//
//  Billing.hpp
//  3
//
//  Created by Vincent Yu on 2/12/18.
//  Copyright © 2018 Vincent Yu. All rights reserved.
//

#ifndef Billing_h
#define Billing_h

#include "Patient.h"
#include "Doctor.h"

class Billing{
public:
    Billing();
    Billing(Patient thePatient, Doctor theDoctor, double theAmountDue);
    Billing(Billing &a);
    
    void setAmountDue(double newAmountDue);
    double getAmountDue();
    
    Billing& operator =(const Billing &a);
private:
    Patient patient;
    Doctor doctor;
    double amountdue;
};


#endif /* Billing_hpp */
