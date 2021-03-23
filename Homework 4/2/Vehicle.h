//
//  Vehicle.h
//  2
//
//  Created by Vincent Yu on 2/11/18.
//  Copyright © 2018 Vincent Yu. All rights reserved.
//

#ifndef Vehicle_h
#define Vehicle_h
#include <string>
#include "Person.h"

class Vehicle{
public:
    Vehicle();
    Vehicle(std::string theManufacturer, int theCylinders, Person theOwner);
    Vehicle(Vehicle& a);
    
    void setManufacturer(std::string newManufacturer);
    void setCylinders(int newCylinders);
    void setOwner(Person newOwner);
    
    std::string getManufacturer();
    int getCylinders();
    Person getOwner();
    
    Vehicle& operator =(const Vehicle &a);
private:
    std::string manufacturer;
    int cylinders;
    Person owner;
};


#endif /* Vehicle_hpp */
