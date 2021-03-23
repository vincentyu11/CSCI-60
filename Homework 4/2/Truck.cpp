//
//  Truck.cpp
//  2
//
//  Created by Vincent Yu on 2/11/18.
//  Copyright © 2018 Vincent Yu. All rights reserved.
//

#include "Truck.h"

Truck::Truck() :Vehicle(), loadcapacity(0), towingcapacity(0){
    //deliberately empty
}

Truck::Truck(std::string theManufacturer, int theCylinders, Person theOwner, double theLoadCapacity, int theTowingCapacity)
    :Vehicle(theManufacturer,theCylinders,theOwner), loadcapacity(theLoadCapacity), towingcapacity(theTowingCapacity){
    //deliberately empty
}
Truck::Truck(Truck &a) : Vehicle(a){
    loadcapacity = a.loadcapacity;
    towingcapacity = a.towingcapacity;
}

void Truck::setLoadCapacity(double newLoadCapacity){
    loadcapacity = newLoadCapacity;
}

void Truck::setTowingCapcity(int newTowingCapacity){
    towingcapacity = newTowingCapacity;
}

double Truck::getLoadCapacity(){
    return loadcapacity;
}

double Truck::getTowingCapacity(){
    return towingcapacity;
}

Truck& Truck::operator =(const Truck &a){
    loadcapacity = a.loadcapacity;
    towingcapacity = a.towingcapacity;
    return *this;
}
