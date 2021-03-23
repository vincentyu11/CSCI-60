//
//  Billing.cpp
//  3
//
//  Created by Vincent Yu on 2/12/18.
//  Copyright © 2018 Vincent Yu. All rights reserved.
//

#include "Billing.h"

Billing::Billing() :amountdue(0){
    //deliberately empty
}

Billing::Billing(Patient thePatient, Doctor theDoctor, double theAmountDue)
    : patient(thePatient),doctor(theDoctor),amountdue(theAmountDue){
    //deliberately empty
}

Billing::Billing(Billing &a){
    patient = a.patient;
    doctor = a.doctor;
    amountdue = a.amountdue;
}

void Billing::setAmountDue(double newAmountDue){
    amountdue = newAmountDue;
}

double Billing::getAmountDue(){
    return amountdue;
}

Billing& Billing::operator =(const Billing &a){
    patient = a.patient;
    doctor = a.doctor;
    amountdue = a.amountdue;
    return *this;
}
