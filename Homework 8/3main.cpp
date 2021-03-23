//
//  main.cpp
//  3
//
//  Created by Vincent Yu on 3/12/18.
//  Copyright © 2018 Vincent Yu. All rights reserved.
//

#include <iostream>
#include "polynomial.h"
using namespace std;

//enter polynomials in this format, with spaces:
//ex: 2x^4 + 6x^5 - 7x^9
int main()
{
    Polynomial a, b, c;
    int x,y;
    a.input();
    b.input();
    cout<< "A= ";
    a.output();
    cout<<endl;
    cout<< "B= ";
    b.output();
    cout<<endl;
    
    cout<<"Enter a number to evaluate A:" <<endl;
    cin>>x;
    cout << "A at x = " <<x <<": "<< a.evaluate(x) << endl;
    cout<<"Enter a number to evaluate B:" <<endl;
    cin>>y;
    cout << "B at x = " <<y <<": "<< b.evaluate(y) << endl;
    cout<<endl;
    
    c = *(a + b);
    cout << "A + B = ";
    c.output();
    cout << endl;
    
    c = *(a - b);
    cout << "A - B = ";
    c.output();
    cout << endl;
    
    c = *(a * b);
    cout << "A * B = ";
    c.output();
    cout << endl;
    
    return 0;
}

