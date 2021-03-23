//
//  Node.hpp
//  3
//
//  Created by Vincent Yu on 3/12/18.
//  Copyright © 2018 Vincent Yu. All rights reserved.
//

#ifndef node_h
#define node_h
#include <iostream>

using namespace std;

class Node
{
public:
    Node();
    Node(int coefficient, int exponent);
    Node(int coefficient, int exponent, Node *next);
    int getCoefficient() const;
    int getExponent() const;
    Node *getLink() const {return link_;}
    void setCoefficient(int coefficient);
    void setExponent(int exponent);
    void setLink(Node *link);
private:
    int coefficient_;
    int exponent_;
    Node *link_;
};

#endif /* Node_hpp */
