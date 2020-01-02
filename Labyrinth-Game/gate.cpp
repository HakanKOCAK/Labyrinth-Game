//
//  gate.cpp
//  Labyrinth-Game
//
//  Created by Hakan KOCAK on 2.01.2020.
//  Copyright © 2020 Hakan KOCAK. All rights reserved.
//

#include "gate.hpp"
#include "textureHolder.hpp"

Gate::Gate(){
    
    // Associate a texture with the sprite
    m_Sprite = Sprite(TextureHolder::GetTexture("../Resources/graphics/gate.png"));
    
    m_Sprite.setScale(100.0f / m_Sprite.getLocalBounds().width, 100.0f / m_Sprite.getLocalBounds().height);
    m_Sprite.setOrigin(25,25);
}

Sprite Gate::getSprite()
{
    return m_Sprite;
}

void Gate::setPosition(int x, int y){
    m_Sprite.setPosition(x, y);
}

void Gate::setGateNumber(int num){
    m_gateNumber = num;
}

int Gate::getGateNumber(){
    return m_gateNumber;
}

void Gate::openTheGate(){
    m_isOpen = true;
}

bool Gate::isGateOpen(){
    return m_isOpen;
}
