//
//  AssetManager.cpp
//  Dessert Racers
//
//  Created by Enrique Mosqueda on 4/24/18.
//  Copyright © 2018 Enrique Mosqueda. All rights reserved.
//

#include "AssetManager.hpp"
using namespace std;

void AssetManager::loadTexture(string name, string fileName){
    
    sf::Texture tex;
    if(tex.loadFromFile(fileName)){
        textures[name] = tex;
    }
}
sf::Texture &AssetManager::getTexture(string name){
    return textures.at(name);
}

void AssetManager::loadFont(string name, string fileName){
    
    sf::Font font;
    if(font.loadFromFile(fileName)){
        fonts[name] = font;
    }
}
sf::Font &AssetManager::getFont(string name){
    return fonts.at(name);
}

