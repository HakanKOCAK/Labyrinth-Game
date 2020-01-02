#include <SFML/Graphics.hpp>
#include "labyrinthGame.hpp"

void createWallsAndGates(std::vector<Wall> &wallArray, std::vector<Gate> &gateArray){
    Wall wall;
    Gate gate;
    int counter = 0;
    
    //Surround the arena
    while(counter < 27){
        wall.setPosition(0, 0 + counter * 100);
        wallArray.push_back(wall);
        
        counter++;
    }
    
    counter = 0;
    while(counter < 21){
        wall.setPosition( 100 + 100 * counter, 2600);
        wallArray.push_back(wall);
        
        counter++;
    }
    
    counter = 0;
    while(counter < 26){
        wall.setPosition(2100, 0 + counter * 100);
        wallArray.push_back(wall);
        
        counter++;
    }
    
    counter = 0;
    while(counter < 18){
        wall.setPosition( 300 + 100 * counter,0);
        wallArray.push_back(wall);
        
        counter++;
    }
    
    //Gate1
    counter = 0;
    while(counter < 2){
        gate.setPosition( 100 + 100 * counter, 0);
        gate.setGateNumber(1);
        gateArray.push_back(gate);
        
        counter++;
    }
    
    //Inside walls
    counter = 0;
    while(counter < 8){
        wall.setPosition(100 * counter, 2200);
        wallArray.push_back(wall);
        
        counter++;
    }
    
    counter = 0;
    while (counter < 3){
        wall.setPosition(700 , 2100 - counter * 100);
        wallArray.push_back(wall);
        
        counter++;
    }
    
    counter = 0;
    while (counter < 10){
        wall.setPosition(1000 , 2500 - counter * 100);
        wallArray.push_back(wall);
        wall.setPosition(1100 , 2500 - counter * 100);
        wallArray.push_back(wall);
        
        counter++;
    }
    
    counter = 0;
    while (counter < 3){
        wall.setPosition(1400 , 2500 - counter * 100);
        wallArray.push_back(wall);
        
        counter++;
    }
    
    counter = 0;
    while (counter < 6){
        wall.setPosition(1500 + counter * 100 , 2100);
        wallArray.push_back(wall);
        
        wall.setPosition(1500 + counter * 100 , 2000);
        wallArray.push_back(wall);
        
        counter++;
    }
    
    counter = 0;
    while (counter < 3){
        
        wall.setPosition(1500 + counter * 100, 1900);
        wallArray.push_back(wall);
        
        wall.setPosition(1500 + counter * 100, 1800);
        wallArray.push_back(wall);
        
        counter++;
    }
    
    counter = 0;
    while (counter < 5){
        wall.setPosition(counter * 100 , 1900);
        wallArray.push_back(wall);
        
        counter++;
    }
    
    counter = 0;
    while (counter < 4){
        wall.setPosition(700 , 1300 + counter * 100);
        wallArray.push_back(wall);
        
        counter++;
    }
    
    counter = 0;
    while (counter < 4){
        wall.setPosition(400 , 1300 + counter * 100);
        wallArray.push_back(wall);
        
        counter++;
    }
    
    counter = 0;
    while (counter < 13){
        wall.setPosition(counter * 100 , 1300);
        wallArray.push_back(wall);
        
        counter++;
    }
    
    //Gate2
    counter = 0;
    while (counter < 2){
        gate.setPosition(1300 + counter * 100 , 1300);
        gate.setGateNumber(2);
        gateArray.push_back(gate);
        
        counter++;
    }
    
    counter = 0;
    while (counter < 6){
        wall.setPosition(1500 + counter * 100 , 1300);
        wallArray.push_back(wall);
        
        counter++;
    }
    
    counter = 0;
    while (counter < 4){
        wall.setPosition(1700 + counter * 100, 1600);
        wallArray.push_back(wall);
        
        counter++;
    }
    
    
    counter = 0;
    while (counter < 3){
        wall.setPosition(1800 + counter * 100, 900 );
        wallArray.push_back(wall);
        
        counter++;
    }
    
    counter = 0;
    while (counter < 2){
        wall.setPosition(1900 + counter * 100, 300 );
        wallArray.push_back(wall);
        
        counter++;
    }
    
    counter = 0;
    while (counter < 2){
        wall.setPosition(700 , 1200 - counter * 100);
        wallArray.push_back(wall);
        
        counter++;
    }
    
    counter = 0;
    while (counter < 2){
        wall.setPosition(400 , 1000 - counter * 100);
        wallArray.push_back(wall);
        
        counter++;
    }
    
    counter = 0;
    while (counter < 13){
        wall.setPosition(counter * 100 , 800);
        wallArray.push_back(wall);
        
        counter++;
    }
    
    counter = 0;
    while (counter < 3){
        wall.setPosition(1000 + counter * 100, 1000);
        wallArray.push_back(wall);
        
        counter++;
    }
    
    counter = 0;
    while (counter < 4){
        wall.setPosition(900 + counter * 100, 900);
        wallArray.push_back(wall);
        
        counter++;
    }
    
    counter = 0;
    while (counter < 2){
        wall.setPosition(1200 , 700 - counter * 100);
        wallArray.push_back(wall);
        
        counter++;
    }
    
    counter = 0;
    while (counter < 6){
        wall.setPosition(1200 + counter * 100, 500 );
        wallArray.push_back(wall);
        
        counter++;
    }
    
    //Gate3
    counter = 0;
    while (counter < 2){
        gate.setPosition(1500 , 600 + counter * 100);
        gate.setGateNumber(3);
        gateArray.push_back(gate);
    
        counter++;
    }
    
    
    counter = 0;
    while (counter < 5){
        wall.setPosition(1500  , 1200 - counter * 100);
        wallArray.push_back(wall);
        
        counter++;
    }
    
    counter = 0;
    while (counter < 3){
        wall.setPosition(1500, 0 + counter * 100);
        wallArray.push_back(wall);
        
        counter++;
    }
    
    counter = 0;
    while (counter < 5){
        wall.setPosition(1000 + counter * 100, 200 );
        wallArray.push_back(wall);
        
        counter++;
    }
    
    counter = 0;
    while (counter < 3){
        wall.setPosition(800 , 700 - counter * 100);
        wallArray.push_back(wall);
        
        counter++;
    }
    
    counter = 0;
    while (counter < 4){
        wall.setPosition(200 , 700 - counter * 100);
        wallArray.push_back(wall);
        
        counter++;
    }
    
    counter = 0;
    while (counter < 4){
        wall.setPosition(500 , 0 + counter * 100);
        wallArray.push_back(wall);
        
        counter++;
    }
    
    counter = 0;
    while (counter < 3){
        wall.setPosition(300 + counter * 100, 0 );
        wallArray.push_back(wall);
        
        counter++;
    }
    
}
