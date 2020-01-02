//
//  wall.hpp
//  Labyrinth-Game
//
//  Created by Hakan KOCAK on 2.01.2020.
//  Copyright © 2020 Hakan KOCAK. All rights reserved.
//

#ifndef wall_hpp
#define wall_hpp

#include <SFML/Graphics.hpp>

using namespace sf;

class Wall{

private:
    //Position
    Vector2f m_Position;

    Sprite m_Sprite;
    Texture m_Texture;
    
public:
    
    Wall();
    
    // Send a copy of the sprite to main
    Sprite getSprite();
    
    // Where is the wall
    FloatRect getPosition();
    
    void setPosition(int x, int y);
};

#endif /* wall_hpp */
