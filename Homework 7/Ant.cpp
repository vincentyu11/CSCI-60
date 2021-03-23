//
//  Ant.cpp
//  2
//
//  Created by Vincent Yu on 3/6/18.
//  Copyright © 2018 Vincent Yu. All rights reserved.
//

#include <cstdlib>

#include <iostream>
#include "Ant.h"
#include "Organism.h"
#include "World.h"
using namespace std;

Ant::Ant(World* aWorld, int xCoordinates, int yCoordinates) : Organism(aWorld, xCoordinates, yCoordinates){
}

void Ant::move(){
    breedTicks++;
    Move mover = world->randomMove();
    switch (mover){
        case RIGHT:
            if(world->getAt(x+1, y) == NULL && range(x+1, y)){
                movesTo(x+1, y);
            }
            break;
        case LEFT:
            if(world->getAt(x-1, y) == NULL && range(x-1, y)){
                movesTo(x-1, y);
            }
            break;
        case UP:
            if(world->getAt(x, y+1) == NULL && range(x, y+1)){
                movesTo(x, y+1);
            }
            break;
        case DOWN:
            if(world->getAt(x, y-1) == NULL && range(x, y-1)){
                movesTo(x, y-1);
            }
            break;
        default:
            break;
    }
}

void Ant::breed(){
    if(breedTicks>=ANTS_BIRTH){
        breedAdjacent();
    }
}

void Ant::generateOffspring(int Xlocation, int Ylocation){
    new Ant(this->world, Xlocation, Ylocation);
    breedTicks=0;
}


OrganismType Ant::getType() const{
    return ANT;
}

char Ant::represent() const{
    return 'O';
}

int Ant::size() const{
    return 10;
}

