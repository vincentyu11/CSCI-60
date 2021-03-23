//
//  human.cpp
//  self
//
//  Created by Vincent Yu on 2/23/18.
//  Copyright © 2018 Vincent Yu. All rights reserved.
//

class Human{
public:
    Human();
    Human(int theheight, int theage);
    void setheight(int theheight);
    void setage(int theage);
    int getheight();
    int getage();
private:
    int height;
    int age;
};

Human::Human(){
    height = 0;
    age = 0;
}

Human::Human(int theheight, int theage){
    height = theheight;
    age = theage;
}

void Human::setheight(int theheight){
    height = theheight;
}

void Human::setage(int theage){
    age = theage;
}

int Human::getheight(){
    return height;
}

int Human::getage(){
    return age;
}
