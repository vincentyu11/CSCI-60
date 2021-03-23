//
//  polynomial.cpp
//  3
//
//  Created by Vincent Yu on 3/12/18.
//  Copyright © 2018 Vincent Yu. All rights reserved.
//

#include "polynomial.h"
#include <iostream>
#include <cstring>
#include <cmath>
#include <stdlib.h>
#include <vector>

using namespace std;

Polynomial::Polynomial() {
    head = nullptr;
}

Polynomial::Polynomial(int constant) {
    head = new Node(constant, 0);
}

Polynomial::Polynomial(int coeffcient, int exponent) {
    head = new Node(coeffcient, exponent);
}

Polynomial::Polynomial(const Polynomial & polynomial) {
    head = polynomial.head;
}

Polynomial::~Polynomial() {
    delete head;
}

double Polynomial::evaluate(double x){
    double result = 0;
    Node *current = head;
    while(current != nullptr){
        result+=(current->getCoefficient()*pow(x,current->getExponent()));
        current = current->getLink();
    }
    return result;
}

void Polynomial::input(){
    vector<string> tokens;
    string line, str, coefstr, expstr, sign;
    int coeff, exp, a;
    string dummy;
    cout << "Enter a polynomial" << endl;
    getline(cin, line);
    string temp = line;
    while(temp.length() > 0){
        str = temp.substr(0, temp.find(" "));
        tokens.push_back(str);
        if(temp.find(" ") == -1){
            break;
        }
        temp = temp.substr(temp.find(" ") + 1);
    }
    for(unsigned int i = 0; i < tokens.size(); i++){
        str = tokens[i];
        sign = "";
        if(str.length() == 1){
            sign = str;
            i++;
            str = tokens[i];
        }
        if(str.find('^') > 1){
            coefstr = str.substr(0, str.find('*') - 1);
            coeff = atoi(coefstr.c_str());
        }
        else{
            coeff = 1;
        }
        sign = sign + "1";
        a = atoi(sign.c_str());
        coeff *= a;
        if(str.find('^') != -1){
            expstr = str.substr(str.find('^') + 1);
            exp = atoi(expstr.c_str());
        }
        else{
            exp = 0;
        }
        insert(coeff,exp);
    }
    cout << endl;
}

void Polynomial::output(){
    Node *current = head;
    while(current != nullptr){
        if(current->getCoefficient() != 0){
            if(current != head && current->getCoefficient() > 0){
                cout << "+";
            }
            if(current->getCoefficient() == -1){
                cout << "-";
            }
            if(current->getCoefficient() != 1){
                if(current->getCoefficient() != -1){
                    cout << current->getCoefficient();
                }
            }
            if(current->getExponent() != 0){
                cout << "x^" << current->getExponent();
            }
            else if(current->getExponent() == 0 && (current->getCoefficient() == -1 || current->getCoefficient() == 1)){
                cout << "1";
            }
        }
        current = current->getLink();
    }
    cout << endl;
}

void Polynomial::insert(int coefficient, int exponent){
    Node *node = new Node(coefficient, exponent);
    if(head == nullptr){
        head = new Node(coefficient, exponent);
    }
    else{
        Node *current = head;
        Node *prev = nullptr;
        while(current != nullptr){
            prev = current;
            current = current->getLink();
        }
        prev->setLink(node);
    }
}

const Polynomial& Polynomial::operator =(const Polynomial &polynomial){
    delete head;
    Node *current = polynomial.head;
    if(current != nullptr){
        head = new Node(current->getCoefficient(),current->getExponent());
        current = current->getLink();
        Node *last = head;
        while(current != nullptr){
            last->setLink(new Node(current->getCoefficient(), current->getExponent()));
            current = current->getLink();
            last = last->getLink();
        }
    }
    return *this;
}


Polynomial* operator +(const Polynomial &polynomial1, const Polynomial &polynomial2){
    Polynomial *result = new Polynomial();
    Node *first = polynomial1.head;
    Node *second = polynomial2.head;
    while(first != nullptr && second != nullptr){
        if(first->getExponent() > second->getExponent()){
            result->insert(first->getCoefficient(), first->getExponent());
            first = first->getLink();
        }
        else if(first->getExponent() < second->getExponent()){
            result->insert(second->getCoefficient(), second->getExponent());
            second = second->getLink();
        }
        else{
            result->insert(first->getCoefficient() + second->getCoefficient(), first->getExponent());
            first = first->getLink();
            second = second->getLink();
        }
    }
    if(first == nullptr){
        while(second != nullptr){
            result->insert(second->getCoefficient(), second->getExponent());
            second = second->getLink();
        }
    }
    if(second == nullptr){
        while(first != nullptr){
            result->insert(first->getCoefficient(), first->getExponent());
            first = first->getLink();
        }
    }
    return result;
}

Polynomial* operator -(const Polynomial &polynomial1, const Polynomial &polynomial2){
    Polynomial *result = new Polynomial();
    Node *first = polynomial1.head;
    Node *second = polynomial2.head;
    while(first != nullptr && second != nullptr){
        if(first->getExponent() > second->getExponent()){
            result->insert(first->getCoefficient(), first->getExponent());
            first = first->getLink();
        }
        else if(first->getExponent() < second->getExponent()){
            result->insert(-1 * second->getCoefficient(), second->getExponent());
            second = second->getLink();
        }
        else{
            result->insert(first->getCoefficient() - second->getCoefficient(), first->getExponent());
            first = first->getLink();
            second = second->getLink();
        }
    }
    if(second == nullptr){
        while(first != nullptr){
            result->insert(first->getCoefficient(), first->getExponent());
            first = first->getLink();
        }
    }
    if(first == nullptr){
        while(second != nullptr){
            result->insert(-1 * second->getCoefficient(), second->getExponent());
            second = second->getLink();
        }
    }
    return result;
}

Polynomial* operator *(const Polynomial &polynomial1, const Polynomial &polynomial2){
    Polynomial *result = new Polynomial();
    Polynomial temp;
    Node *first = polynomial1.head;
    Node *second;
    while(first != nullptr){
        second = polynomial2.head;
        while(second != nullptr){
            temp.insert(first->getCoefficient() * second->getCoefficient(), first->getExponent() + second->getExponent());
            second = second->getLink();
        }
        result = (*result) + temp;
        first = first->getLink();
    }
    return result;
}



