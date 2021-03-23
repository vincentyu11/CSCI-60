//
//  1.cpp
//  1
//
//  Created by Vincent Yu on 2/4/18.
//  Copyright © 2018 Vincent Yu. All rights reserved.
//



//bag.h

#ifndef BAG_H//name of file all in caps, . becomes _
#define BAG_H

#include <cstdlib>
#include <cassert>
#include <algorithm>

// WANT: a class Bag to store a collection of ints
//       (multiple copies are allowed)
//       there is a FIXED limit on how many elements can be in a
//       Bag called CAPACITY (same for every Bag)

// Supported operations:
//        size (number of elements in Bag), count number of times
//        a value appears in Bag insert, delete, find


class Bag{
public:
    // CONSTANTS and TYPES
    
    typedef std::size_t size_type;
    //typedef int cat;
    //cat x;
    //using size_type = std::size_t;
    
    // known outside class as Bag::CAPACITY
    static const size_type CAPACITY = 1000;//Constant variables can't be changed, usually all caps
    
    // std::size_t is a pre-defined type for unsigned int
    // guaranteed to use the maximum storage allowed on
    // your machine
    
    // CONSTRUCTORS
    
    // pre: none
    // post: creates an initially empty Bag
    Bag();
    
    // pre: size tells us how many ints are in arr
    // post: creates an initially empty Bag
    Bag(int arr[], size_type size);
    
    // CONSTANT MEMBER FUNCTIONS
    
    // pre: none
    // post: returns the number of elements stored in this Bag
    size_type size() const;
    
    // pre: none
    // post: if target appears in this Bag, returns the number of times it appears
    //       else, returns 0
    size_type count(int target) const;
    
    // pre: none
    // post: returns the item at given pos
    int operator [](size_type pos) const{return data_[pos];}
    
    // MODIFICATION (MUTATOR) MEMBER FUNCTIONS
    
    // pre: size() < CAPACITY
    // post: a copy of target has been added to this Bag
    void insert(int target);
    
    // pre: size() + b.size() <= CAPACITY
    // post: adds a copy of each element of b to this Bag
    void operator += (const Bag & b);
    
    // pre: none
    // post: if target appears in this Bag, removes one copy of target and returns true
    //       else returns false
    bool erase_one(int target);
    
    // pre: none
    // post: if target appears in this Bag k times, removes all copies and returns k
    //       else returns 0
    size_type erase(int target);
    
private:
    
    int data_[CAPACITY];
    size_type  size_;
    
    // INVARIANTS:
    
    // data_[0], data_[1], ..., data_[size_-1] contain the elements in this Bag
    // don't care about values in data_[size_], ..., data_[CAPACITY-1]
    
};

// pre: b1.size() + b2.size() <= CAPACITY
// post: returns a Bag containing all elements in b1 and b2
Bag operator + (const Bag & b1, const Bag & b2);



#endif // BAG_H




//main.cpp

#include <iostream>
using namespace std;

int main(){
    Bag b;
    b.insert(5);
    b.insert(6);
    for (std::size_t i=0; i<b.size(); i++){
        cout<<b[i]<<" ";
    }
    cout<<endl;
    cout<<b.size()<<endl;
    
    return 0;
}




//bag.cpp

Bag::Bag(){
    size_ = 0;
}

Bag::Bag(int arr[], size_type size){
    for(size_type i = 0; i<size; i++){
        data_[i] = arr[i];
    }
    size_ = size;
}

Bag::size_type Bag::size() const{
    return size_;
}

Bag::size_type Bag::count(int target) const{//Need Bag::size_type because the typedef is only for the scope of Bag, and the return typpe of the function is outside that scope.  So this use of :: is more like std::size_t, not like Bag::count(...
    size_type count = 0;
    for(size_type i = 0; i<size_; i++){
        if(data_[i] == target)
            count++;
    }
    return count;
    
}

void Bag::insert(int target){
    if (size_ == 0) {
        size_ = 1;
        data_[0] = target;
    }
    else if (size_ < CAPACITY) {
        int arr[size_+1];
        for (int i=0; i<size_; i++) {
            arr[i] = data_[i];
        }
        arr[size_] = target;
        size_ = size_ +1;
        for (int j =0; j<size_; j++) {
            data_[j] = arr[j];
        }
    }
    else{
        cout << "Size will be greater than capacity. Exiting program" <<endl;
        exit(1);
    }
}



