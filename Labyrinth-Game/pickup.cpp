//
//  pickup.cpp
//  Zombie Arena
//

#include "pickup.hpp"
#include "textureHolder.hpp"

Pickup::Pickup(int type)
{
    // Store the type of this pickup
    m_Type = type;
    
    m_IsInTheArena= true;
    
    // Associate the texture with the sprite
    if (m_Type == 1){
        m_Sprite = Sprite(TextureHolder::GetTexture("../Resources/graphics/health_kit.png"));
        // How much is pickup worth?
        m_Value = HEALTH_VALUE;
        
    }else if (m_Type == 2){
        m_Sprite = Sprite(TextureHolder::GetTexture("../Resources/graphics/ammo_crate.png"));
        
        // How much is pickup worth?
        m_Value = AMMO_VALUE;
    } else {
        m_Sprite = Sprite(TextureHolder::GetTexture("../Resources/graphics/key.png"));
        m_Value = KEY_VALUE;
    }
    
    m_Sprite.setOrigin(25, 25);
}

FloatRect Pickup::getPosition()
{
    return m_Sprite.getGlobalBounds();
}

Sprite Pickup::getSprite()
{
    return m_Sprite;
}

bool Pickup::isInTheArena()
{
    return m_IsInTheArena;
}

int Pickup::gotIt()
{
    m_IsInTheArena = false;
    return m_Value;
}

int Pickup::returnType(){
    return m_Type;
}

void Pickup::setPosition(int x, int y){
    m_Sprite.setPosition(x, y);
}
