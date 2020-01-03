#include "player.hpp"
#include "textureHolder.hpp"
#include <iostream>

Player::Player(){
    m_Speed = SPEED;
    m_Health = HEALTH;
    
    // Associate a texture with the sprite
    m_Sprite = Sprite(TextureHolder::GetTexture("../Resources/graphics/player.png"));
    // Set the origin of the sprite to the centre,
    // for smooth rotation
    m_Sprite.setOrigin(60.0f, 39.5f);
    
    m_Rect.setSize(Vector2f(50.0f, 50.0f));
    m_Rect.setPosition(300, 2500);
    m_Rect.setFillColor(Color::Transparent);
    m_Rect.setOrigin(25.0f, 25.0f);
}

void Player::spawn(Vector2f resolution, int tileSize) {
    // Place the player to the left bottom corner of the arena
    m_Position.x = 300;
    m_Position.y = 2500;
    
    // Remember how big the tiles are in this arena
    m_TileSize = tileSize;
    
    // Store the resolution for future use
    m_Resolution.x = resolution.x;
    m_Resolution.y = resolution.y;
}

void Player::resetPlayerStats(){
    m_Speed = SPEED;
    m_Health = HEALTH;
}

Time Player::getLastHitTime(){
    return m_LastHit;
}

bool Player::hit(Time timeHit){
    // 2 tenths of second
    if (timeHit.asMilliseconds() - m_LastHit.asMilliseconds() > 200){
        m_LastHit = timeHit;
        m_Health -= 10;
        return true;
    } else{
        return false;
    }
    
}

FloatRect Player::getPosition(){
    return m_Rect.getGlobalBounds();
}

Vector2f Player::getCenter(){
    return m_Position;
}

float Player::getRotation(){
    return m_Sprite.getRotation();
}

Sprite Player::getSprite(){
    return m_Sprite;
}

int Player::getHealth(){
    return m_Health;
}

void Player::update(Vector2i mousePosition){
    m_Sprite.setPosition(m_Position);
    m_Rect.setPosition(m_Position.x, m_Position.y);
    
    // Calculate the angle the player is facing
    //float angle = (atan2(mousePosition.y - m_Resolution.y / 2,mousePosition.x - m_Resolution.x / 2) * 180) / 3.141;
    
    // if using iMac Retina comment out above and uncomment below
    float angle = (atan2((mousePosition.y-m_Resolution.y) - m_Resolution.y / 2, mousePosition.x - m_Resolution.x / 2) * 180) / 3.141;
    
    m_Sprite.setRotation(angle);
    m_Rect.setRotation(angle);
}

bool Player::doHaveAKey(){
    return m_HasKey;
}

void Player::setKey(bool haveAKey){
    m_HasKey = haveAKey;
}

void Player::increaseHealthLevel(int amount)
{
    m_Health += amount;
    
    // But not beyond the maximum
    if (m_Health > HEALTH)
    {
        m_Health = HEALTH;
    }
}

void Player::updateMovement(float elapsedTime){
    
    if(Keyboard::isKeyPressed(Keyboard::W)){
        if(m_CanMoveUp){
            m_Position.y -= m_Speed * elapsedTime;
            m_Rect.move(0, -m_Speed*elapsedTime);
            m_Direction = 1;
            m_CanMoveUp = true;
            m_CanMoveDown = true;
            m_CanMoveLeft = true;
            m_CanMoveRight = true;
            //m_Sprite.setRotation(270.0f);
        }
    }else if(Keyboard::isKeyPressed(Keyboard::S)){
        if(m_CanMoveDown){
            m_Position.y += m_Speed * elapsedTime;
            m_Rect.move(0, m_Speed*elapsedTime);
            m_Direction = 2;
            m_CanMoveUp = true;
            m_CanMoveDown = true;
            m_CanMoveLeft = true;
            m_CanMoveRight = true;
            //m_Sprite.setRotation(90.0f);
        }
    }else if(Keyboard::isKeyPressed(Keyboard::A)){
        if(m_CanMoveLeft){
            m_Position.x -= m_Speed * elapsedTime;
            m_Rect.move(-m_Speed*elapsedTime, 0);
            m_Direction = 3;
            m_CanMoveUp = true;
            m_CanMoveDown = true;
            m_CanMoveLeft = true;
            m_CanMoveRight = true;
            
            //m_Sprite.setRotation(180.0f);
        }
    }else if(Keyboard::isKeyPressed(Keyboard::D)){
        if(m_CanMoveRight){
            m_Position.x += m_Speed * elapsedTime;
            m_Rect.move(m_Speed*elapsedTime, 0);
            m_Direction = 4;
            m_CanMoveUp = true;
            m_CanMoveDown = true;
            m_CanMoveLeft = true;
            m_CanMoveRight = true;
            
           // m_Sprite.setRotation(0.0f);
        }
    } else {
    }
}
