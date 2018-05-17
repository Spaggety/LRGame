//
//  Car.cpp
//  DesserRacers
//
//  Created by Enrique Mosqueda on 5/2/18.
//  Copyright © 2018 Enrique Mosqueda. All rights reserved.
//

#include "Car.hpp"
Car::Car(char p){
	this->p=p;
    rectangle.setSize(sf::Vector2f(80,80));
    rectangle.setPosition(384,800);
    rectangle.setFillColor(sf::Color::Red);
    
    sprite.setTextureRect(sf::IntRect(0,0, 80, 80));
}

void Car::updating(){
    sprite.setPosition(rectangle.getPosition());
}

void Car::movement(){
	if(getP() == 'A'){
	    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
	        rectangle.move(-speed,0);
	        sprite.setTextureRect(sf::IntRect(counterMoves * 80, 80 * 1, 80, 80));
	    }
	    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
	        rectangle.move(speed,0);
	        sprite.setTextureRect(sf::IntRect(counterMoves * 80, 80 * 2, 80, 80));
	    }

	    counterMoves++;
	    if(counterMoves==2)
	        counterMoves=0;
	    sprite.setPosition(rectangle.getPosition());
	}

	if(getP() == 'B'){
	    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
	        rectangle.move(-speed,0);
	        sprite.setTextureRect(sf::IntRect(counterMoves * 80, 80 * 1, 80, 80));
	    }
	    if(sf::Keyboard::isKeyPressed(sf::Keyboard::C)){
	        rectangle.move(speed,0);
	        sprite.setTextureRect(sf::IntRect(counterMoves * 80, 80 * 2, 80, 80));
	    }

	    counterMoves++;
	    if(counterMoves==2)
	        counterMoves=0;
	    sprite.setPosition(rectangle.getPosition());
	}

}
