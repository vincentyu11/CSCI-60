//
//  2.cpp
//  2
//
//  Created by Vincent Yu on 2/26/18.
//  Copyright © 2018 Vincent Yu. All rights reserved.
//

#include <iostream>
using namespace std;

int combination(int n, int r);

int main() {
    cout << combination(13, 5) <<endl;
    return 0;
}

int combination(int n, int r){
    if (r==0) {
        return 1;
    }
    else if (r==1){
        return n;
    }
    else if (r==n){
        return 1;
    }
    else{
        return combination(n-1, r) + combination(n-1, r-1);
    }
}
