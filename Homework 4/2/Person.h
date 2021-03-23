//
//  Person.h
//  2
//
//  Created by Vincent Yu on 2/11/18.
//  Copyright © 2018 Vincent Yu. All rights reserved.
//

#ifndef Person_h
#define Person_h
#include <string>

class Person
{
public:
    Person( );
    Person(std::string theName);
    Person(const Person& theObject);
    std::string getName( ) const;
    Person& operator=(const Person& rtSide);
    friend std::istream& operator >>(std::istream& inStream, Person& personObject);
    friend std::ostream& operator <<(std::ostream& outStream, const Person& personObject);
private:
    std::string name;
};

#endif /* Person_hpp */
