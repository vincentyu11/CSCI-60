//
//  main.cpp
//  2
//
//  Created by Vincent Yu on 3/6/18.
//  Copyright © 2018 Vincent Yu. All rights reserved.
//

#include <iostream>
#include "World.h"
using namespace std;

int main()
{
    World myWorld(0);
    myWorld.displayField();
    cout<< "Press enter for next round." <<"\n" <<"Enter 'q' to quit the game." <<endl;
    char ch;
    while (cin.get(ch) && ch != 'q') {
        myWorld.oneRound();
        myWorld.displayField();
        cout<< "Press enter for next round." <<"\n" <<"Enter 'q' to quit the game." <<endl;
    }
    return 0;
}
