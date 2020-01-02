//
//  player.cpp
//  Labyrinth-Game
//
//  Created by Hakan KOCAK on 2.01.2020.
//  Copyright © 2020 Hakan KOCAK. All rights reserved.
//

#include "player.hpp"
#include "textureHolder.hpp"
#include <iostream>

Player::Player(){
    m_Speed = SPEED;
    m_Health = HEALTH;
    
    // Associate a texture with the sprite
    m_Sprite = Sprite(TextureHolder::GetTexture("../Resources/graphics/player.png"));
    
    m_Sprite.setScale(100.0f / m_Sprite.getLocalBounds().width, 100.0f / m_Sprite.getLocalBounds().height);
    // Set the origin of the sprite to the centre,
    // for smooth rotation
    m_Sprite.setOrigin(25, 25);
}

void Player::spawn(IntRect arena, Vector2f resolution, int tileSize) {
    // Place the player in the middle of the arena
    std::cout << "Width: " << arena.width << " Height: " << arena.height;
    m_Position.x = -1 * arena.width;
    m_Position.y = arena.height;
    
    // Copy the details of the arena to the player's m_Arena
    m_Arena.left = arena.left;
    m_Arena.width = arena.width;
    m_Arena.top = arena.top;
    m_Arena.height = arena.height;
    
    // Remember how big the tiles are in this arena
    m_TileSize = tileSize;
    
    // Store the resolution for future use
    m_Resolution.x = resolution.x;
    m_Resolution.y = resolution.y;
}

void Player::resetPlayerStats()
{
    m_Speed = SPEED;
    m_Health = HEALTH;
}

Time Player::getLastHitTime()
{
    return m_LastHit;
}

bool Player::hit(Time timeHit)
{
    if (timeHit.asMilliseconds() - m_LastHit.asMilliseconds() > 200)// 2 tenths of second
    {
        m_LastHit = timeHit;
        m_Health -= 10;
        return true;
    }
    else
    {
        return false;
    }
    
}

FloatRect Player::getPosition()
{
    return m_Sprite.getGlobalBounds();
}

Vector2f Player::getCenter()
{
    return m_Position;
}

float Player::getRotation()
{
    return m_Sprite.getRotation();
}

Sprite Player::getSprite()
{
    return m_Sprite;
}

int Player::getHealth()
{
    return m_Health;
}

void Player::moveLeft()
{
    m_LeftPressed = true;
}

void Player::moveRight()
{
    m_RightPressed = true;
}

void Player::moveUp()
{
    m_UpPressed = true;
}

void Player::moveDown()
{
    m_DownPressed = true;
}

void Player::stopLeft()
{
    m_LeftPressed = false;
}

void Player::stopRight()
{
    m_RightPressed = false;
}

void Player::stopUp()
{
    m_UpPressed = false;
}

void Player::stopDown()
{
    m_DownPressed = false;
}

void Player::update(float elapsedTime, Vector2i mousePosition)
{
    
    if (m_UpPressed)
    {
        m_Position.y -= m_Speed * elapsedTime;
    }
    
    if (m_DownPressed)
    {
        m_Position.y += m_Speed * elapsedTime;
    }
    
    if (m_RightPressed)
    {
        m_Position.x += m_Speed * elapsedTime;
    }
    
    if (m_LeftPressed)
    {
        m_Position.x -= m_Speed * elapsedTime;
    }
    
    m_Sprite.setPosition(m_Position);
    
    // Keep the player in the arena
    if (m_Position.x > m_Arena.width - m_TileSize)
    {
        m_Position.x = m_Arena.width - m_TileSize;
    }
    
    if (m_Position.x < m_Arena.left + m_TileSize)
    {
        m_Position.x = m_Arena.left + m_TileSize;
    }
    
    if (m_Position.y > m_Arena.height - m_TileSize)
    {
        m_Position.y = m_Arena.height - m_TileSize;
    }
    
    if (m_Position.y < m_Arena.top + m_TileSize)
    {
        m_Position.y = m_Arena.top + m_TileSize;
    }
    
    // Calculate the angle the player is facing
    //float angle = (atan2(mousePosition.y - m_Resolution.y / 2,mousePosition.x - m_Resolution.x / 2) * 180) / 3.141;
    
    // if using iMac Retina comment out above and uncomment below
    float angle = (atan2((mousePosition.y-m_Resolution.y) - m_Resolution.y / 2, mousePosition.x - m_Resolution.x / 2) * 180) / 3.141;
    
    
    m_Sprite.setRotation(angle);
    
}

void Player::increaseHealthLevel(int amount)
{
    m_Health += amount;
    
    // But not beyond the maximum
    if (m_Health > HEALTH){
        m_Health = HEALTH;
    }
}