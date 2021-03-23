//
//  2.cpp
//  2
//
//  Created by Vincent Yu on 1/28/18.
//  Copyright © 2018 Vincent Yu. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Zipcode{
public:
    Zipcode() = default;
    Zipcode(int digits);
    Zipcode(string bars);
    
    void inputzip(int digits);
    void inputzip(string bars);
    
    int getDigits()const;
    string getBars()const;
    
    int barToDigit(string bars)const;
    string digitToBar(int digits)const;
private:
    string barcode;
};



int main() {
    Zipcode one(85129);
    cout << one.getBars() <<endl;
    Zipcode two;
    two.inputzip("11010011000100010110000110000111");
    cout << two.getDigits() <<endl;
    
    return 0;
}




Zipcode::Zipcode(int digits){
    barcode = digitToBar(digits);
}

Zipcode::Zipcode(string bars){
    barcode = bars;
}

void Zipcode::inputzip(int digits){
    barcode = digitToBar(digits);
}

void Zipcode::inputzip(string bars){
    barcode = bars;
}

int Zipcode::getDigits()const{
    return barToDigit(barcode);
}

string Zipcode::getBars()const{
    return barcode;
}

string Zipcode::digitToBar(int digits)const{
    string bars = "100000000000000000000000001";
    int a = digits/10000;
    int b = (digits - (a*10000))/1000;
    int c = (digits - (a*10000)-(b*1000))/100;
    int d = (digits - (a*10000)-(b*1000)-(c*100))/10;
    int e = (digits - (a*10000)-(b*1000)-(c*100)-(d*10))/1;
    int array[5] = {a,b,c,d,e};
    int counter = 1;
    for (int i=0; i<5; i++) {
        if (array[i] == 0) {
            for (int j=1; j<=5; j++) {
                if (j == 1) {
                    bars.replace(counter,1,"1");
                    counter++;
                }
                if (j == 2) {
                    bars.replace(counter,1,"1");
                    counter++;
                }
                if (j == 3) {
                    bars.replace(counter,1,"0");
                    counter++;
                }
                if (j == 4) {
                    bars.replace(counter,1,"0");
                    counter++;
                }
                if (j == 5) {
                    bars.replace(counter,1,"0");
                    counter++;
                }
            }
        }
        if (array[i] == 1) {
            for (int j=1; j<=5; j++) {
                if (j == 1) {
                    bars.replace(counter,1,"0");
                    counter++;
                }
                if (j == 2) {
                    bars.replace(counter,1,"0");
                    counter++;
                }
                if (j == 3) {
                    bars.replace(counter,1,"0");
                    counter++;
                }
                if (j == 4) {
                    bars.replace(counter,1,"1");
                    counter++;
                }
                if (j == 5) {
                    bars.replace(counter,1,"1");
                    counter++;
                }
            }
        }
        if (array[i] == 2) {
            for (int j=1; j<=5; j++) {
                if (j == 1) {
                    bars.replace(counter,1,"0");
                    counter++;
                }
                if (j == 2) {
                    bars.replace(counter,1,"0");
                    counter++;
                }
                if (j == 3) {
                    bars.replace(counter,1,"1");
                    counter++;
                }
                if (j == 4) {
                    bars.replace(counter,1,"0");
                    counter++;
                }
                if (j == 5) {
                    bars.replace(counter,1,"1");
                    counter++;
                }
            }
        }
        if (array[i] == 3) {
            for (int j=1; j<=5; j++) {
                if (j == 1) {
                    bars.replace(counter,1,"0");
                    counter++;
                }
                if (j == 2) {
                    bars.replace(counter,1,"0");
                    counter++;
                }
                if (j == 3) {
                    bars.replace(counter,1,"1");
                    counter++;
                }
                if (j == 4) {
                    bars.replace(counter,1,"1");
                    counter++;
                }
                if (j == 5) {
                    bars.replace(counter,1,"0");
                    counter++;
                }
            }
        }
        if (array[i] == 4) {
            for (int j=1; j<=5; j++) {
                if (j == 1) {
                    bars.replace(counter,1,"0");
                    counter++;
                }
                if (j == 2) {
                    bars.replace(counter,1,"1");
                    counter++;
                }
                if (j == 3) {
                    bars.replace(counter,1,"0");
                    counter++;
                }
                if (j == 4) {
                    bars.replace(counter,1,"0");
                    counter++;
                }
                if (j == 5) {
                    bars.replace(counter,1,"1");
                    counter++;
                }
            }
        }
        if (array[i] == 5) {
            for (int j=1; j<=5; j++) {
                if (j == 1) {
                    bars.replace(counter,1,"0");
                    counter++;
                }
                if (j == 2) {
                    bars.replace(counter,1,"1");
                    counter++;
                }
                if (j == 3) {
                    bars.replace(counter,1,"0");
                    counter++;
                }
                if (j == 4) {
                    bars.replace(counter,1,"1");
                    counter++;
                }
                if (j == 5) {
                    bars.replace(counter,1,"0");
                    counter++;
                }
            }
        }
        if (array[i] == 6) {
            for (int j=1; j<=5; j++) {
                if (j == 1) {
                    bars.replace(counter,1,"0");
                    counter++;
                }
                if (j == 2) {
                    bars.replace(counter,1,"1");
                    counter++;
                }
                if (j == 3) {
                    bars.replace(counter,1,"1");
                    counter++;
                }
                if (j == 4) {
                    bars.replace(counter,1,"0");
                    counter++;
                }
                if (j == 5) {
                    bars.replace(counter,1,"0");
                    counter++;
                }
            }
        }
        if (array[i] == 7) {
            for (int j=1; j<=5; j++) {
                if (j == 1) {
                    bars.replace(counter,1,"1");
                    counter++;
                }
                if (j == 2) {
                    bars.replace(counter,1,"0");
                    counter++;
                }
                if (j == 3) {
                    bars.replace(counter,1,"0");
                    counter++;
                }
                if (j == 4) {
                    bars.replace(counter,1,"0");
                    counter++;
                }
                if (j == 5) {
                    bars.replace(counter,1,"1");
                    counter++;
                }
            }
        }
        if (array[i] == 8) {
            for (int j=1; j<=5; j++) {
                if (j == 1) {
                    bars.replace(counter,1,"1");
                    counter++;
                }
                if (j == 2) {
                    bars.replace(counter,1,"0");
                    counter++;
                }
                if (j == 3) {
                    bars.replace(counter,1,"0");
                    counter++;
                }
                if (j == 4) {
                    bars.replace(counter,1,"1");
                    counter++;
                }
                if (j == 5) {
                    bars.replace(counter,1,"0");
                    counter++;
                }
            }
        }
        if (array[i] == 9) {
            for (int j=1; j<=5; j++) {
                if (j == 1) {
                    bars.replace(counter,1,"1");
                    counter++;
                }
                if (j == 2) {
                    bars.replace(counter,1,"0");
                    counter++;
                }
                if (j == 3) {
                    bars.replace(counter,1,"1");
                    counter++;
                }
                if (j == 4) {
                    bars.replace(counter,1,"0");
                    counter++;
                }
                if (j == 5) {
                    bars.replace(counter,1,"0");
                    counter++;
                }
            }
        }
    }
    return bars;
}

