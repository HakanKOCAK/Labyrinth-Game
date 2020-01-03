#ifndef labyrinthGame_h
#define labyrinthGame_h

#include "wall.hpp"
#include "gate.hpp"
#include "pickup.hpp"
#include "enemy.hpp"

using namespace sf;

int createBackground(VertexArray& rVA, IntRect arena);
void createWallsAndGates(std::vector<Wall> &wallArray, std::vector<Gate> &gateArray);
void createPickups(std::vector<Pickup> &pickupArray);
Enemy* createEnemies(int numOfEnemies);

#endif /* labyrinthGame_h */
