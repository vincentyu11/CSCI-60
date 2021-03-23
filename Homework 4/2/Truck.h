//
//  Truck.h
//  2
//
//  Created by Vincent Yu on 2/11/18.
//  Copyright © 2018 Vincent Yu. All rights reserved.
//

#ifndef Truck_h
#define Truck_h
#include <string>
#include "Vehicle.h"

class Truck : public Vehicle{
public:
    Truck();
    Truck(std::string theManufacturer, int theCylinders, Person theOwner, double theLoadCapacity, int theTowingCapacity);
    Truck(Truck &a);
    
    void setLoadCapacity(double newLoadCapacity);
    void setTowingCapcity(int newTowingCapacity);
    
    double getLoadCapacity();
    double getTowingCapacity();
    
    Truck& operator =(const Truck &a);
private:
    double loadcapacity;
    int towingcapacity;
};

#endif /* Truck_hpp */
