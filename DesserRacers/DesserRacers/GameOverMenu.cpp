//
//  GameOverMenu.cpp
//  DesserRacers
//
//  Created by Enrique Mosqueda on 5/14/18.
//  Copyright © 2018 Enrique Mosqueda. All rights reserved.
//
#include "GameOverMenu.hpp"
#include "ResourcePath.hpp"
#include <iostream>
using namespace std;
GameOverMenu::GameOverMenu(float width, float height){
    if(!font.loadFromFile(resourcePath() + "baby blocks.ttf")){
        cout << 1;;
    }
    
    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color::White);
    menu[0].setString("Play Again");
    menu[0].setCharacterSize(40);
    menu[0].setPosition(180,550);
    
    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("Exit");
    menu[1].setCharacterSize(40);
    menu[1].setPosition(420,550);

    
}

void GameOverMenu::draw(sf::RenderWindow &window){
    for (int i = 0; i < MAX_NUMBER_OF_ITMES; i++)
    {
        window.draw(menu[i]);
        
    }
    
}
void GameOverMenu::moveUp()
{
    if (MAX_NUMBER_OF_ITMES - 1 <= selectedItem + 1 && selectedItem + 1 <= MAX_NUMBER_OF_ITMES)
    {
        menu[selectedItem].setFillColor(sf::Color::White);
        selectedItem--;
        menu[selectedItem].setFillColor(sf::Color::Magenta);
    }
}
void GameOverMenu::moveDown()
{
    if (MAX_NUMBER_OF_ITMES - 2 <= selectedItem + 1 && selectedItem + 1 <= MAX_NUMBER_OF_ITMES-1)
    {
        menu[selectedItem].setFillColor(sf::Color::White);
        selectedItem++;
        menu[selectedItem].setFillColor(sf::Color::Magenta);
    }
}

