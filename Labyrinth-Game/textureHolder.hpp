//
//  textureHolder.hpp
//  Labyrinth-Game
//
//  Created by Hakan KOCAK on 2.01.2020.
//  Copyright © 2020 Hakan KOCAK. All rights reserved.
//

#ifndef textureHolder_hpp
#define textureHolder_hpp

#include <SFML/Graphics.hpp>
#include <map>

using namespace sf;

class TextureHolder
{
public:
    TextureHolder();
    static Texture& GetTexture(std::string const& filename);
    
private:
    // A map holding pairs of String and Texture
    std::map<std::string, sf::Texture> m_Textures;
    
    // A pointer to the singleton
    static TextureHolder* m_s_Instance;
};
#endif /* textureHolder_hpp */
