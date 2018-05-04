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
    Car();
    void updating();
    void movement();
    
    int speed = 2;
    int counterMoves;
    
};
