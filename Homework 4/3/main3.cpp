//
//  main.cpp
//  3
//
//  Created by Vincent Yu on 2/11/18.
//  Copyright © 2018 Vincent Yu. All rights reserved.
//

#include <iostream>
#include "Patient.h"
#include "Billing.h"
using namespace std;

int main() {
    Doctor a = Doctor("Thomas", "87493852", 50031.77, "Surgeon", 1123.16);
    Doctor b = Doctor("Mandy", "234197112", 1655.99, "Pediatrician", 900.75);
    Patient c("Jessy", a);
    Patient d("Bobby", b);
    
    Billing firstbill(c, a, 2986.45);
    Billing secondbill(d, b, 712.50);
    
    cout <<"Total amount due: $" <<firstbill.getAmountDue()+secondbill.getAmountDue() <<endl;
    
    firstbill.setAmountDue(1430.99);
    
    cout <<"Total amount due: $" <<firstbill.getAmountDue()+secondbill.getAmountDue() <<endl;
    
    return 0;
}
