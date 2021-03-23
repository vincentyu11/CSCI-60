//
//  Doctor.cpp
//  1
//
//  Created by Vincent Yu on 2/11/18.
//  Copyright © 2018 Vincent Yu. All rights reserved.
//

#include <iostream>
#include <string>
#include "Doctor.h"
using std::string;
using std::cout;
using std::endl;

Doctor::Doctor() :SalariedEmployee(), specialty("No Specialty"), visitfee(0){
    //deliberately empty
}

Doctor::Doctor(const string& theName, const string& theSsn, double theWeeklySalary, string theSpecialty, double theVisitFee) : SalariedEmployee(theName, theSsn, theWeeklySalary), specialty(theSpecialty), visitfee(theVisitFee){
    //deliberately empty
}

void Doctor::setSpecialty(string newSpecialty){
    specialty = newSpecialty;
}

void Doctor::setVisitFee(double newVisitFee){
    visitfee = newVisitFee;
}

string Doctor::getSpecialty(){
    return specialty;
}

double Doctor::getVisitFee(){
    return visitfee;
}

Doctor& Doctor::operator =(const Doctor &a){
    specialty = a.specialty;
    visitfee = a.visitfee;
    return *this;
}

Doctor::Doctor(const Doctor &b) : SalariedEmployee(b){
    specialty = b.specialty;
    visitfee = b.visitfee;
}

