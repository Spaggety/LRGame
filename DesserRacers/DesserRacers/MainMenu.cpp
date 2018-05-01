//
//  MainMenu.cpp
//  DesserRacers
//
//  Created by Enrique Mosqueda on 4/30/18.
//  Copyright © 2018 Enrique Mosqueda. All rights reserved.
//


#include "MainMenu.hpp"
#include "ResourcePath.hpp"

MainMenu::MainMenu(float width, float height){
    if(!font.loadFromFile(resourcePath() + "baby blocks.ttf")){
        return EXIT_FAILURE;
    }
    
    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color::White);
    menu[0].setString("Play");
    menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITMES + 1) * 1));
    
    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("Options");
    menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITMES + 1) * 2));
    
    menu[2].setFont(font);
    menu[2].setFillColor(sf::Color::White);
    menu[2].setString("Exit");
    menu[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITMES + 1) * 3));
    
    
}

void MainMenu::draw(sf::RenderWindow &window){
    for (int i = 0; i < MAX_NUMBER_OF_ITMES; i++)
    {
        window.draw(menu[i]);
    }
}
void MainMenu::moveUp()
{
    if (MAX_NUMBER_OF_ITMES - 1 <= selectedItem + 1 && selectedItem + 1 <= MAX_NUMBER_OF_ITMES)
    {
        menu[selectedItem].setFillColor(sf::Color::White);
        selectedItem--;
        menu[selectedItem].setFillColor(sf::Color::Magenta);
    }
}
void MainMenu::moveDown()
{
    if (MAX_NUMBER_OF_ITMES - 2 <= selectedItem + 1 && selectedItem + 1 <= MAX_NUMBER_OF_ITMES-1)
    {
        menu[selectedItem].setFillColor(sf::Color::White);
        selectedItem++;
        menu[selectedItem].setFillColor(sf::Color::Magenta);
    }
}

