//
//  Bug.cpp
//  2
//
//  Created by Vincent Yu on 3/6/18.
//  Copyright © 2018 Vincent Yu. All rights reserved.
//

#include "Bug.h"
#include "Organism.h"
using namespace std;

Bug::Bug(World* aWorld, int xCoordinates, int yCoordinates):Organism(aWorld, xCoordinates, yCoordinates){
    deathtick = 0;
}

void Bug::move(){
    breedTicks++;
    deathtick++;
    if(world->getAt(x, y+1) != NULL){
        if(world->getAt(x, y+1)->getType() == ANT){
            deathtick = 0;
            delete world->getAt(x, y+1);
            movesTo(x, y+1);
            return;
        }
    }
    if(world->getAt(x, y-1) != NULL){
        if(world->getAt(x, y-1)->getType() == ANT){
            deathtick=0;
            delete world->getAt(x, y-1);
            movesTo(x, y-1);
            return;
        }
    }
    if(world->getAt(x-1, y) != NULL){
        if(world->getAt(x-1, y)->getType() == ANT){
            deathtick=0;
            delete world->getAt(x-1, y);
            movesTo(x-1, y);
            return;
        }
    }
    if(world->getAt(x+1, y) != NULL){
        if(world->getAt(x+1, y)->getType() == ANT){
            deathtick=0;
            delete world->getAt(x+1, y);
            movesTo(x+1, y);
            return;
        }
    }
    Move mover=world->randomMove();
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
            if(world->getAt(x, y+1) == NULL && range(x, y +1)){
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

void Bug::generateOffspring(int Xlocation, int Ylocation){
    new Bug(this->world, Xlocation, Ylocation);
    breedTicks = 0;
}

void Bug::breed(){
    if(breedTicks>=BUGS_BIRTH){
        breedAdjacent();
    }
}

bool Bug::isDead() const{
    if(deathtick>=BUGS_DEATH){
        return true;
    }
    else{
        return false;
    }
}

OrganismType Bug::getType() const{
    return BUG;
}

char Bug::represent()const{
    return 'X';
}

int Bug::size() const{
    return 30;
}

