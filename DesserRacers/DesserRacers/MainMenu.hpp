//
//  MainMenu.hpp
//  DesserRacers
//
//  Created by Enrique Mosqueda on 4/30/18.
//  Copyright © 2018 Enrique Mosqueda. All rights reserved.
//

#include <SFML/Graphics.hpp>
#pragma once
#define MAX_NUMBER_OF_ITMES 3



class MainMenu {
    
public:
    MainMenu(float width, float height);
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
