//
//  main.cpp
//  1
//
//  Created by Vincent Yu on 2/11/18.
//  Copyright © 2018 Vincent Yu. All rights reserved.
//

#include <iostream>
#include "Doctor.h"
using namespace std;

int main() {
    Doctor a("Amanda","12345678",1239.99,"Chemotherapy",123.45);
    a.setSpecialty("Surgeon");
    a.setVisitFee(500.66);
    cout << a.getSpecialty() <<endl
    << a.getVisitFee() << endl <<endl;
    Doctor b = a;
    cout << b.getName() <<endl
    <<b.getSsn() <<endl
    <<b.getSalary() <<endl
    <<b.getSpecialty() <<endl
    <<b.getVisitFee() <<endl <<endl;
    Doctor c = Doctor(a);
    c.setSpecialty("Receptionist");
    c.setVisitFee(79.89);
    cout << c.getName() <<endl
    <<c.getSsn() <<endl
    <<c.getSalary() <<endl
    <<c.getSpecialty() <<endl
    <<c.getVisitFee() <<endl <<endl;
    return 0;
}
