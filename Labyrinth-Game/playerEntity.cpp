//
//  playerEntity.cpp
//  Labyrinth-Game
//
//  Created by Hakan KOCAK on 3.01.2020.
//  Copyright © 2020 Hakan KOCAK. All rights reserved.
//

#include "playerEntity.hpp"

FloatRect PlayerEntity::getPosition(){
    return m_Rect.getGlobalBounds();
}

Sprite PlayerEntity::getSprite(){
    return m_Sprite;
}

int PlayerEntity::getHealth(){
    return m_Health;
}
