//
//  Obstacle.hpp
//  DesserRacers
//
//  Created by Enrique Mosqueda on 5/3/18.
//  Copyright © 2018 Enrique Mosqueda. All rights reserved.
//
#pragma once

#include "Entity.hpp"
#include <random>

class Obstacle : public Entity{
public:
    
    Obstacle();
    
    void updating();
    int speed = 3;
};
