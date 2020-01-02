#include "gate.hpp"
#include "textureHolder.hpp"

Gate::Gate(){
    
    // Associate a texture with the sprite
    m_Sprite = Sprite(TextureHolder::GetTexture("../Resources/graphics/gate.png"));
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
