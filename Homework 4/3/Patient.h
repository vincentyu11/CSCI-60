//
//  Patient.hpp
//  3
//
//  Created by Vincent Yu on 2/11/18.
//  Copyright © 2018 Vincent Yu. All rights reserved.
//

#ifndef Patient_h
#define Patient_h

#include "Person.h"
#include "Doctor.h"

class Patient : public Person{
public:
    Patient();
    Patient(std::string name, Doctor thePhysician);
    Patient(Patient &a);
    
    void setPhysician(Doctor newPhysician);
    Doctor getPhysician();
    
    Patient& operator =(const Patient &a);
    
private:
    Doctor physician;
};


#endif /* Patient_hpp */
