//
//  4.cpp
//  4
//
//  Created by Vincent Yu on 1/29/18.
//  Copyright © 2018 Vincent Yu. All rights reserved.
//

#ifndef BIGUINT_H
#define BIGUINT_H

#include <cstdlib>
#include <iostream>
#include <string>

// WANT: integers with CAPACITY digits, only non-negative
//
// support:
//    2 constructors: int, string
//    member functions:  [] returns individual digits given position
//                        +=
//                        -=
//                        compare: return +1, 0, -1, depending on
//                        whether this biguint >, ==, < than given biguint
//                        +, - (binary), - (unary), <, <=, ==, !=, >=, >
//                        <<, >>


class biguint
{
public:
    // CONSTANTS & TYPES
    
    static const std::size_t CAPACITY = 20;
    
    // CONSTRUCTORS
    
    // pre: none
    // post: creates a biguint with value 0
    biguint();
    
    // pre: s contains only decimal digits
    // post: creates a biguint whose value corresponds to given string of digits
    biguint(const std::string &);
    
    // CONSTANT MEMBER FUNCTIONS
    
    // pre: pos < CAPACITY
    // post: returns the digit at position pos
    //          0 is the least significant (units) position
    
    unsigned short operator [](std::size_t pos) const;
    
    // pre: none
    // post: returns 1 if this biguint > b
    //               0 if this biguint == b
    //              -1 if this biguint < b
    int compare(const biguint & b) const;
    
    
    
    // MODIFICATION MEMBER FUNCTIONS
    
    
    // pre: none
    // post: b is added to this biguint; ignore last carry bit if any
    void operator += (const biguint & b);
    void operator -= (const biguint & b);

    
private:
    
    unsigned short data_[CAPACITY];
    
    // INVARIANTS:
    //    data_[i] holds the i^th digit of this biguint or 0 if not used
    //    data_[0] holds the least significant (units) digit
};

// nonmember functions

biguint operator + (const biguint &, const biguint &);
biguint operator - (const biguint &, const biguint &);

bool operator < (const biguint &, const biguint &);
bool operator <= (const biguint &, const biguint &);
bool operator != (const biguint &, const biguint &);
bool operator == (const biguint &, const biguint &);
bool operator >= (const biguint &, const biguint &);
bool operator > (const biguint &, const biguint &);

std::ostream& operator <<(std::ostream&, const biguint &);


#endif // BIGUINT_H


#include <iostream>
using namespace std;

int main(){
    biguint z = biguint();
    
    string a;
    cout << "Enter a string" <<endl;
    cin >> a;
    biguint x = biguint(a);
    
    cout << x[3] <<endl;
    cout << x.compare(z) <<endl;
    cout << (x<z) <<endl;
    
    cout << x <<endl;
    
    biguint h = biguint("99999");
    biguint i = biguint("99999");
    h+=(i);
    cout << h <<endl;
    cout << h+i <<endl;
    
    return 0;
}



#include <cmath>

biguint::biguint(){
    for (int i=0; i<CAPACITY; i++){
        data_[i] = 0;
    }
}

biguint::biguint(const std::string &a){
    int j=0;
    for (int i=0; i<CAPACITY; i++){
        data_[i] = 0;
    }
    for (int i=(a.length()-1); j<CAPACITY && i>=0; --i){
        data_[j]=a[i] - '0';
        ++j;
    }
}

unsigned short biguint::operator [](std::size_t pos)const {
    int i;
    if (pos < CAPACITY){
        i = data_[pos];
    }
    return (i);
}

int biguint::compare(const biguint & b) const{
    int result;
    int x=0;
    int y=0;
    for (int i=0; i<20; i++){
        x = x + (data_[i]*(pow(10,i)));
    }
    for (int i=0; i<20; i++){
        y = y + (b[i]*(pow(10,i)));
    }
    if (x>y){
        result = 1;
    }
    if (x==y){
        result = 0;
    }
    if (x<y){
        result = -1;
    }
    return (result);
}

bool operator < (const biguint &a, const biguint &b){
    bool result;
    if (a.compare(b) == -1){
        result = true;
    }
    else {
        result = false;
    }
    return result;
}

bool operator <= (const biguint &a, const biguint &b){
    bool result;
    if ((a.compare(b) == -1) || (a.compare(b) == 0)){
        result = true;
    }
    else {
        result = false;
    }
    return result;
}

bool operator > (const biguint &a, const biguint &b){
    bool result;
    if (a.compare(b) == 1){
        result = true;
    }
    else {
        result = false;
    }
    return result;
}

bool operator >= (const biguint &a, const biguint &b){
    bool result;
    if ((a.compare(b) == 1) || (a.compare(b) == 0)){
        result = true;
    }
    else {
        result = false;
    }
    return result;
}

bool operator == (const biguint &a, const biguint &b){
    bool result;
    if (a.compare(b) == 0){
        result = true;
    }
    else {
        result = false;
    }
    return result;
}

bool operator != (const biguint &a, const biguint &b){
    bool result;
    if ((a.compare(b) == -1) || (a.compare(b) == 1)){
        result = true;
    }
    else {
        result = false;
    }
    return result;
}

std::ostream& operator <<(std::ostream&os, const biguint &b){
    int x=0;
    for (int i=0; i<20; i++){
        x = x + (b[i]*(pow(10,i)));
    }
    os << x;
    return os;
}

void biguint::operator += (const biguint & b){
    int add = 0;
    for (int i = 0; i< CAPACITY; i++) {
        int temp = data_[i];
        if (temp + b.data_[i] >= 10) {
            add = 1;
        }
        else{
            add = 0;
        }
        if ((b.data_[i] + temp) == 10) {
            data_[i] = 0;
            data_[i+1] = (data_[i+1] +add);
        }
        else if ((b.data_[i] + temp) > 10) {
            data_[i] = (b.data_[i] + temp)-10;
            data_[i+1] = (data_[i+1] +add);
        }
        else{
            data_[i] = ((b.data_[i] %10) + data_[i]) +add;
        }
    }
}

biguint operator + (const biguint &a, const biguint &b){
    biguint tempa = a;
    biguint tempb = b;
    tempa+=(tempb);
    return tempa;
}
