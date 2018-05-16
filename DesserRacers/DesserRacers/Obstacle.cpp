//
//  Obstacle.cpp
//  DesserRacers
//
//  Created by Enrique Mosqueda on 5/3/18.
//  Copyright © 2018 Enrique Mosqueda. All rights reserved.
//

#include "Obstacle.hpp"
Obstacle::Obstacle(){
    
    rectangle.setSize(sf::Vector2f(85,70));
    rectangle.setFillColor(sf::Color::Yellow);
}
void Obstacle::updating(){
    rectangle.move(0, speed);

    //setting sprite @ rectangle position
    sprite.setPosition(rectangle.getPosition());
}

