//
//  1.cpp
//  1
//
//  Created by Vincent Yu on 2/20/18.
//  Copyright © 2018 Vincent Yu. All rights reserved.
//

#include <iostream>
using namespace std;

const int ARRAY_SIZE = 10;

//T1 specification: int, long, short, double, string, char, bool --- can input an array of these types, and search for the key of these types
//T2 specification: int, long, short --- position of element can only be a number
template <typename T1, typename T2>
void search(const T1 a[], T2 first, T2 last, T1 key, bool& found, int& location){
    if (first > last){
        found = false;
    }
    T1 mid = (first+last)/2;
    while (key >= a[first] && key <= a[last] && key != a[mid]) {
        if (key > a[mid]) {
            first = mid +1;
            mid = (first+last)/2;
        }
        else if (key < a[mid]){
            last = mid -1;
            mid = (first+last)/2;
        }
        if (key == a[mid]) {
            found = true;
            mid = (first+last)/2;
            location = mid;
        }
    }
}


int main() {
    int array[ARRAY_SIZE] = {1,3,5,7,9,11,13,15,17,19};
    bool found;
    int location;
    int first = 0;
    int last = ARRAY_SIZE -1;
    search(array,first,last,19,found,location);
    if (found) {
        cout << "Found in location: " <<location <<endl;
    }
    if (!found) {
        cout << "Not found" <<endl;
    }
    
    return 0;
}

