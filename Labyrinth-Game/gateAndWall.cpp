#include "gateAndWall.hpp"

FloatRect GateAndWall::getPosition(){
    return m_Sprite.getGlobalBounds();
}

Sprite GateAndWall::getSprite(){
    return m_Sprite;
}

void GateAndWall::setPosition(int x, int y){
    m_Sprite.setPosition(x, y);
}
