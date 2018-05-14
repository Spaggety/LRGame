//
//  Obstacle.cpp
//  DesserRacers
//
//  Created by Enrique Mosqueda on 5/3/18.
//  Copyright © 2018 Enrique Mosqueda. All rights reserved.
//

#include "Obstacle.hpp"
Obstacle::Obstacle(){
    int num1;
    srand(time(0));
    int derivedRandomNum = (rand() % 462) + 153;
    num1 = (rand() % derivedRandomNum) + 152;
    
    rectangle.setSize(sf::Vector2f(85,70));
    rectangle.setPosition(num1,-500);
    rectangle.setFillColor(sf::Color::Yellow);
}
void Obstacle::updating(){
    rectangle.move(0, speed);

    //setting sprite @ rectangle position
    sprite.setPosition(rectangle.getPosition());
}

