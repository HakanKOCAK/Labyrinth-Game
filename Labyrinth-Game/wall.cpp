#include "wall.hpp"
#include "textureHolder.hpp"

Wall::Wall(){
    // Associate a texture with the sprite
    m_Sprite = Sprite(TextureHolder::GetTexture("../Resources/graphics/wall.png"));
    m_Sprite.setOrigin(50.0f, 50.0f);
}
