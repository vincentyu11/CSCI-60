//
//  main.cpp
//  2
//
//  Created by Vincent Yu on 2/4/18.
//  Copyright © 2018 Vincent Yu. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    string a;
    cout << "Enter a string:" <<endl;
    cin >> a;
    int b = a.length();
    char string1[b];
    for (int i = 0; i < b; i++) {
        string1[i] = a.c_str()[i];
    }
    string1[b+1] = '\0';
    char *x, *y;
    char tempx, tempy;
    if ((b%2) == 0)  {
        for (int i=0; i<(b/2); i++) {
            x = &string1[i];
            y = &string1[b-i-1];
            tempx = string1[i];
            tempy = string1[b-i-1];
            *y = tempx;
            *x = tempy;
        }
    }
    if ((b%2) == 1) {
        for (int i=0; i<((b-1)/2); i++) {
            x = &string1[i];
            y = &string1[b-i-1];
            tempx = string1[i];
            tempy = string1[b-i-1];
            *y = tempx;
            *x = tempy;
        }
    }
    for (int i = 0; i<b; i++) {
        cout << string1[i];
    }
    cout <<endl;
    
    return 0;
}
