//
//  3.cpp
//  3
//
//  Created by Vincent Yu on 2/4/18.
//  Copyright © 2018 Vincent Yu. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstdlib>

class Student{
public:
    Student();
    ~Student();
    void input();
    void output();
    void resetClass();
    
    std::string getName()const;
    int getNumClasses()const;
    std::string* getClassList()const;
    
    void operator =(const Student& newcopy);
private:
    std::string name;
    int numClasses;
    std::string *classList;
};


#include <iostream>
using namespace std;

int main() {
    Student one, two;
    one.input();
    one.output();
    two.input();
    two.output();
    Student three;
    three = one;
    three.output();
    one.resetClass();
    two.~Student();
    return 0;
}


Student::Student(){
    name = "";
    numClasses = 0;
    classList = NULL;
}

Student::~Student(){
    delete [] classList;
}

void Student::input(){
    resetClass();
    string fool;
    cout << "Enter student name:" <<endl;
    getline(cin, name);
    cout << "Enter number of classes: " <<endl;
    cin >>numClasses;
    getline(cin, fool);
    if (numClasses > 0) {
        classList = new string[numClasses];
        for (int i = 0; i< numClasses; i++) {
            cout << "Enter name of class: " <<endl;
            getline(cin, classList[i]);
        }
    }
    cout <<endl;
}

void Student::output(){
    cout << "Student name: " <<name <<endl;
    cout << "Number of classes: " <<numClasses <<endl;
    for (int i=0; i<numClasses; i++) {
        cout <<"Class " <<(i+1) <<": " << classList[i] <<endl;
    }
    cout<<endl;
}

void Student::resetClass(){
    numClasses = 0;
    delete [] classList;
}

string Student::getName()const{
    return name;
}

int Student::getNumClasses()const{
    return numClasses;
}

string* Student::getClassList()const{
    return classList;
}

void Student::operator =(const Student &newcopy){
    string *temp = newcopy.getClassList();
    name = newcopy.getName();
    numClasses = newcopy.getNumClasses();
    classList = new string[numClasses];
    for (int i=0; i<numClasses; i++) {
        classList[i] = temp[i];
    }
}
