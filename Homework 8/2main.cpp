//
//  main.cpp
//  2
//
//  Created by Vincent Yu on 3/11/18.
//  Copyright © 2018 Vincent Yu. All rights reserved.
//

#include <iostream>
using namespace std;

class Node{
public:
    Node(int num, Node* n);
    Node* getNext();
    int getData();
    void setNext(Node* n);
private:
    int data;
    Node *next;
    friend Node* mergeLists(Node* first, Node* second);
};

void input(Node* &list, int n);
void output(Node *third);
Node* mergeLists(Node* first, Node* second);

int main() {
    Node *first = nullptr;
    input(first, 1);
    input(first, 2);
    input(first, 9);
    input(first, 10);
    output(first);
    cout<<endl;
    Node *second = nullptr;
    input(second, 5);
    input(second, 6);
    input(second, 7);
    output(second);
    cout<<endl;
    Node* third = mergeLists(first, second);
    output(third);
    cout<< endl;
}



Node::Node(int num, Node* n){
    data = num;
    next = n;
}

Node* Node::getNext() {
    return next;
}

int Node::getData() {
    return data;
}

void Node::setNext(Node* n) {
    next = n;
}


void input(Node* &list, int n) {
    Node* current = list;
    if (current == nullptr) {
        list = new Node(n, nullptr);
        return;
    }
    
    while (current->getNext() != nullptr) {
        current = current->getNext();
    }
    current->setNext(new Node(n, nullptr));
}

void output(Node *third) {
    while(third != nullptr) {
        cout<< third->getData() <<" ";
        third=third->getNext();
    }
}


Node* mergeLists(Node* first, Node* second) {
    Node* product = nullptr;
    if(first == nullptr){
        return(second);
    }
    else if (second == nullptr){
        return(first);
    }
    if (first->data <= second->data){
        product = first;
        product->next = mergeLists(first->next, second);
    }
    else{
        product = second;
        product->next = mergeLists(first, second->next);
    }
    return(product);
}
