//
//  3.cpp
//  3
//
//  Created by Vincent Yu on 1/28/18.
//  Copyright © 2018 Vincent Yu. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;


class Money{
public:
    Money();
    Money(double amount);
    Money(int theDollars, int theCents);
    Money(int theDollars);
    double getAmount( ) const;
    int getDollars( ) const;
    int getCents( ) const;
    friend const Money operator +(const Money& amount1, const Money& amount2);
    friend const Money operator -(const Money& amount1, const Money& amount2);
    friend bool operator ==(const Money& amount1, const Money& amount2);
    friend const Money operator -(const Money& amount);
    friend ostream& operator <<(ostream& outputStream, const Money& amount);
    friend istream& operator >>(istream& inputStream, Money& amount);
    friend bool operator <(const Money &amount1, const Money &amount2);
    friend bool operator <=(const Money &amount1, const Money &amount2);
    friend bool operator >(const Money &amount1, const Money &amount2);
    friend bool operator >=(const Money &amount1, const Money &amount2);
    const Money percent(int percentFigure) const;
private:
    int dollars, cents;
    int dollarsPart(double amount) const;
    int centsPart(double amount) const;
    int round(double number) const;
};


int main(){
    Money amount1(7000,99);
    cout << amount1.getAmount() <<endl;
    Money amount2(300);
    cout << (amount1<=amount2) <<endl;
    cout <<amount1.percent(30) <<endl;
    return 0;
}



Money::Money(){
    dollars = 0;
    cents = 0;
}

Money::Money(double amount){
    dollars = dollarsPart(amount);
    cents = centsPart(amount);
}

Money::Money(int theDollars){
    dollars = theDollars;
    cents = 0;
}

Money::Money(int theDollars, int theCents){
    dollars = theDollars;
    if (theCents > 99) {
        cents = theCents - 100;
        dollars = dollars + ((theCents - cents)/100);
    }
    else{
        cents = theCents;
    }
}

int Money::dollarsPart(double amount) const{
    return static_cast<int>(amount);
}

int Money::centsPart(double amount) const{
    return static_cast<int>(amount);
}

double Money::getAmount() const{
    return (dollars + cents*0.01);
}

ostream& operator <<(ostream& outputStream, const Money& amount){
    int absDollars = abs(amount.dollars);
    int absCents = abs(amount.cents);
    if (amount.dollars < 0 || amount.cents < 0){
        outputStream << "$-";
    }
    else{
        outputStream << '$';
    }
    outputStream << absDollars;
    if (absCents >= 10){
        outputStream << '.' << absCents;
    }
    else{
        outputStream << '.' << '0' << absCents;
    }
    return outputStream;
}

istream& operator >>(istream& inputStream, Money& amount){
    char dollarSign;
    inputStream >> dollarSign; //hopefully
    if (dollarSign != '$'){
        cout << "No dollar sign in Money input.\n";
        exit(1);
    }
    double amountAsDouble;
    inputStream >> amountAsDouble;
    amount.dollars = amount.dollarsPart(amountAsDouble);
    amount.cents = amount.centsPart(amountAsDouble);
    return inputStream;
}





bool operator <(const Money &amount1, const Money &amount2){
    return ((amount1.dollars < amount2.dollars) ||
            ((amount1.dollars == amount2.dollars) &&
             (amount1.cents < amount2.cents)));
}

bool operator <=(const Money &amount1, const Money &amount2){
    return (((amount1.dollars < amount2.dollars) ||
            ((amount1.dollars == amount2.dollars) &&
             (amount1.cents < amount2.cents))) ||
            ((amount1.dollars == amount2.dollars) && (amount1.cents == amount2.cents)));
}

bool operator >(const Money &amount1, const Money &amount2){
    return ((amount1.dollars > amount2.dollars) ||
            ((amount1.dollars == amount2.dollars) &&
             (amount1.cents > amount2.cents)));
}

bool operator >=(const Money &amount1, const Money &amount2){
    return (((amount1.dollars > amount2.dollars) ||
             ((amount1.dollars == amount2.dollars) &&
              (amount1.cents > amount2.cents))) ||
            ((amount1.dollars == amount2.dollars) && (amount1.cents == amount2.cents)));
}

const Money Money::percent(int percentFigure) const{
    Money newPercent;
    newPercent.dollars = dollars/percentFigure;
    newPercent.cents = cents/percentFigure;
    return newPercent;
}
















