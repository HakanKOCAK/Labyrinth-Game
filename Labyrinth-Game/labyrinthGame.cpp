#include <SFML/Graphics.hpp>
#include <iostream>
#include "player.hpp"
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
    
    //Walls
    std::vector<Wall> wallArray;
    std::vector<Wall>::const_iterator wallIterator;
    
    //Gates
    std::vector<Gate> gateArray;
    std::vector<Gate>::const_iterator gateIterator;
    
    // Hide the mouse pointer and replace it with crosshair
    window.setMouseCursorVisible(false);
    Sprite spriteCrosshair;
    Texture textureCrosshair = TextureHolder::GetTexture("../Resources/graphics/crosshair.png");
    spriteCrosshair.setTexture(textureCrosshair);
    spriteCrosshair.setScale(64.0f / spriteCrosshair.getLocalBounds().width,
                             64.0f / spriteCrosshair.getLocalBounds().height);
    spriteCrosshair.setOrigin(25, 25);
    
    // Create a view for the HUD
    View hudView(FloatRect(0, 0, resolution.x, resolution.y));
    
    
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
    
    // Game Over
    Text gameOverText;
    gameOverText.setFont(font);
    gameOverText.setCharacterSize(125);
    gameOverText.setFillColor(sf::Color::White);
    gameOverText.setString("Press Enter to play");
    
    FloatRect gameOverRect = gameOverText.getLocalBounds();
    gameOverText.setOrigin(gameOverRect.left+gameOverRect.width/2.0f, gameOverRect.top+gameOverRect.height/2.0f);
    gameOverText.setPosition(resolution.x/2, resolution.y/2);
    
    
    // Health bar
    RectangleShape healthBar;
    healthBar.setFillColor(Color::Red);
    healthBar.setPosition(resolution.x*0.33, resolution.y-200);
    
    
    // When did we last update the HUD?
    int framesSinceLastHUDUpdate = 0;
    
    // How often (in frames) should we update the HUD
    int fpsMeasurementFrameInterval = 1000;
    
    
    // The main game loop
    while (window.isOpen()) {
        /*
         ************
         Handle input
         ************
         */
        
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
                
                    arena.width = 2200;
                    arena.height = 2700;
                    arena.left = 0;
                    arena.top = 0;
                    
                    // Pass the vertex array by reference
                    // to the createBackground function
                    int tileSize = createBackground(background, arena);
                    createWallsAndGates(wallArray, gateArray);
    
                    // Reset the player's stats
                    player.resetPlayerStats();
                    
                    // Spawn the player to the left bottom corner of the arena
                    player.spawn(arena, resolution, tileSize);
                    state = State::PLAYING;
                    
                    // Reset the clock so there isn't a frame jump
                    clock.restart();
                }
                
                
            } //End if (event.type == Event::KeyPressed)
        }// End event polling
        
        
        // Handle the player quitting
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }
        
        // Handle controls while playing
        if (state == State::PLAYING)
        {
            // Handle the pressing and releasing of the WASD keys
            if (Keyboard::isKeyPressed(Keyboard::W)){
                player.moveUp();
            }  else {
                player.stopUp();
            }
            
            if (Keyboard::isKeyPressed(Keyboard::S)){
                player.moveDown();
            } else {
                player.stopDown();
            }
            
            if (Keyboard::isKeyPressed(Keyboard::A)) {
                player.moveLeft();
            } else{
                player.stopLeft();
            }
            
            if (Keyboard::isKeyPressed(Keyboard::D)){
                player.moveRight();
            } else  {
                player.stopRight();
            }
            
        }// End WASD while playing
        
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
            player.update(dtAsSeconds, Mouse::getPosition());
            
            // Make a note of the players new position
            Vector2f playerPosition(player.getCenter());
            
            // Make the view centre around the player
            mainView.setCenter(player.getCenter());
            
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
                window.draw(gateArray[counter].getSprite());
                counter++;
            }
          
            
            // Draw the player
            window.draw(player.getSprite());
            
            //Draw the crosshair
            window.draw(spriteCrosshair);
            
            // Switch to the HUD view
            window.setView(hudView);
            
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
