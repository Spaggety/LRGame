//
//  State.hpp
//  Dessert Racers
//
//  Created by Enrique Mosqueda on 4/24/18.
//  Copyright © 2018 Enrique Mosqueda. All rights reserved.
//
#pragma once
using namespace std;

class State{
    public:
        virtual void Init() = 0;
    
        virtual void HandleInput() = 0;
        virtual void Update() = 0;
        virtual void Draw(float dt) = 0;
    
        virtual void Pause(){}
        virtual void Resume(){}
    
};
