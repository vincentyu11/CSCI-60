//
//  Ant.h
//  2
//
//  Created by Vincent Yu on 3/6/18.
//  Copyright © 2018 Vincent Yu. All rights reserved.
//

#ifndef Ant_h
#define Ant_h

#include <iostream>
#include "World.h"
#include "Organism.h"

class Ant : public Organism
{
public:
    Ant(World* aWorld, int xCoordinates, int yCoordinates);
    void move();
    void breed();
    OrganismType getType() const;
    char represent() const;
    int size() const;
private:
    void generateOffspring(int Xlocation, int Ylocation);
};

#endif /* Ant_h */
