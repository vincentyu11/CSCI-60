//
//  Patient.cpp
//  3
//
//  Created by Vincent Yu on 2/11/18.
//  Copyright © 2018 Vincent Yu. All rights reserved.
//

#include "Patient.h"
#include <string>

Patient::Patient() :Person(), physician(Doctor()){
    //deliberately empty
}

Patient::Patient(std::string name, Doctor thePhysician) :Person(name), physician(thePhysician){
    //deliberately empty
}

Patient::Patient(Patient &a) :Person(a){
    physician = a.physician;
}

void Patient::setPhysician(Doctor newPhysician){
    physician = newPhysician;
}

Doctor Patient::getPhysician(){
    return physician;
}

Patient& Patient::operator =(const Patient &a){
    physician = a.physician;
    return *this;
}
