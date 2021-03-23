//
//  Employee.h
//  1
//
//  Created by Vincent Yu on 2/11/18.
//  Copyright © 2018 Vincent Yu. All rights reserved.
//

#ifndef Employee_h
#define Employee_h

#include <string>
using std::string;

class Employee
{
public:
    Employee( );
    Employee(const string& theName, const string& theSsn);
    string getName( ) const;
    string getSsn( ) const;
    double getNetPay( ) const;
    void setName(const string& newName);
    void setSsn(const string& newSsn);
    void setNetPay(double newNetPay);
    void printCheck( ) const;
private:
    string name;
    string ssn;
    double netPay;
};

#endif /* employee_h */

