//
//  1.cpp
//  2
//
//  Created by Vincent Yu on 1/18/18.
//  Copyright © 2018 Vincent Yu. All rights reserved.
//

#include <iostream>
using namespace std;

class Point{
private:
    int x;
    int y;
public:
    void setx(int newx);
    void sety(int newy);
    void movePoint(int amount1, int amount2);
    void rotatePoint90();
    const int getx();
    const int gety();
    
};

int main() {
    Point set1;
    int input1, input2, move1, move2;
    cout << "Enter an x coordinate:" <<endl;
    cin >> input1;
    cout << "Enter a y coordinate:" <<endl;
    cin >> input2;
    set1.setx(input1);
    set1.sety(input2);
    cout << set1.getx() << "," << set1.gety() <<endl;
    cout << "Enter an amount to move the x coordinate:" <<endl;
    cin >>move1;
    cout << "Enter an amount to move the y coordinate:" <<endl;
    cin >>move2;
    set1.movePoint(move1, move2);
    cout << set1.getx() << "," << set1.gety() <<endl;
    set1.rotatePoint90();
    cout << set1.getx() << "," << set1.gety() <<endl;

    return 0;
}

void Point::setx(int newx){
    x = newx;
}

void Point::sety(int newy){
    y = newy;
}

void Point::movePoint(int amount1, int amount2){
    x = x + amount1;
    y = y + amount2;
}

void Point::rotatePoint90(){
    int temp = x;
    x = y;
    y = temp * -1;
}

const int Point::getx(){
    return x;
}

const int Point::gety(){
    return y;
}

