//
//  labyrinthGame.hpp
//  Labyrinth-Game
//
//  Created by Hakan KOCAK on 2.01.2020.
//  Copyright © 2020 Hakan KOCAK. All rights reserved.
//

#ifndef labyrinthGame_h
#define labyrinthGame_h
#include "wall.hpp"
#include "gate.hpp"

using namespace sf;

int createBackground(VertexArray& rVA, IntRect arena);
void createWallsAndGates(std::vector<Wall> &wallArray, std::vector<Gate> &gateArray);

#endif /* labyrinthGame_h */
