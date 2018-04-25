//
//  AssetManager.hpp
//  Dessert Racers
//
//  Created by Enrique Mosqueda on 4/24/18.
//  Copyright © 2018 Enrique Mosqueda. All rights reserved.
//

#pragma once

#include <map>
#include <SFML/Graphics.hpp>

using namespace std;

class AssetManager{
public:
    AssetManager();
    ~AssetManager();
    
    void loadTexture(string name, string fileName);
    sf::Texture &getTexture(string name);
    
    
    void loadFont(string name, string fileName);
    sf::Font &getFont(string name);
    
private:
    map<string, sf::Texture> textures;
    map<string, sf::Font> fonts;
    
};
