//
//  Entity.hpp
//  DesserRacers
//
//  Created by Enrique Mosqueda on 5/2/18.
//  Copyright © 2018 Enrique Mosqueda. All rights reserved.
//

#ifndef ENT
#define ENT
#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include <cmath>
#include "ResourcePath.hpp"
#include <cstdlib>
#include <functional>
#include <tgmath.h>
#include <deque>
#include <list>
#include <vector>
#include <unistd.h>
using namespace std;


class Entity{
public:
    sf::RectangleShape rectangle;
    sf::Sprite sprite;
    sf::Text text;
    sf::Texture texture;
};
#endif
