//
//  GameOverMenu.hpp
//  DesserRacers
//
//  Created by Enrique Mosqueda on 5/14/18.
//  Copyright © 2018 Enrique Mosqueda. All rights reserved.
//
#include <SFML/Graphics.hpp>

#pragma once
const int MAX_NUMBER_OF_ITMES = 3;


class GameOverMenu {
    
public:
    GameOverMenu(float width, float height);
    //    ~MainMenu();
    
    void draw(sf::RenderWindow &window);
    void moveUp();
    void moveDown();
    int getSelectedItemIndex() { return selectedItem; }
private:
    sf::Font font;
    sf::Text menu[MAX_NUMBER_OF_ITMES];
    int selectedItem = 1;
    
};
