//
//  main.cpp
//  3
//
//  Created by Vincent Yu on 2/20/18.
//  Copyright © 2018 Vincent Yu. All rights reserved.
//

#include "itemset.h"
#include <iostream>
using namespace std;

int main() {
    int array[4] = {1,2,3,4};
    int size =4;
    Set<int> a(array,size);
    cout<< a.getsize() <<endl;
    a.add(21);
    a.add(123);
    cout<< a.getitem(2) <<endl;
    cout<< a.getitem(5) <<endl;
    
    return 0;
}
