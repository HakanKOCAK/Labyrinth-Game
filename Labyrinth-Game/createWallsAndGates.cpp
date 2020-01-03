#include <SFML/Graphics.hpp>
#include "labyrinthGame.hpp"

void createWallsAndGates(std::vector<Wall> &wallArray, std::vector<Gate> &gateArray){
    Wall wall;
    Gate gate;
    int counter = 0;
    
    //Surround the arena
    while(counter < 27){
        wall.setPosition(50, 50 + counter * 100);
        wallArray.push_back(wall);
        
        counter++;
    }
    
    counter = 0;
    while(counter < 21){
        wall.setPosition( 150 + 100 * counter, 2650);
        wallArray.push_back(wall);
        
        counter++;
    }
    
    counter = 0;
    while(counter < 26){
        wall.setPosition(2150, 50 + counter * 100);
        wallArray.push_back(wall);
        
        counter++;
    }
    
    counter = 0;
    while(counter < 18){
        wall.setPosition( 350 + 100 * counter,+50);
        wallArray.push_back(wall);
        
        counter++;
    }
    
    //Gate3
    counter = 0;
    while(counter < 2){
        gate.setPosition( 150 + 100 * counter, +50);
        gate.setGateNumber(3);
        gateArray.push_back(gate);
        
        counter++;
    }
    
    //Inside walls
    counter = 0;
    while(counter < 8){
        wall.setPosition(50 + 100 * counter, 2250);
        wallArray.push_back(wall);
        
        counter++;
    }
    
    counter = 0;
    while (counter < 3){
        wall.setPosition(750 , 2150 - counter * 100);
        wallArray.push_back(wall);
        
        counter++;
    }
    
    counter = 0;
    while (counter < 10){
        wall.setPosition(1050 , 2550 - counter * 100);
        wallArray.push_back(wall);
        wall.setPosition(1150 , 2550 - counter * 100);
        wallArray.push_back(wall);
        
        counter++;
    }
    
    counter = 0;
    while (counter < 2){
        wall.setPosition(1450 , 2550 - counter * 100);
        wallArray.push_back(wall);
        
        counter++;
    }
    
    counter = 0;
    while (counter < 6){
        wall.setPosition(1550 + counter * 100 , 2150);
        wallArray.push_back(wall);
        
        wall.setPosition(1550 + counter * 100 , 2050);
        wallArray.push_back(wall);
        
        counter++;
    }
    
    counter = 0;
    while (counter < 2){
        
        wall.setPosition(1550 + counter * 100, 1950);
        wallArray.push_back(wall);
        
        wall.setPosition(1550 + counter * 100, 1850);
        wallArray.push_back(wall);
        
        counter++;
    }
    
    counter = 0;
    while (counter < 5){
        wall.setPosition(50 + counter * 100 , 1950);
        wallArray.push_back(wall);
        
        counter++;
    }
    
    counter = 0;
    while (counter < 4){
        wall.setPosition(750 , 1350 + counter * 100);
        wallArray.push_back(wall);
        
        counter++;
    }
    
    counter = 0;
    while (counter < 4){
        wall.setPosition(450 , 1350 + counter * 100);
        wallArray.push_back(wall);
        
        counter++;
    }
    
    counter = 0;
    while (counter < 13){
        wall.setPosition(50 + counter * 100 , 1350);
        wallArray.push_back(wall);
        
        counter++;
    }
    
    //Gate1
    counter = 0;
    while (counter < 2){
        gate.setPosition(1350 + counter * 100 , 1350);
        gate.setGateNumber(1);
        gateArray.push_back(gate);
        
        counter++;
    }
    
    counter = 0;
    while (counter < 6){
        wall.setPosition(1550 + counter * 100 , 1350);
        wallArray.push_back(wall);
        
        counter++;
    }
    
    counter = 0;
    while (counter < 4){
        wall.setPosition(1750 + counter * 100, 1550);
        wallArray.push_back(wall);
        
        counter++;
    }
    
    
    counter = 0;
    while (counter < 3){
        wall.setPosition(1850 + counter * 100, 950 );
        wallArray.push_back(wall);
        
        counter++;
    }
    
    counter = 0;
    while (counter < 2){
        wall.setPosition(1950 + counter * 100, 250 );
        wallArray.push_back(wall);
        
        counter++;
    }
    
    counter = 0;
    while (counter < 2){
        wall.setPosition(750 , 1200 - counter * 150);
        wallArray.push_back(wall);
        
        counter++;
    }
    
    counter = 0;
    while (counter < 2){
        wall.setPosition(450 , 1050 - counter * 100);
        wallArray.push_back(wall);
        
        counter++;
    }
    
    counter = 0;
    while (counter < 13){
        wall.setPosition(50 + counter * 100 , 850);
        wallArray.push_back(wall);
        
        counter++;
    }
    
    counter = 0;
    while (counter < 3){
        wall.setPosition(1050 + counter * 100, 1050);
        wallArray.push_back(wall);
        
        counter++;
    }
    
    counter = 0;
    while (counter < 3){
        wall.setPosition(1050 + counter * 100, 950);
        wallArray.push_back(wall);
        
        counter++;
    }
    
    counter = 0;
    while (counter < 2){
        wall.setPosition(1250 , 750 - counter * 100);
        wallArray.push_back(wall);
        
        counter++;
    }
    
    counter = 0;
    while (counter < 6){
        wall.setPosition(1250 + counter * 100, 550 );
        wallArray.push_back(wall);
        
        counter++;
    }
    
    //Gate2
    counter = 0;
    while (counter < 2){
        gate.setPosition(1550 , 650 + counter * 100);
        gate.setGateNumber(2);
        gateArray.push_back(gate);
    
        counter++;
    }
    
    
    counter = 0;
    while (counter < 5){
        wall.setPosition(1550  , 1250 - counter * 100);
        wallArray.push_back(wall);
        
        counter++;
    }
    
    counter = 0;
    while (counter < 3){
        wall.setPosition(1550, 50 + counter * 100);
        wallArray.push_back(wall);
        
        counter++;
    }
    
    counter = 0;
    while (counter < 3){
        wall.setPosition(1050, 50 + counter * 100 );
        wallArray.push_back(wall);
        
        counter++;
    }
    
    counter = 0;
    while (counter < 3){
        wall.setPosition(850 , 700 - counter * 150);
        wallArray.push_back(wall);
        
        counter++;
    }
    
    counter = 0;
    while (counter < 2){
        wall.setPosition(350 , 750 - counter * 150);
        wallArray.push_back(wall);
        
        counter++;
    }
    
    counter = 0;
    while (counter < 4){
        wall.setPosition(550 , 0 + counter * 150);
        wallArray.push_back(wall);
        
        counter++;
    }
    
    counter = 0;
    while (counter < 3){
        wall.setPosition(350 + counter * 100, 50 );
        wallArray.push_back(wall);
        
        counter++;
    }
    
}
