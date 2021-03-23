//
//  SalariedEmployee.h
//  1
//
//  Created by Vincent Yu on 2/11/18.
//  Copyright © 2018 Vincent Yu. All rights reserved.
//

#ifndef SalariedEmployee_h
#define SalariedEmployee_h

#include <string>
#include "Employee.h"
using std::string;

class SalariedEmployee : public Employee{
public:
    SalariedEmployee( );
    SalariedEmployee (const string& theName, const string& theSsn,double theWeeklySalary);
    double getSalary( ) const;
    void setSalary(double newSalary);
    void printCheck( );
private:
    double salary;//weekly
};

#endif /* SalariedEmployee_hpp */
