//
//  StateMachine.cpp
//  Dessert Racers
//
//  Created by Enrique Mosqueda on 4/24/18.
//  Copyright © 2018 Enrique Mosqueda. All rights reserved.
//

#include "StateMachine.hpp"

void StateMachine::addState(StateRef newState, bool isReplacing){
    this -> isAdding = true;
    this -> isReplacing = isReplacing;
    
    this -> newState = move(newState);
}

void StateMachine::removeState(){
    isRemoving = true;
}
void StateMachine::processStateChanges(){
    if(isRemoving && !states.empty()){
        states.pop();
        if(!states.empty()){
            states.top() -> Resume();
        }
        isRemoving = false;
    }
    if(isAdding){
        if(!states.empty()){
            if(isReplacing){
                states.pop();
            }
            else{
                states.top() -> Pause();
            }
        }
        states.push(move(newState));
        states.top() -> Init();
        isAdding = false;
    }
 
}
StateRef &StateMachine::getActiveState(){
    return states.top();
}



