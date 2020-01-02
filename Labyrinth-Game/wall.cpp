//
//  wall.cpp
//  Labyrinth-Game
//
//  Created by Hakan KOCAK on 2.01.2020.
//  Copyright © 2020 Hakan KOCAK. All rights reserved.
//

#include "wall.hpp"
#include "textureHolder.hpp"

Wall::Wall(){
    
    // Associate a texture with the sprite
    m_Sprite = Sprite(TextureHolder::GetTexture("../Resources/graphics/wall.png"));
    
    m_Sprite.setScale(100.0f / m_Sprite.getLocalBounds().width, 100.0f / m_Sprite.getLocalBounds().height);
    m_Sprite.setOrigin(25,25);
}

Sprite Wall::getSprite()
{
    return m_Sprite;
}

void Wall::setPosition(int x, int y){
    m_Sprite.setPosition(x, y);
}