int Zipcode::barToDigit(string bars)const{
    int digits = 0;
    int counter = 1;
    int a,b,c,d,e;
    if ((counter > 0) && (counter <= 5)) {
        for (int i=1; i<=5; i++) {
            if (i == 1) {
                a = (bars.at(counter)-'0')*7;
                counter++;
            }
            if (i == 2) {
                b = (bars.at(counter)-'0')*4;
                counter++;
            }
            if (i == 3) {
                c = (bars.at(counter)-'0')*2;
                counter++;
            }
            if (i == 4) {
                d = (bars.at(counter)-'0')*1;
                counter++;
            }
            if (i == 5) {
                e = (bars.at(counter)-'0')*0;
                counter++;
            }
        }
    }
    if ((a+b+c+d+e)>9) {
        digits = digits + 0;
    }
    else {
        digits = digits + ((a+b+c+d+e)*10000);
    }
    if ((counter > 5) && (counter <= 10)) {
        for (int i=1; i<=5; i++) {
            if (i == 1) {
                a = (bars.at(counter)-'0' )*7;
                counter++;
            }
            if (i == 2) {
                b = (bars.at(counter)-'0' )*4;
                counter++;
            }
            if (i == 3) {
                c = (bars.at(counter)-'0' )*2;
                counter++;
            }
            if (i == 4) {
                d = (bars.at(counter)-'0' )*1;
                counter++;
            }
            if (i == 5) {
                e = (bars.at(counter)-'0' )*0;
                counter++;
            }
        }
    }
    if ((a+b+c+d+e)>9) {
        digits = digits + 0;
    }
    else {
        digits = digits + ((a+b+c+d+e)*1000);
    }
    if ((counter > 10) && (counter <= 15)) {
        for (int i=1; i<=5; i++) {
            if (i == 1) {
                a = (bars.at(counter)-'0' )*7;
                counter++;
            }
            if (i == 2) {
                b = (bars.at(counter)-'0' )*4;
                counter++;
            }
            if (i == 3) {
                c = (bars.at(counter)-'0' )*2;
                counter++;
            }
            if (i == 4) {
                d = (bars.at(counter)-'0' )*1;
                counter++;
            }
            if (i == 5) {
                e = (bars.at(counter)-'0' )*0;
                counter++;
            }
        }
    }
    if ((a+b+c+d+e)>9) {
        digits = digits + 0;
    }
    else {
        digits = digits + ((a+b+c+d+e)*100);
    }
    if ((counter > 15) && (counter <= 20)) {
        for (int i=1; i<=5; i++) {
            if (i == 1) {
                a = (bars.at(counter)-'0' )*7;
                counter++;
            }
            if (i == 2) {
                b = (bars.at(counter)-'0' )*4;
                counter++;
            }
            if (i == 3) {
                c = (bars.at(counter)-'0' )*2;
                counter++;
            }
            if (i == 4) {
                d = (bars.at(counter)-'0' )*1;
                counter++;
            }
            if (i == 5) {
                e = (bars.at(counter)-'0' )*0;
                counter++;
            }
        }
    }
    if ((a+b+c+d+e)>9) {
        digits = digits + 0;
    }
    else {
        digits = digits + ((a+b+c+d+e)*10);
    }
    if ((counter > 20) && (counter <= 25)) {
        for (int i=1; i<=5; i++) {
            if (i == 1) {
                a = (bars.at(counter)-'0' )*7;
                counter++;
            }
            if (i == 2) {
                b = (bars.at(counter)-'0' )*4;
                counter++;
            }
            if (i == 3) {
                c = (bars.at(counter)-'0' )*2;
                counter++;
            }
            if (i == 4) {
                d = (bars.at(counter)-'0' )*1;
                counter++;
            }
            if (i == 5) {
                e = (bars.at(counter)-'0' )*0;
                counter++;
            }
        }
    }
    if ((a+b+c+d+e)>9) {
        digits = digits + 0;
    }
    else {
        digits = digits + ((a+b+c+d+e)*1);
    }
    return digits;
}
