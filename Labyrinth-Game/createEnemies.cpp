// #include "stdafx.h" <- Visual Studio only
#include "labyrinthGame.hpp"
#include "enemy.hpp"

Enemy* createEnemies(int numOfEnemies){
    Enemy* enemies = new Enemy[numOfEnemies];
    
    float positions [numOfEnemies][2];
    
    positions[0][0] = 750;
    positions[0][1] = 1800;
    
    positions[1][0] = 450;
    positions[1][1] = 2100;
    
    positions[2][0] = 250;
    positions[2][1] = 1700;
    
    positions[3][0] = 1300;
    positions[3][1] = 2400;
    
    positions[4][0] = 1800;
    positions[4][1] = 2500;
    
    positions[5][0] = 1350;
    positions[5][1] = 2000;
    
    positions[6][0] = 1900;
    positions[6][1] = 1900;
    
    positions[7][0] = 1900;
    positions[7][1] = 1700;
    
    positions[8][0] = 1500;
    positions[8][1] = 1700;
    
    positions[9][0] = 1150;
    positions[9][1] = 1200;
    
    positions[10][0] = 850;
    positions[10][1] = 1000;
    
    positions[11][0] = 300;
    positions[11][1] = 1100;
    
    positions[12][0] = 1900;
    positions[12][1] = 750;
    
    positions[13][0] = 1700;
    positions[13][1] = 1150;
    
    positions[14][0] = 2000;
    positions[14][1] = 1150;
    
    positions[15][0] = 2000;
    positions[15][1] = 450;
    
    positions[16][0] = 1750;
    positions[16][1] = 250;
    
    positions[17][0] = 1300;
    positions[17][1] = 300;
    
    positions[18][0] = 1050;
    positions[18][1] = 500;
    
    positions[19][0] = 750;
    positions[19][1] = 300;
    
    positions[20][0] = 600;
    positions[20][1] = 700;
    
    positions[21][0] = 300;
    positions[21][1] = 300;
    
    for (int i = 0; i < numOfEnemies; i++){
        // Spawn the enemies into the array
        enemies[i].spawn(positions[i][0], positions[i][1]);
    }
     return enemies;
}
