//
//  Car.hpp
//  DesserRacers
//
//  Created by Enrique Mosqueda on 5/2/18.
//  Copyright © 2018 Enrique Mosqueda. All rights reserved.
//

#include "Entity.hpp"

class Car: public Entity{
public:
    Car(char p);
    void updating();
    void movement();
   	char p; 
	char getP() const { return p; }
    int speed = 1;
//	int speed2 = 2;
    int counterMoves;
//	int counterMoves2;
    
};
