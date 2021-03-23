//
//  Organism.h
//  2
//
//  Created by Vincent Yu on 3/6/18.
//  Copyright © 2018 Vincent Yu. All rights reserved.
//

#ifndef Organism_h
#define Organism_h

enum OrganismType {ANT,BUG};
class World;

class Organism {
public:
    Organism(World* aWorld, int xCoordinates, int yCoordinates);
    virtual ~Organism() { }
    virtual void move() = 0;
    virtual void breed() = 0;
    virtual OrganismType getType()const = 0;
    void setMoved(bool hasMoved);
    virtual char represent()const = 0;
    virtual int size() const = 0;
    bool hasMoved() const;
    virtual bool isDead()const;
    bool range(int x1, int y2);
protected:
    int x;
    int y;
    virtual void generateOffspring(int Xlocation, int Ylocation) = 0;
    void movesTo(int newx, int newy);
    void breedAdjacent();
    bool moved;
    int breedTicks;
    World* world;
};

#endif /* Organism_h */
