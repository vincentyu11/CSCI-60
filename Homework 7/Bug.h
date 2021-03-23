//
//  Bug.h
//  2
//
//  Created by Vincent Yu on 3/6/18.
//  Copyright © 2018 Vincent Yu. All rights reserved.
//

#ifndef Bug_h
#define Bug_h

#include <iostream>
#include "World.h"
#include "Organism.h"

class Bug : public Organism
{
public:
    
    Bug(World* aWorld, int xCoordinates, int yCoordinates);
    void move();
    void breed();
    OrganismType getType() const;
    char represent() const;
    int size() const;
    bool isDead() const;
    
private:
    void generateOffspring(int Xlocation, int Ylocation);
    int deathtick;
};

#endif /* Bug_h */
