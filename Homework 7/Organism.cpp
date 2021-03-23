//
//  Organism.cpp
//  2
//
//  Created by Vincent Yu on 3/6/18.
//  Copyright © 2018 Vincent Yu. All rights reserved.
//

#include <iostream>
#include "Organism.h"
#include "World.h"

Organism::Organism(World* aWorld, int xCoordinates, int yCoordinates){
    world=aWorld;
    x=xCoordinates;
    y=yCoordinates;
    breedTicks=0;
    moved=false;
    world->setAt(x, y, this);
}

void Organism::setMoved(bool hasMoved){
    moved=hasMoved;
}

bool Organism::hasMoved() const{
    return moved;
}

void Organism::movesTo(int newx, int newy){
    world->setAt(newx, newy, world->getAt(x, y));
    world->setAt(x, y, NULL);
    x=newx;
    y=newy;
    world->getAt(x, y)->setMoved(true);
}

void Organism::breedAdjacent(){
    if((world->getAt(x, y+1) == NULL) && range(x, y+1)){
        generateOffspring(x, y + 1);
    }
    else if((world->getAt(x, y-1) == NULL) && range(x, y-1)){
        generateOffspring(x, y-1);
    }
    else if((world->getAt(x-1, y) == NULL)  && range(x-1, y)){
        generateOffspring(x-1, y);
    }
    else if((world->getAt(x+1, y) == NULL)  && range(x+1, y)){
        generateOffspring(x+1, y);
    }
}


bool Organism::range(int x1, int y2){
    return (x1>=0) && (x1 < SIZE_OF_WORLD) && (y2>=0) && (y2 < SIZE_OF_WORLD);
}

bool Organism::isDead() const{
    return false;
}
