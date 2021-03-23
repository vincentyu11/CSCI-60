//
//  World.h
//  2
//
//  Created by Vincent Yu on 3/6/18.
//  Copyright © 2018 Vincent Yu. All rights reserved.
//

#ifndef World_h
#define World_h
#include "Organism.h"

const int INITIAL_ANTS = 100;
const int INITIAL_BUGS = 5;
const int ANTS_BIRTH = 3;
const int BUGS_BIRTH = 8;
const int BUGS_DEATH = 3;
const int SIZE_OF_WORLD = 20;
enum Move {UP = 0, DOWN, LEFT, RIGHT};

struct Position{
    int x;
    int y;
};

class World{
public:
    World(unsigned int seed);
    Organism* getAt(int x, int y) const;
    void setAt(int x, int y, Organism* org);
    void displayField() const;
    void oneRound();
    Position ition() const;
    Move randomMove() const;
    
private:
    Organism* field[SIZE_OF_WORLD][SIZE_OF_WORLD];
    void createOrganism(OrganismType orgType, int count);
    void moveOrganism(OrganismType aType);
    void breedOrganism();
    void resetOrganism();
    void eraseDead();
};

#endif /* World_h */
