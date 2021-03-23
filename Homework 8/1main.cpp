//
//  main.cpp
//  1
//
//  Created by Vincent Yu on 3/11/18.
//  Copyright © 2018 Vincent Yu. All rights reserved.
//

#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node* link;
};

Node* input(Node* head,int data);
void output(Node* head);
Node* reverse(Node* head);

int main() {
    int size;
    int element;
    Node* head = nullptr;
    cout <<"Enter the number of elements in the linked list:" <<endl;
    cin >> size;
    cout<< "Enter " <<size << " elements:" <<endl;
    for (int i =0; i<size; i++) {
        cin>>element;
        head = input(head, element);
    }
    output(head);
    cout <<endl;
    head = reverse(head);
    output(head);
    
    return 0;
}

Node* input(Node* head,int data){
    if (head==nullptr) {
        Node* temp = (Node*)malloc(sizeof(Node));
        temp->data=data;
        temp->link=nullptr;
        head=temp;
    }
    else{
        Node* temp = (Node*)malloc(sizeof(Node));
        temp->data=data;
        temp->link=head;
        head=temp;
    }
    return head;
}

void output(Node* head){
    Node* temp=head;
    while (temp!=nullptr) {
        cout<< temp->data<<" ";
        temp=temp->link;
    }
}

Node* reverse(Node* head){
    Node* a = nullptr;
    Node* b = nullptr;
    Node* c = head;
    if (head->link == nullptr) {
        return head;
    }
    while (c) {
        a=b;
        b=c;
        c=c->link;
        b->link=a;
    }
    return b;
}








