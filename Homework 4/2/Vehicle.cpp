//
//  Vehicle.cpp
//  2
//
//  Created by Vincent Yu on 2/11/18.
//  Copyright © 2018 Vincent Yu. All rights reserved.
//

#include "Vehicle.h"

Vehicle::Vehicle(){
    manufacturer = "";
    cylinders = 0;
    owner = Person();
}

Vehicle::Vehicle(std::string theManufacturer, int theCylinders, Person theOwner){
    manufacturer = theManufacturer;
    cylinders = theCylinders;
    owner = theOwner;
}

Vehicle::Vehicle(Vehicle& a){
    manufacturer = a.manufacturer;
    cylinders = a.cylinders;
    owner = a.owner;
}

void Vehicle::setManufacturer(std::string newManufacturer){
    manufacturer = newManufacturer;
}

void Vehicle::setCylinders(int newCylinders){
    cylinders = newCylinders;
}

void Vehicle::setOwner(Person newOwner){
    owner = newOwner;
}

std::string Vehicle::getManufacturer(){
    return manufacturer;
}

int Vehicle::getCylinders(){
    return cylinders;
}

Person Vehicle::getOwner(){
    return owner;
}

Vehicle& Vehicle::operator =(const Vehicle &a){
    manufacturer = a.manufacturer;
    cylinders = a.cylinders;
    owner = a.owner;
    return *this;
}
