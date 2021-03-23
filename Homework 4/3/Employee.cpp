//
//  Employee.cpp
//  1
//
//  Created by Vincent Yu on 2/11/18.
//  Copyright © 2018 Vincent Yu. All rights reserved.
//

#include <string>
#include <cstdlib>
#include <iostream>
#include "Employee.h"
using std::string;
using std::cout;

Employee::Employee( ) : name("No name yet"), ssn("No number yet"), netPay(0){
    //deliberately empty
}
Employee::Employee(const string& theName, const string& theNumber)
: name(theName), ssn(theNumber), netPay(0){
    //deliberately empty
}
string Employee::getName( ) const{
    return name;
}
string Employee::getSsn( ) const{
    return ssn;
}
double Employee::getNetPay( ) const{
    return netPay;
}
void Employee::setName(const string& newName){
    name = newName;
}
void Employee::setSsn(const string& newSsn){
    ssn = newSsn;
}
void Employee::setNetPay (double newNetPay){
    netPay = newNetPay;
}
void Employee::printCheck( ) const{
    cout << "\nERROR: printCheck FUNCTION CALLED FOR AN \n"
    << "UNDIFFERENTIATED EMPLOYEE. Aborting the program.\n"
    << "Check with the author of the program about this bug.\n";
    exit(1);
}



