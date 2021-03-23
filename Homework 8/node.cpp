//
//  Node.cpp
//  3
//
//  Created by Vincent Yu on 3/12/18.
//  Copyright © 2018 Vincent Yu. All rights reserved.
//

#include "node.h"

Node::Node() {
    coefficient_ = 0; exponent_ = 0; link_ = nullptr;
}

Node::Node(int coefficient, int exponent){
    coefficient_ = coefficient;
    exponent_ = exponent;
    link_ = nullptr;
}

Node::Node(int coefficient, int exponent, Node *next){
    coefficient_ = coefficient;
    exponent_ = exponent;
    link_ = next;
}

int Node::getCoefficient() const{
    return coefficient_;
}

int Node::getExponent() const{
    return exponent_;
}

void Node::setCoefficient(int coefficient) {
    coefficient_ = coefficient;
}

void Node::setExponent(int exponent) {
    exponent_ = exponent;
}

void Node::setLink(Node *link) {
    link_ = link;
}


