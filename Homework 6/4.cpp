//
//  4.cpp
//  4
//
//  Created by Vincent Yu on 2/26/18.
//  Copyright © 2018 Vincent Yu. All rights reserved.
//

#include <iostream>
using namespace std;

int fibonacci(int n);

int main() {
    cout << fibonacci(159) <<endl;
    
    return 0;
}

int fibonacci(int n){
    int a=0;
    int b=1;
    int c=0;
    if (n==0 || n==1) {
        return 1;
    }
    for (int i=1; i<=n; i++) {
        c=a+b;
        a=b;
        b=c;
    }
    return c;
}

//time to compute fibonacci number takes longer for recursive function as the number goes up
