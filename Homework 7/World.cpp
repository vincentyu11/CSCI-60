//
//  World.cpp
//  2
//
//  Created by Vincent Yu on 3/6/18.
//  Copyright © 2018 Vincent Yu. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include "Ant.h"
#include "Bug.h"
#include "World.h"
using namespace std;

World::World(unsigned int seed){
    srand(seed);
    for (int i=0; i<SIZE_OF_WORLD; i++) {
        for (int j=0; j<SIZE_OF_WORLD; j++) {
            field[i][j] = NULL;
        }
    }
    createOrganism(ANT, INITIAL_ANTS);
    createOrganism(BUG, INITIAL_BUGS);
}

Organism* World::getAt(int x, int y) const {
    if ((x>=0) && (x<SIZE_OF_WORLD) && (y>=0) && (y<SIZE_OF_WORLD)) {
        return field[x][y];
    }
    else{
        return NULL;
    }
}

void World::setAt(int x, int y, Organism* org){
    if ((x>=0) && (x<SIZE_OF_WORLD) && (y>=0) && (y<SIZE_OF_WORLD)) {
        field[x][y]=org;
    }
}

void World::displayField()const{
    int numAnts=0;
    int numBugs=0;
    cout <<endl <<endl;
    for (int j=0; j<SIZE_OF_WORLD; j++){
        for (int i=0; i<SIZE_OF_WORLD; i++){
            if (field[i][j] == NULL) {
                cout <<"-";
            }
            else {
                if (field[i][j]->getType() == ANT){
                    numAnts++;
                }
                else if (field[i][j]->getType() == BUG){
                    numBugs++;
                }
                cout <<field[i][j]->represent();
            }
        }
        cout <<endl;
    }
    cout <<"Number of Ants: " <<numAnts <<"\n" <<"Number of Bugs: " <<numBugs <<endl;
}

void World::oneRound(){
    resetOrganism();
    moveOrganism(BUG);
    moveOrganism(ANT);
    eraseDead();
    breedOrganism();
}

Position World::ition()const{
    Position p;
    p.x=rand()%SIZE_OF_WORLD;
    p.y=rand()%SIZE_OF_WORLD;
    return p;
}

Move World::randomMove()const{
    return static_cast<Move>(rand()%4);
}

void World::createOrganism(OrganismType orgType, int count){
    int orgCount=0;
    while (orgCount<count){
        Position p = ition();
        if (field[p.x][p.y] == NULL){
            orgCount++;
            if (orgType==ANT){
                new Ant(this, p.x, p.y);
            }
            else if (orgType==BUG){
                new Bug(this, p.x, p.y);
            }
        }
    }
}


void World::resetOrganism(){
    for(int i=0; i<SIZE_OF_WORLD; i++){
        for (int j=0; j<SIZE_OF_WORLD; j++){
            if(field[i][j]!=NULL){
                field[i][j]->setMoved(false);
            }
        }
    }
}


void World::moveOrganism(OrganismType aType) {
    for(int i=0; i<SIZE_OF_WORLD; i++){
        for(int j=0; j<SIZE_OF_WORLD; j++){
            if(field[i][j] != NULL){
                if(field[i][j]->getType() == aType && !(field[i][j]->hasMoved())){
                    field[i][j]->move();
                }
            }
        }
    }
}

void World::eraseDead() {
    for (int i=0; i<SIZE_OF_WORLD; i++) {
        for (int j=0; j<SIZE_OF_WORLD; j++) {
            if ((field[i][j] != NULL) && field[i][j]->isDead()) {
                delete field[i][j];
                field[i][j] = NULL;
            }
        }
    }
}


void World::breedOrganism() {
    for(int i=0; i<SIZE_OF_WORLD; i++){
        for(int j=0; j<SIZE_OF_WORLD; j++){
            if(field[i][j]!=NULL){
                field[i][j]->breed();
            }
        }
    }
}
