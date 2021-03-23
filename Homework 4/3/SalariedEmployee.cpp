//
//  SalariedEmployee.cpp
//  1
//
//  Created by Vincent Yu on 2/11/18.
//  Copyright © 2018 Vincent Yu. All rights reserved.
//

#include <iostream>
#include <string>
#include "SalariedEmployee.h"
using std::string;
using std::cout;
using std::endl;

SalariedEmployee::SalariedEmployee( ) : Employee( ), salary(0){
    //deliberately empty
}
SalariedEmployee::SalariedEmployee(const string& theName,const string& theNumber,double theWeeklyPay)
: Employee(theName, theNumber), salary(theWeeklyPay){
    //deliberately empty
}
double SalariedEmployee::getSalary( ) const{
    return salary;
}
void SalariedEmployee::setSalary(double newSalary){
    salary = newSalary;
}
void SalariedEmployee::printCheck( ){
    setNetPay(salary);
    cout << "\n________________________________________________\n";
    cout << "Pay to the order of " << getName( ) << endl;
    cout << "The sum of " << getNetPay( ) << " Dollars\n";
    cout << "_________________________________________________\n";
    cout << "Check Stub NOT NEGOTIABLE \n";
    cout << "Employee Number: " << getSsn( ) << endl;
    cout << "Salaried Employee. Regular Pay: "
    << salary << endl;
    cout << "_________________________________________________\n";
}

