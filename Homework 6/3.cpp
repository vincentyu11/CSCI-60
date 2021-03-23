//
//  3.cpp
//  3
//
//  Created by Vincent Yu on 2/26/18.
//  Copyright © 2018 Vincent Yu. All rights reserved.
//

#include <iostream>
using namespace std;

void tower(int n, char a, char b, char c);

int main() {
    tower(3, 'a', 'b', 'c');
    return 0;
}

void tower(int n, char a, char b, char c){
    if (n==1) {
        cout << "Move disk "<< n <<" from " <<a <<" to " << c <<endl;
        return;
    }
    else{
        tower(n-1, a, c, b);
        cout << "Move disk "<< n <<" from " <<a <<" to " << c <<endl;
        tower(n-1, b, a, c);
    }
}
