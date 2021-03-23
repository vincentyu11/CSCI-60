//
//  dsa.h
//  dsa
//
//  Created by Vincent Yu on 2/21/18.
//  Copyright © 2018 Vincent Yu. All rights reserved.
//

#ifndef dsa_h
#define dsa_h

#include <iostream>
#include <cstdlib>


template<typename T1, typename T2>
class DynamicStringArray{
public:
    DynamicStringArray();
    DynamicStringArray(const DynamicStringArray &other);
    DynamicStringArray(T1 *thearray, T2 thesize);
    ~DynamicStringArray();
    T2 getsize();
    void addEntry(T1 newline);
    void deleteEntry(T1 newline);
    T1 getEntry(T2 index);
    DynamicStringArray &operator =(const DynamicStringArray &other);
private:
    T1 *dynamicArray;
    T2 size;
};


#endif /* dsa_h */

template<typename T1, typename T2>
DynamicStringArray<T1,T2>::DynamicStringArray(){
    size = 0;
    dynamicArray = nullptr;
}


template<typename T1, typename T2>
DynamicStringArray<T1,T2>::DynamicStringArray(const DynamicStringArray &other){
    size = other.size;
    T1 *newarray = new T1[size];
    for (T2 i=0; i<other.size; i++) {
        newarray[i] = other.dynamicArray[i];
    }
    dynamicArray = newarray;
}

template<typename T1, typename T2>
DynamicStringArray<T1,T2>::DynamicStringArray(T1 *thearray, T2 thesize){
    dynamicArray = thearray;
    size = thesize;
}

template<typename T1, typename T2>
DynamicStringArray<T1,T2>::~DynamicStringArray(){
    dynamicArray = nullptr;
    delete [] dynamicArray;
}


template<typename T1, typename T2>
T2 DynamicStringArray<T1,T2>::getsize(){
    return size;
}


template<typename T1, typename T2>
void DynamicStringArray<T1,T2>::addEntry(T1 newline){
    bool duplicate = false;
    for (T2 i =0; i<size; i++) {
        if (dynamicArray[i] == newline) {
            duplicate = true;
        }
    }
    if (duplicate == false) {
        T1 *newarray = new T1[size+1];
        for (T2 i=0; i<size; i++) {
            newarray[i] = dynamicArray[i];
        }
        newarray[size] = newline;
        size = size+1;
        dynamicArray = newarray;
    }
}


template<typename T1, typename T2>
void DynamicStringArray<T1,T2>::deleteEntry(T1 newline){
    T2 location;
    bool search = false;
    for (T2 i=0; i<size; i++) {
        if (dynamicArray[i] == newline) {
            search = true;
            location = i;
        }
    }
    if (search == false) {
        exit(1);
    }
    else {
        T1 *newarray = new T1[size-1];
        for (T2 i=0; i<location; i++) {
            newarray[i] = dynamicArray[i];
        }
        for (T2 i=location; i<size-1; i++) {
            newarray[i] = dynamicArray[i+1];
        }
        size = size-1;
        dynamicArray = newarray;
    }
}


template<typename T1, typename T2>
T1 DynamicStringArray<T1,T2>::getEntry(T2 index){
    if (index>=size || index <0) {
        return '\0';
    }
    else {
        return dynamicArray[index];
    }
}


template<typename T1, typename T2>
DynamicStringArray<T1,T2>& DynamicStringArray<T1,T2>::operator =(const DynamicStringArray<T1,T2>& other){
    size = other.size;
    T1 *newarray = new T1[size];
    for (T2 i=0; i<other.size; i++) {
        newarray[i] = other.dynamicArray[i];
    }
    dynamicArray = newarray;
}




