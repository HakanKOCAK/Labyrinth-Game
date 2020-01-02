#include "wall.hpp"
#include "textureHolder.hpp"

Wall::Wall(){
    
    // Associate a texture with the sprite
    m_Sprite = Sprite(TextureHolder::GetTexture("../Resources/graphics/wall.png"));
}

Sprite Wall::getSprite()
{
    return m_Sprite;
}

FloatRect Wall::getPosition(){
    return m_Sprite.getGlobalBounds();
}

void Wall::setPosition(int x, int y){
    m_Sprite.setPosition(x, y);
}
