#include <SFML/Graphics.hpp>
#include "labyrinthGame.hpp"

void createPickups(std::vector<Pickup> &pickupArray){
    Pickup healthPickup1(1);
    healthPickup1.setPosition(1300, 2500);
    pickupArray.push_back(healthPickup1);
    
    Pickup ammoPickup1(2);
    ammoPickup1.setPosition(180, 2100);
    pickupArray.push_back(ammoPickup1);
    
    Pickup healthPickup2(1);
    healthPickup2.setPosition(180, 1500);
    pickupArray.push_back(healthPickup2);
    
    Pickup ammoPickup2(2);
    ammoPickup2.setPosition(2000, 1900);
    pickupArray.push_back(ammoPickup2);
    
    Pickup keyPickup1(3);
    keyPickup1.setPosition(2000, 2500);
    pickupArray.push_back(keyPickup1);
    
    Pickup ammoPickup3(2);
    ammoPickup3.setPosition(550, 970);
    pickupArray.push_back(ammoPickup3);
    
    Pickup healthPickup3(1);
    healthPickup3.setPosition(180, 1250);
    pickupArray.push_back(healthPickup3);
    
    Pickup keyPickup2(3);
    keyPickup2.setPosition(160, 970);
    pickupArray.push_back(keyPickup2);
    
    Pickup ammoPickup4(2);
    ammoPickup4.setPosition(2000, 1250);
    pickupArray.push_back(ammoPickup4);
    
    Pickup healthPickup4(1);
    healthPickup4.setPosition(1400, 150);
    pickupArray.push_back(healthPickup4);
    
    
    Pickup ammoPickup5(2);
    ammoPickup5.setPosition(1150, 750);
    pickupArray.push_back(ammoPickup5);
    
    Pickup keyPickup3(3);
    keyPickup3.setPosition(160, 750);
    pickupArray.push_back(keyPickup3);
}
