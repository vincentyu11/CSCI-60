//
//  Person.cpp
//  2
//
//  Created by Vincent Yu on 2/11/18.
//  Copyright © 2018 Vincent Yu. All rights reserved.
//

#include "Person.h"
#include <string>
#include <iostream>

Person::Person( ){
    name = "";
}

Person::Person(std::string theName){
    name = theName;
}

Person::Person(const Person& theObject){
    name = theObject.name;
}

std::string Person::getName( ) const{
    return name;
}

Person& Person::operator=(const Person& rtSide){
    name = rtSide.name;
    return *this;
}

std::istream& operator >>(std::istream& inStream, Person& personObject){
    inStream >> personObject.name;
    return inStream;
}

std::ostream& operator <<(std::ostream& outStream, const Person& personObject){
    outStream << personObject.name;
    return outStream;
}

