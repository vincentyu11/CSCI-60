//
//  1.cpp
//  1
//
//  Created by Vincent Yu on 1/28/18.
//  Copyright © 2018 Vincent Yu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;



int main() {
    int num;
    vector<int> suitor;
    
    cout <<"Enter how many suitors: " <<endl;
    cin >> num;
    
    for (int i=1; i<num+1; i++){
        suitor.push_back(i);
    }
    
    for (int i=0; i<suitor.size(); i++) {
        cout << suitor[i];
    }
    cout <<endl;
    
    int n = 2;
    while (suitor.size()>0) {
        if (n<suitor.size()) {
            suitor.erase(suitor.begin()+n);
            for (int i=0; i<suitor.size(); i++) {
                cout << suitor[i];
            }
            cout <<endl;
            n = n+2;
        }
        if (n>suitor.size()-1) {
            while (n>suitor.size()-1) {
                n=n-suitor.size();
            }
            suitor.erase(suitor.begin()+n);
            for (int i=0; i<suitor.size(); i++) {
                cout << suitor[i];
            }
            cout <<endl;
            n = n+2;
        }
    }
    return 0;
}
