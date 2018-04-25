//
//  StateMachine.hpp
//  Dessert Racers
//
//  Created by Enrique Mosqueda on 4/24/18.
//  Copyright © 2018 Enrique Mosqueda. All rights reserved.
//

#pragma once
#include <memory>
#include <stack>
#include "State.hpp"

using namespace std;

typedef unique_ptr<State> StateRef;

class StateMachine{
public:
    //constructor
    StateMachine();
    //destructor
    ~StateMachine();
    
    void addState(StateRef newState, bool isReplacing);
    void removeState();
    void processStateChanges();
    
    
    StateRef &getActiveState();
private:
    
    stack<StateRef> states;
    StateRef newState;
    //tracks to see if states are removed/added/replaced
    bool isRemoving;
    bool isAdding;
    bool isReplacing;
    
};













