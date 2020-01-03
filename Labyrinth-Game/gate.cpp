#include "gate.hpp"
#include "textureHolder.hpp"

Gate::Gate(){
    
    // Associate a texture with the sprite
    m_Sprite = Sprite(TextureHolder::GetTexture("../Resources/graphics/gate.png"));
    m_Sprite.setOrigin(100.0f, 50.0f);
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

void Gate::setRotation(float angle){
    m_Sprite.setRotation(angle);
}

bool Gate::isGateOpen(){
    return m_isOpen;
}
