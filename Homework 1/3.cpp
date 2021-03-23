//
//  3.cpp
//  3
//
//  Created by Vincent Yu on 1/18/18.
//  Copyright © 2018 Vincent Yu. All rights reserved.
//


#include <iostream>
using namespace std;

class GasPump{
private:
    double costPerGallon = 2.99;
    double amountDispensed = 0;
    double price = 0;
public:
    void reset();
    double getPrice();
    double getAmountDispensed();
    double getCostPG();
    void pumpGallon(double gallons);
    void addPrice(double gallons);
};

int main(){
    GasPump scenario1;
    char initiation;
    cout <<"Enter 'S' to start pumping gas." <<endl;
    cin >> initiation;
    
    while (initiation != 'Q') {
        if (initiation == 'S' || initiation == 'R') {
            double input;
            cout <<"Enter how many gallons of gas to pump." <<endl;
            cin >> input;
            scenario1.pumpGallon(input);
            scenario1.addPrice(input);
            cout <<"Amount Dispensed: " <<scenario1.getAmountDispensed() <<endl;
            cout <<"Price per gallon: " <<scenario1.getCostPG() <<endl;
            cout <<"Amount of money due: " <<scenario1.getPrice() <<endl;
            cout <<"Enter 'S' to pump more gas or 'R' to reset or 'Q' to quit." <<endl;
            cin >> initiation;
            if (initiation == 'R') {
                scenario1.reset();
            }
        }
    }
    if (initiation == 'Q') {
        exit(1);
    }
    return 0;
}

void GasPump::reset(){
    amountDispensed = 0;
    price = 0;
}

double GasPump::getPrice(){
    return price;
}

double GasPump::getAmountDispensed(){
    return amountDispensed;
}

double GasPump::getCostPG(){
    return costPerGallon;
}

void GasPump::pumpGallon(double gallons){
    amountDispensed = amountDispensed + gallons;
}

void GasPump::addPrice(double gallons){
    price = price + (costPerGallon*gallons);
}
