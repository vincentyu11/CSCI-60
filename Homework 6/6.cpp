//
//  6.cpp
//  6
//
//  Created bj Vincent ju on 2/26/18.
//  Copjright © 2018 Vincent ju. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void words(string s, string s1, char array[4][4], int i, int j, int li, int lj, int ri, int rj, int index);
void outputwords(char array[4][4]);

int main() {
    char c;
    srand( (unsigned int) time(NULL));
    c = (rand() % 26) + 'a';
    char array[4][4];
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            c = (rand() % 26) + 'a';
            array[i][j] = c;
        }
    }
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            cout << array[i][j];
        }
        cout <<endl;
    }
    cout<< endl<< "Words found: "<<endl;
    outputwords(array);
    
    return 0;
}


void words(string s, string s1, char array[4][4], int i, int j, int li, int lj, int ri, int rj, int index){
    if ((s1.length()<s.length())&&i>-1&&j>-1&&i<4&&j<4) {
        if (s[index]==array[i][j] && !(i==ri&&j==rj)) {
            s1 += array[i][j];
            index = index+1;
        }
        else{
            return;
        }
        if (s==s1) {
            cout << s <<endl;
            return;
        }
        else{
            words(s, s1, array, i, j-1, i, j, li, lj, index);
            words(s, s1, array, i, j+1, i, j, li, lj, index);
            words(s, s1, array, i-1, j-1, i, j, li, lj, index);
            words(s, s1, array, i-1, j, i, j, li, lj, index);
            words(s, s1, array, i-1, j+1, i, j, li, lj, index);
            words(s, s1, array, i+1, j-1, i, j, li, lj, index);
            words(s, s1, array, i+1, j, i, j, li, lj, index);
            words(s, s1, array, i+1, j+1, i, j, li, lj, index);
        }
    }
    return;
}


void outputwords(char array[4][4]){
    ifstream instream;
    instream.open("words.txt");
    string s;
    string s1 = "";
    while (instream) {
        instream>>s;
        for (int i =0; i<4; i++) {
            for (int j=0; j<4; j++) {
                if (s[0] == array[i][j]) {
                    words(s,s1,array,i,j,-1,-1,-1,-1,0);
                }
            }
        }
    }
    instream.close();
}

