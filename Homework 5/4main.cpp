//
//  main.cpp
//  4
//
//  Created by Vincent Yu on 2/21/18.
//  Copyright © 2018 Vincent Yu. All rights reserved.
//

#include "dsa.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    int array[4] = {1,2,3,4};
    int size = 4;
    DynamicStringArray<int,int> a(array,size);
    
    cout << a.getsize() <<endl;
    cout << a.getEntry(0) <<endl;
    
    DynamicStringArray<int, int> b(a);
    b.addEntry(0);
    cout << b.getsize() <<endl;
    for (int i=0; i<b.getsize(); i++) {
        cout << a.getEntry(i) << " ";
    }
    cout << endl;
    b.deleteEntry(0);
    cout << b.getsize() <<endl;
    for (int i=0; i<b.getsize(); i++) {
        cout << a.getEntry(i) << " ";
    }
    cout << endl;
    return 0;
}
