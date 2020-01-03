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

Vector2f PlayerEntity::getCenter(){
    return m_Position;
}
