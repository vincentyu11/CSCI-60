//
//  1.cpp
//  1
//
//  Created by Vincent Yu on 1/18/18.
//  Copyright © 2018 Vincent Yu. All rights reserved.
//

#include <iostream>
using namespace std;

class CounterType{
public:
    int count;
    CounterType();
    CounterType(int newCount);
    void setcount(int newCount);
    int getCount();
    int output();
    void increase();
    void decrease();
};

int main() {
    CounterType count1;
    count1.output();
    count1.setcount(5);
    count1.increase();
    count1.increase();
    count1.decrease();
    count1.output();
    count1.setcount(10);
    count1.output();
    
    return 0;
}


CounterType::CounterType(){
    count = 0;
}

CounterType::CounterType(int newCount){
    count = newCount;
}

void CounterType::setcount(int newCount){
    count = newCount;
}

int CounterType::getCount(){
    return count;
}

int CounterType::output(){
    cout << count <<endl;
    return 1;
}

void CounterType::increase(){
    count = count + 1;
}

void CounterType::decrease(){
    if (count > 1) {
        count = count - 1;
    }
    if (count < 1) {
        count = 0;
    }
}

