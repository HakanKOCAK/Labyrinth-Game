#include "enemy.hpp"
#include "textureHolder.hpp"
#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

void Enemy::spawn(float startX, float startY){
    
    m_Sprite = Sprite(TextureHolder::GetTexture("../Resources/graphics/enemy.png"));
    
    m_Speed = WALK_SPEED;
    m_Health = HEALTH;
    
    m_Sprite.setOrigin(60.0f, 46.5f);
    m_Position.x = startX;
    m_Position.y = startY;
    m_Sprite.setPosition(m_Position);
    
    
    m_Rect.setSize(Vector2f(50.0f, 50.0f));
    m_Rect.setPosition(startX, startY);
    m_Rect.setFillColor(Color::White);
    m_Rect.setOrigin(25.0f, 25.0f);
   
}

bool Enemy::hit(){
    m_Health-= 35;
    
    if (m_Health < 0){
        // dead
        m_Sprite.setTexture(TextureHolder::GetTexture("../Resources/graphics/bloodsplat.png"));
        return true;
    }
    
    // injured but not dead yet
    return false;
}

void Enemy::setSpeed(){
    if(m_IsFocused){
        m_Speed = SPEED;
    } else {
        m_Speed = WALK_SPEED;
    }
}

void Enemy::runToThePlayer(bool isFocused){
    m_IsFocused = isFocused;
}

void Enemy::update(){
    m_Sprite.setPosition(m_Position);
    m_Rect.setPosition(m_Position.x, m_Position.y);
    setSpeed();
}
void Enemy::updateMovement(float elapsedTime){
    if(m_Direction == 1){//Up
        if(m_CanMoveUp){
            m_Position.y -= m_Speed * elapsedTime;
            m_Rect.move(0, -m_Speed * elapsedTime);
            m_GenerateRandom = true;
            m_Direction = 1;
            m_CanMoveUp = true;
            m_CanMoveDown = true;
            m_CanMoveLeft = true;
            m_CanMoveRight = true;
            m_Sprite.setRotation(270.0f);
            m_Rect.setRotation(270.0f);
        }
    } else if(m_Direction == 2){ //Down
        if(m_CanMoveDown){
            m_Position.y += m_Speed * elapsedTime;
            m_Rect.move(0, m_Speed*elapsedTime);
            m_GenerateRandom = true;
            m_Direction = 2;
            m_CanMoveUp = true;
            m_CanMoveDown = true;
            m_CanMoveLeft = true;
            m_CanMoveRight = true;
            m_Sprite.setRotation(90.0f);
            m_Rect.setRotation(90.0f);
        }
    } else if(m_Direction == 3){ //Left
        if(m_CanMoveLeft){
            m_Position.x -= m_Speed * elapsedTime;
            m_Rect.move(-m_Speed*elapsedTime, 0);
            m_GenerateRandom = true;
            m_Direction = 3;
            m_CanMoveUp = true;
            m_CanMoveDown = true;
            m_CanMoveLeft = true;
            m_CanMoveRight = true;
            m_Sprite.setRotation(180.0f);
            m_Rect.setRotation(180.0f);
        }
        
    } else if(m_Direction == 4){//Right
        if(m_CanMoveRight){
            m_Position.x += m_Speed * elapsedTime;
            m_Rect.move(m_Speed*elapsedTime, 0);
            m_GenerateRandom = true;
            m_Direction = 4;
            m_CanMoveUp = true;
            m_CanMoveDown = true;
            m_CanMoveLeft = true;
            m_CanMoveRight = true;
            m_Sprite.setRotation(0.0f);
            m_Rect.setRotation(0.0f);
        }
    }
        
    waitFor++;
    if(m_IsFocused){
        if(waitFor >= 200 && m_GenerateRandom){
            m_Direction = rand() % 4 + 1;
            waitFor = 0;
        }
    } else {
        if(waitFor >= 500 && m_GenerateRandom){
            m_Direction = rand() % 4 + 1;
            waitFor = 0;
        }
    }
    
}
