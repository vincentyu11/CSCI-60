//
//  polynomial.hpp
//  3
//
//  Created by Vincent Yu on 3/12/18.
//  Copyright © 2018 Vincent Yu. All rights reserved.
//

#ifndef polynomial_hpp
#define polynomial_hpp

#include "node.h"
#include <iostream>
using namespace std;

class Polynomial{
public:
    Polynomial();
    ~Polynomial();
    Polynomial(int constant);
    Polynomial(int coefficient, int exponent);
    Polynomial(const Polynomial & polynomial);
    double evaluate(double x);
    void input();
    void output();
    void insert(int coefficient, int exponent);
    const Polynomial& operator =(const Polynomial &polynomial);
    friend Polynomial* operator +(const Polynomial &polynomial1, const Polynomial &polynomial2);
    friend Polynomial* operator -(const Polynomial &polynomial1, const Polynomial &polynomial2);
    friend Polynomial* operator *(const Polynomial &polynomial1, const Polynomial &polynomial2);
protected:
    Node *head;
};


#endif /* polynomial_hpp */
