//
//  5.cpp
//  5
//
//  Created by Vincent Yu on 2/26/18.
//  Copyright © 2018 Vincent Yu. All rights reserved.
//

#include <iostream>
using namespace std;

int fibonacci(int n);

int main() {
    cout << fibonacci(9) <<endl;
    
    return 0;
}

int fibonacci(int n){
    int array[n+1];
    array[0] = 1;
    array[1] = 1;
    for (int i =2; i<=n; i++) {
        array[i] = array[i-1] + array[i-2];
    }
    return array[n];
}
