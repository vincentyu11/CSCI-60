//
//  Doctor.h
//  1
//
//  Created by Vincent Yu on 2/11/18.
//  Copyright © 2018 Vincent Yu. All rights reserved.
//

#ifndef Doctor_h
#define Doctor_h

#include <string>
#include "SalariedEmployee.h"
using std::string;

class Doctor : public SalariedEmployee{
public:
    Doctor();
    Doctor(const string& theName, const string& theSsn,double theWeeklySalary, string theSpecialty, double theVisitFee);
    void setSpecialty(string newSpecialty);
    void setVisitFee(double newVisitFee);
    string getSpecialty();
    double getVisitFee();
    Doctor& operator =(const Doctor &a);
    Doctor(const Doctor &b);
private:
    string specialty;
    double visitfee;
};

#endif /* Doctor_hpp */
