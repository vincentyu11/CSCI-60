//
//  4.cpp
//  4
//
//  Created by Vincent Yu on 1/18/18.
//  Copyright © 2018 Vincent Yu. All rights reserved.
//

#include <iostream>
using namespace std;

class Month{
private:
    int month;
public:
    Month();
    Month(int number);
    Month(char a, char b, char c);
    void inputNum(int inputNum);
    void inputChar(char a, char b, char c);
    void outputNum();
    void outputChar();
    void nextMonth();
};

int main(){
    Month month1, month2, month3(12);
    int monthNum;
    char a, b, c;
    cout << "Enter a number of a month (1-12):" <<endl;
    cin >> monthNum;
    month1.inputNum(monthNum);
    month1.outputNum();
    month1.outputChar();

    cout << "Enter the first letter of the month:" <<endl;
    cin >> a;
    cout << "Enter the second letter of the month:" <<endl;
    cin >> b;
    cout << "Enter the third letter of the month:" <<endl;
    cin >> c;
    month2.inputChar(a, b, c);
    month2.outputNum();
    month2.outputChar();
   
    month3.nextMonth();
    month3.outputNum();
    month3.outputChar();
    
    return 0;
}

Month::Month(){
    month = 1;
}

Month::Month(int number){
    month = number;
}

Month::Month(char a, char b, char c){
    if (a == 'j' && b == 'a' && c == 'n'){
        month = 1;
    }
    else if (a == 'f' && b == 'e' && c == 'b'){
        month = 2;
    }
    else if (a == 'm' && b == 'a' && c == 'r'){
        month = 3;
    }
    else if (a == 'a' && b == 'p' && c == 'r'){
        month = 4;
    }
    else if (a == 'm' && b == 'a' && c == 'y'){
        month = 5;
    }
    else if (a == 'j' && b == 'u' && c == 'n'){
        month = 6;
    }
    else if (a == 'j' && b == 'u' && c == 'l'){
        month = 7;
    }
    else if (a == 'a' && b == 'u' && c == 'g'){
        month = 8;
    }
    else if (a == 's' && b == 'e' && c == 'p'){
        month = 9;
    }
    else if (a == 'o' && b == 'c' && c == 't'){
        month = 10;
    }
    else if (a == 'n' && b == 'o' && c == 'v'){
        month = 11;
    }
    else if (a == 'd' && b == 'e' && c == 'c'){
        month = 12;
    }
    else{
        cout << "Invalid combination of characters. Exiting program."<<endl;
        exit(1);
    }
}

void Month::inputNum(int inputNum){
    month = inputNum;
}

void Month::inputChar(char a, char b, char c){
    if (a == 'j' && b == 'a' && c == 'n'){
        month = 1;
    }
    else if (a == 'f' && b == 'e' && c == 'b'){
        month = 2;
    }
    else if (a == 'm' && b == 'a' && c == 'r'){
        month = 3;
    }
    else if (a == 'a' && b == 'p' && c == 'r'){
        month = 4;
    }
    else if (a == 'm' && b == 'a' && c == 'y'){
        month = 5;
    }
    else if (a == 'j' && b == 'u' && c == 'n'){
        month = 6;
    }
    else if (a == 'j' && b == 'u' && c == 'l'){
        month = 7;
    }
    else if (a == 'a' && b == 'u' && c == 'g'){
        month = 8;
    }
    else if (a == 's' && b == 'e' && c == 'p'){
        month = 9;
    }
    else if (a == 'o' && b == 'c' && c == 't'){
        month = 10;
    }
    else if (a == 'n' && b == 'o' && c == 'v'){
        month = 11;
    }
    else if (a == 'd' && b == 'e' && c == 'c'){
        month = 12;
    }
    else{
        cout << "Invalid combination of characters. Exiting program."<<endl;
        exit(1);
    }
}

void Month::outputNum(){
    cout << month;
}

void Month::outputChar(){
    if (month == 1) {
        cout << "jan" <<endl;
    }
    if (month == 2) {
        cout << "feb" <<endl;
    }
    if (month == 3) {
        cout << "mar" <<endl;
    }
    if (month == 4) {
        cout << "apr" <<endl;
    }
    if (month == 5) {
        cout << "may" <<endl;
    }
    if (month == 6) {
        cout << "jun" <<endl;
    }
    if (month == 7) {
        cout << "jul" <<endl;
    }
    if (month == 8) {
        cout << "aug" <<endl;
    }
    if (month == 9) {
        cout << "sep" <<endl;
    }
    if (month == 10) {
        cout << "oct" <<endl;
    }
    if (month == 11) {
        cout << "nov" <<endl;
    }
    if (month == 12) {
        cout << "dec" <<endl;
    }
}

void Month::nextMonth(){
    if(month < 12){
        month = month + 1;
    }
    else {
        month = 1;
    }
}
