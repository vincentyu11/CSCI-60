//
//  1.cpp
//  1
//
//  Created by Vincent Yu on 2/25/18.
//  Copyright © 2018 Vincent Yu. All rights reserved.
//

#include <iostream>
using namespace std;

int fibonacci(int n);

int main() {
    cout << fibonacci(13    ) <<endl;
    return 0;
}

int fibonacci(int n){
    if (n==0 || n==1) {
        return 1;
    }
    else{
        return fibonacci(n-1)+fibonacci(n-2);
    }
}
