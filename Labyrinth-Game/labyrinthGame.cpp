#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <fstream>
#include "player.hpp"
#include "bullet.hpp"
#include "textureHolder.hpp"
#include "labyrinthGame.hpp"

using namespace sf;

int main(int argc, const char * argv[]) {
    
    // Here is the instance of TextureHolder
    TextureHolder holder;
    
    // The game will always be in one of three states
    enum class State { PAUSED, GAME_OVER, PLAYING };
    
    // Start with the GAME_OVER state
    State state = State::GAME_OVER;
    
    // Get the screen resolution and create an SFML window
    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;
    
    RenderWindow window(VideoMode(resolution.x, resolution.y),
                        "Labyrinth Game", Style::Fullscreen);
    
    // Create a an SFML View for the main action
    View mainView(sf::FloatRect(0, 0, resolution.x, resolution.y));
    
    // Here is our clock for timing everything
    Clock clock;
    // How long has the PLAYING state been active
    Time gameTimeTotal;
    
    // Where is the mouse in relation to world coordinates
    Vector2f mouseWorldPosition;
    // Where is the mouse in relation to screen coordinates
    Vector2i mouseScreenPosition;
    
    // Create an instance of the Player class
    Player player;
    
    // The boundaries of the arena
    IntRect arena;
    
    // Create the background
    VertexArray background;
    // Load the texture for our background vertex array
    Texture textureBackground = TextureHolder::GetTexture("../Resources/graphics/floor_tile.png");
    
    int numOfEnemies = 22;
    int numOfAliveEnemies = 22;
    Enemy *enemies = nullptr;
    
    //Walls
    std::vector<Wall> wallArray;
    std::vector<Wall>::const_iterator wallIterator;
    
    //Gates
    std::vector<Gate> gateArray;
    std::vector<Gate>::const_iterator gateIterator;
    
    //Pickups
    std::vector<Pickup> pickupArray;
    std::vector<Pickup>::const_iterator pickupIterator;
    
    // Hide the mouse pointer and replace it with crosshair
    window.setMouseCursorVisible(false);
    Sprite spriteCrosshair;
    Texture textureCrosshair = TextureHolder::GetTexture("../Resources/graphics/crosshair.png");
    spriteCrosshair.setTexture(textureCrosshair);
    spriteCrosshair.setScale(64.0f / spriteCrosshair.getLocalBounds().width,
                             64.0f / spriteCrosshair.getLocalBounds().height);
    spriteCrosshair.setOrigin(25, 25);
    
    Bullet bullets[100];
    int currentBullet = 0;
    int bulletsSpare = 10;
    int bulletsInClip = 10;
    float fireRate = 1;
    // When was the fire button last pressed?
    Time lastPressed;
    
    // Create a view for the HUD
    View hudView(FloatRect(0, 0, resolution.x, resolution.y));
    
    
    // Create a sprite for the ammo icon
    Sprite spriteAmmoIcon;
    Texture textureAmmoIcon = TextureHolder::GetTexture("../Resources/graphics/bullet.png");
    spriteAmmoIcon.setTexture(textureAmmoIcon);
    spriteAmmoIcon.setScale(80.0f / spriteAmmoIcon.getLocalBounds().width, 80.0f / spriteAmmoIcon.getLocalBounds().height);
    spriteAmmoIcon.setPosition(70, resolution.y-200);
    
    // Load the font
    Font font;
    font.loadFromFile("../Resources/fonts/jockey_full_of_bourbon.ttf");
    
    // Paused
    Text pausedText;
    pausedText.setFont(font);
    pausedText.setCharacterSize(155);
    pausedText.setFillColor(Color::White);
    pausedText.setString("Press Enter \nto continue");
    
    FloatRect pausedRect = pausedText.getLocalBounds();
    pausedText.setOrigin(pausedRect.left+pausedRect.width/2.0f, pausedRect.top+pausedRect.height/2.0f);
    pausedText.setPosition(resolution.x/2, resolution.y/2);
    
    // About the game
    int score = 0;
    // Score
    Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(55);
    scoreText.setFillColor(Color::White);
    scoreText.setPosition(20, 0);
    
    // Zombies remaining
    Text enemiesRemainingText;
    enemiesRemainingText.setFont(font);
    enemiesRemainingText.setCharacterSize(55);
    enemiesRemainingText.setFillColor(Color::White);
    enemiesRemainingText.setPosition(resolution.x-400, resolution.y-200);
    enemiesRemainingText.setString("Enemies: 22");
    
    // Game Over
    Text gameOverText;
    gameOverText.setFont(font);
    gameOverText.setCharacterSize(125);
    gameOverText.setFillColor(sf::Color::White);
    gameOverText.setString("Press Enter to play");
    
    FloatRect gameOverRect = gameOverText.getLocalBounds();
    gameOverText.setOrigin(gameOverRect.left+gameOverRect.width/2.0f, gameOverRect.top+gameOverRect.height/2.0f);
    gameOverText.setPosition(resolution.x/2, resolution.y/2);
    
    // Ammo
    Text ammoText;
    ammoText.setFont(font);
    ammoText.setCharacterSize(55);
    ammoText.setFillColor(Color::White);
    ammoText.setPosition(200, resolution.y-200);
    
    // Health bar
    RectangleShape healthBar;
    healthBar.setFillColor(Color::Red);
    healthBar.setPosition(resolution.x*0.33, resolution.y-200);
    
    
    // Prepare the shoot sound
    SoundBuffer shootBuffer;
    shootBuffer.loadFromFile("../Resources/sounds/shoot.wav");
    Sound shoot;
    shoot.setBuffer(shootBuffer);
    
    // Prepare the reload sound
    SoundBuffer reloadBuffer;
    reloadBuffer.loadFromFile("../Resources/sounds/reload.wav");
    Sound reload;
    reload.setBuffer(reloadBuffer);
    
    // Prepare the pain sound
    SoundBuffer hitByBullet;
    hitByBullet.loadFromFile("../Resources/sounds/pain.wav");
    Sound pain;
    pain.setBuffer(hitByBullet);
    
    // Prepare the knife hit sound
    SoundBuffer hitByKnife;
    hitByKnife.loadFromFile("../Resources/sounds/knife_hit.wav");
    Sound knifeHit;
    knifeHit.setBuffer(hitByKnife);
    
    // Prepare no ammo sound
    SoundBuffer noAmmoBuffer;
    noAmmoBuffer.loadFromFile("../Resources/sounds/no_ammo.wav");
    Sound noAmmo;
    noAmmo.setBuffer(noAmmoBuffer);
    
    
    // When did we last update the HUD?
    int framesSinceLastHUDUpdate = 0;
    
    // How often (in frames) should we update the HUD
    int fpsMeasurementFrameInterval = 200;
    
    // The main game loop
    while (window.isOpen()) {
        // Handle events
        Event event;
        while (window.pollEvent(event)){
            if (event.type == Event::KeyPressed){
                if (event.key.code == Keyboard::Return && state == State::PLAYING) {
                    state = State::PAUSED;
                } else if (event.key.code == Keyboard::Return && state == State::PAUSED){
                    state = State::PLAYING;
                    // Reset the clock so there isn't a frame jump
                    clock.restart();
                } else if (event.key.code == Keyboard::Return && state == State::GAME_OVER){
                
                    state = State::PLAYING;
                    arena.width = 2200;
                    arena.height = 2700;
                    arena.left = 0;
                    arena.top = 0;
                    
                    // Pass the vertex array by reference
                    // to the createBackground function
                    int tileSize = createBackground(background, arena);
                    createWallsAndGates(wallArray, gateArray);
                    createPickups(pickupArray);
    
                    // Prepare the gun and ammo for next game
                    currentBullet = 0;
                    bulletsSpare = 10;
                    bulletsInClip = 10;
                    fireRate = 1;
                    score = 0;
                    
                    // Reset the player's stats
                    player.resetPlayerStats();
                    delete[] enemies;
                    enemies = createEnemies(numOfEnemies);
                    numOfAliveEnemies = numOfEnemies;
                    
                    // Spawn the player to the left bottom corner of the arena
                    player.spawn(resolution);
                    
                    // Reset the clock so there isn't a frame jump
                    clock.restart();
                }
                
                if (state == State::PLAYING)
                {
                    // Reloading
                    if (event.key.code == Keyboard::R) {
                        if (bulletsSpare > 0 && bulletsInClip != 10){
                            if (bulletsSpare + bulletsInClip >= 10){
                                int val = bulletsInClip;
                                bulletsInClip += 10 - bulletsInClip;
                                bulletsSpare -= 10 - val;
                            } else {
                                bulletsInClip += bulletsSpare;
                                bulletsSpare = 0;
                            }
                            reload.play();
                        } else{
                            noAmmo.play();
                        }
                    }
                }
                
                
            } //End if (event.type == Event::KeyPressed)
        }// End event polling
        
        
        // Handle the player quitting
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }
        
        if (state == State::PLAYING)
        {
            
            int counter = 0;
            
            for(int i=0; i<numOfEnemies; i++){
                counter = 0;
                for(wallIterator = wallArray.begin(); wallIterator != wallArray.end(); wallIterator++){
                    if (enemies[i].getPosition().intersects(wallArray[counter].getPosition())){
                        //Up
                        if (enemies[i].m_Direction == 1){
                            enemies[i].m_CanMoveUp = false;
                            enemies[i].m_Rect.move(0, 1);
                            enemies[i].m_Direction = 2;
                            enemies[i].m_GenerateRandom = false;
                        }
                        //Down
                        else if (enemies[i].m_Direction == 2){
                            enemies[i].m_CanMoveDown = false;
                            enemies[i].m_Rect.move(0, -1);
                            enemies[i].m_Direction = 1;
                            enemies[i].m_GenerateRandom = false;
                        }
                        //Left
                        else if (enemies[i].m_Direction == 3){
                            enemies[i].m_CanMoveLeft = false;
                            enemies[i].m_Rect.move(1, 0);
                            enemies[i].m_Direction = 4;
                            enemies[i].m_GenerateRandom = false;
                        }
                        //Right
                        else if (enemies[i].m_Direction == 4){
                            enemies[i].m_CanMoveRight = false;
                            enemies[i].m_Rect.move(-1, 0);
                            enemies[i].m_Direction = 3;
                            enemies[i].m_GenerateRandom = false;
                        }
                    }
                    counter ++;
                }
            }
            
            
            counter = 0;
            for(wallIterator = wallArray.begin(); wallIterator != wallArray.end(); wallIterator++){
                if (player.getPosition().intersects(wallArray[counter].getPosition())){
                    //Up
                    if (player.m_Direction == 1){
                        player.m_CanMoveUp = false;
                        player.m_Rect.move(0, 1);
                    }
                    //Down
                    else if (player.m_Direction == 2){
                        player.m_CanMoveDown = false;
                        player.m_Rect.move(0, -1);
                    }
                    //Left
                    else if (player.m_Direction == 3){
                        player.m_CanMoveLeft = false;
                        player.m_Rect.move(1, 0);
                    }
                    //Right
                    else if (player.m_Direction == 4){
                        player.m_CanMoveRight = false;
                        player.m_Rect.move(-1, 0);
                    }
                }
                counter ++;
            }
            
            counter = 0;
            for(gateIterator = gateArray.begin(); gateIterator != gateArray.end(); gateIterator++){
                if (player.getPosition().intersects(gateArray[counter].getPosition()) && !gateArray[counter].isGateOpen()){
                    //Up
                    if (player.m_Direction == 1){
                        player.m_CanMoveUp = false;
                    }
                    //Down
                    else if (player.m_Direction == 2){
                        player.m_CanMoveDown = false;
                    }
                    //Left
                    else if (player.m_Direction == 3){
                        player.m_CanMoveLeft = false;
                    }
                    //Right
                    else if (player.m_Direction == 4){
                        player.m_CanMoveRight = false;
                    }
                    
                    if(player.doHaveAKey() && Keyboard::isKeyPressed(Keyboard::Key::F)){
                        gateArray[counter].openTheGate();
                        
                        player.setKey(false);
                        
                        if(gateArray[counter].getGateNumber() == 3){
                            state = State::GAME_OVER;
                        }
                        
                        if(!player.m_CanMoveUp){
                            player.m_CanMoveUp = true;
                        }
                        if(!player.m_CanMoveDown){
                            player.m_CanMoveDown = true;
                        }
                        if(!player.m_CanMoveLeft){
                            player.m_CanMoveLeft = true;
                        }
                        if(!player.m_CanMoveRight){
                            player.m_CanMoveRight = true;
                        }
                    }
                }
                counter ++;
            }
            
            // Fire a bullet
            if (Mouse::isButtonPressed(Mouse::Left)) {
                
                if (gameTimeTotal.asMilliseconds()
                    - lastPressed.asMilliseconds()
                    > 1000 / fireRate && bulletsInClip > 0) {
                    
                    // Pass the centre of the player and the centre of the cross-hair
                    // to the shoot function
                    //bullets[currentBullet].shoot(
                    //                             player.getCenter().x, player.getCenter().y,
                    //                             mouseWorldPosition.x, mouseWorldPosition.y);
                    
                    // if working on iMac Retina comment out above and uncomment below
                    bullets[currentBullet].shoot(player.getCenter().x, player.getCenter().y,mouseWorldPosition.x, mouseWorldPosition.y - resolution.y);
                    
                    
                    currentBullet++;
                    if (currentBullet > 99) {
                        currentBullet = 0;
                    }
                    lastPressed = gameTimeTotal;
                    
                    shoot.play();
                    
                    bulletsInClip--;
                } else {
                    noAmmo.play();
                }
                
            }// End fire a bullet
        }
        
        /*
         ****************
         UPDATE THE FRAME
         ****************
         */
        
        if (state == State::PLAYING)
        {
            
            // Update the delta time
            Time dt = clock.restart();
            // Update the total game time
            gameTimeTotal += dt;
            // Make a decimal fraction of 1 from the delta time
            float dtAsSeconds = dt.asSeconds();
            
            // Where is the mouse pointer
            mouseScreenPosition = Mouse::getPosition(window);
            
            // Convert mouse position to world coordinates of mainView
            mouseWorldPosition = window.mapPixelToCoords(Mouse::getPosition(), mainView);
            
            // Set the crosshair to the mouse world location
            //spriteCrosshair.setPosition(mouseWorldPosition);
            
            // if using iMac Retina comment out above and uncomment below
            spriteCrosshair.setPosition(mouseWorldPosition.x, mouseWorldPosition.y - resolution.y);
            
            
            // Update the player
            player.update(Mouse::getPosition());
            player.updateMovement(dtAsSeconds);
            
            // Make a note of the players new position
            Vector2f playerPosition(player.getCenter());
            
            // Make the view centre around the player
            mainView.setCenter(player.getCenter());
            
            //Update the enemies
            for (int i = 0; i < numOfEnemies; i++) {
                if (enemies[i].getHealth() > 0) {
                    enemies[i].update();
                    enemies[i].updateMovement(dt.asSeconds());
                }
            }
            
            // Update any bullets that are in-flight
            for (int i = 0; i < 100; i++) {
                if (bullets[i].isInFlight()) {
                    bullets[i].update(dtAsSeconds);
                }
            }
            
            // Collision detection
            // Have any enemies been shot?
            for (int i = 0; i < 100; i++)
            {
                for (int j = 0; j < numOfEnemies; j++)
                {
                    if (bullets[i].isInFlight() &&
                        enemies[j].getHealth() > 0)
                    {
                        if (bullets[i].getPosition().intersects
                            (enemies[j].getPosition()))
                        {
                            // Stop the bullet
                            bullets[i].stop();
                            
                            // Register the hit and see if it was a kill
                            if (enemies[j].hit()) {
                                pain.play();
                                // Not just a hit but a kill too
                                score += 10;
                                
                                numOfAliveEnemies--;
                                
                                // When all the enemies are dead (again)
                                if (numOfAliveEnemies == 0) {
                                    state = State::GAME_OVER;
                                }
                            }
                            
                        }
                    }
                    
                }
            }// End enemy being shot
            
            // Have any enemies touched the player
            for (int i = 0; i < numOfEnemies; i++)
            {
                if (player.getPosition().intersects(enemies[i].getPosition()) && enemies[i].getHealth()>0)
                {
                    
                    if (player.hit(gameTimeTotal))
                    {
                        // More here later
                        knifeHit.play();
                    }
                    
                    if (player.getHealth() <= 0)
                    {
                        state = State::GAME_OVER;
                    }
                    
                }
            }// End player touched
            
            //Check the collision between bullets and walls
            for (int i = 0; i < 100; i++)
            {
                for (int j = 0; j < wallArray.size(); j++)
                {
                    if (bullets[i].isInFlight()){
                        if (bullets[i].getPosition().intersects(wallArray[j].getPosition())){
                             bullets[i].stop();
                        }
                    }
                }
            }
            
            
            int counter = 0;
            for(pickupIterator = pickupArray.begin(); pickupIterator != pickupArray.end(); pickupIterator++){
                if(player.getPosition().intersects(pickupArray[counter].getPosition()) && pickupArray[counter].isInTheArena()){
                    if(pickupArray[counter].returnType() == 1){
                        player.increaseHealthLevel(pickupArray[counter].gotIt());
                    } else if (pickupArray[counter].returnType() == 2){
                        bulletsSpare += pickupArray[counter].gotIt();
                    } else {
                        int num = pickupArray[counter].gotIt();
                        player.setKey(true);
                    }
                }
                counter++;
            }
            
            // size up the health bar
            healthBar.setSize(Vector2f(player.getHealth() * 3, 70));
            
            // Increment the number of frames since the last HUD calculation
            framesSinceLastHUDUpdate++;
            // Calculate FPS every fpsMeasurementFrameInterval frames
            if (framesSinceLastHUDUpdate > fpsMeasurementFrameInterval) {
                
                // Update game HUD text
                std::stringstream ssAmmo;
                std::stringstream ssScore;
                std::stringstream ssEnemiesAlive;
                
                // Update the ammo text
                ssAmmo << bulletsInClip << "/" << bulletsSpare;
                ammoText.setString(ssAmmo.str());
                
                // Update the score text
                ssScore << "Score:" << score;
                scoreText.setString(ssScore.str());
                
                // Update the high score text
                ssEnemiesAlive << "Enemies:" << numOfAliveEnemies;
                enemiesRemainingText.setString(ssEnemiesAlive.str());
                
                framesSinceLastHUDUpdate = 0;
                
            } // End HUD Update
            
        }// End updating the scene
        
       
        /*
         **************
         Draw the scene
         **************
         */
        
        if (state == State::PLAYING)
        {
            window.clear();
            
            // set the mainView to be displayed in the window
            // And draw everything related to it
            window.setView(mainView);
            
            // Draw the background
            window.draw(background, &textureBackground);
            
            //Draw the walls
            int counter = 0;
            for(wallIterator = wallArray.begin(); wallIterator != wallArray.end(); wallIterator++){
                window.draw(wallArray[counter].getSprite());
                counter++;
            }
            
            //Draw the gate
            counter = 0;
            for(gateIterator = gateArray.begin(); gateIterator != gateArray.end(); gateIterator++){
                if(!gateArray[counter].isGateOpen()){
                     window.draw(gateArray[counter].getSprite());
                }
                counter++;
            }
          
            counter = 0;
            for(pickupIterator = pickupArray.begin(); pickupIterator != pickupArray.end(); pickupIterator++){
                if(pickupArray[counter].isInTheArena()){
                    window.draw(pickupArray[counter].getSprite());
                }
                counter++;
            }
            
            // Draw the zombies
            for (int i = 0; i < numOfEnemies; i++) {
                if(enemies[i].getHealth() > 0){
                    window.draw(enemies[i].getSprite());
                }
            }
            
            for (int i = 0; i < 100; i++) {
                if (bullets[i].isInFlight()) {
                    window.draw(bullets[i].getShape());
                }
            }
            
            // Draw the player
            window.draw(player.getSprite());
            
            //Draw the crosshair
            window.draw(spriteCrosshair);
            
            // Switch to the HUD view
            window.setView(hudView);
            
            // Draw all the HUD elements
            window.draw(spriteAmmoIcon);
            window.draw(ammoText);
            window.draw(healthBar);
            window.draw(scoreText);
            window.draw(enemiesRemainingText);
        }
        
        
        if (state == State::PAUSED)
        {
            window.draw(pausedText);
        }
        
        if (state == State::GAME_OVER)
        {
            window.draw(gameOverText);
        }
        
        window.display();
        
    }// End game loop

    return 0;
}
