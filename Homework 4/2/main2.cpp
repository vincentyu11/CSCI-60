//
//  main.cpp
//  2
//
//  Created by Vincent Yu on 2/11/18.
//  Copyright © 2018 Vincent Yu. All rights reserved.
//

#include <iostream>
#include "Truck.h"
using namespace std;

int main() {
    Person owner = Person("Jim");
    Truck a("Tesla",90,owner,9000.99,5000);
    Truck b(a);
    b.setLoadCapacity(10.1);
    b.setTowingCapcity(2);
    cout << b.getLoadCapacity() <<endl
    << b.getTowingCapacity() <<endl <<endl;
    Truck c = a;
    cout << c.getManufacturer() <<endl
    <<c.getCylinders() <<endl
    <<c.getOwner() <<endl
    <<c.getLoadCapacity() <<endl
    <<c.getTowingCapacity() <<endl <<endl;
    
    return 0;
}
