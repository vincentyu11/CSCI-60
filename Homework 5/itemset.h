//
//  itemset.h
//  3
//
//  Created by Vincent Yu on 2/20/18.
//  Copyright © 2018 Vincent Yu. All rights reserved.
//

#ifndef itemset_h
#define itemset_h

template <typename T>
class Set{
public:
    Set();
    Set(T *thearray, int thesize);
    ~Set();
    void add(T item);
    int getsize();
    T getitem(int location);
    T getpointer()const;
private:
    T *array;
    int size;
};


template <typename T>
Set<T>::Set(){
    size = 0;
    array = nullptr;
}

template <typename T>
Set<T>::Set(T *thearray, int thesize){
    array = thearray;
    size = thesize;
}

template <typename T>
Set<T>::~Set(){
    delete [] array;
}

template <typename T>
void Set<T>::add(T item){
    bool duplicate = false;
    for (int i =0; i<size; i++) {
        if (array[i] == item) {
            duplicate = true;
        }
    }
    if (duplicate == false) {
        T *newarray = new T[size+1];
        for (int i=0; i<size; i++) {
            newarray[i] = array[i];
        }
        newarray[size] = item;
        size = size+1;
        array = newarray;
    }
}

template <typename T>
int Set<T>::getsize(){
    return size;
}

template <typename T>
T Set<T>::getitem(int location){
    return array[location];
}

template <typename T>
T Set<T>::getpointer()const{
    T *newcopy = new T[size];
    for (int i =0; i<size; i++) {
        newcopy[i] = array[i];
    }
    return newcopy;
}

#endif /* itemset_h */

