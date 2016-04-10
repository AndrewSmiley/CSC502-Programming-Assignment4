//
//  Comparable.h
//  CSC502-Programming-Assignment4
//
//  Created by Andrew Smiley on 4/10/16.
//  Copyright © 2016 Andrew Smiley. All rights reserved.
//


#ifndef Comparable_h
#include <iostream>
#define Comparable_h


using namespace std;


template <class T> class Comparable{
public:
    Comparable(const T &initialValue = T())
    : value(initialValue) {};
    
    void print(ostream & out= cout) const{
        out << value;
    }
    
    T getValue()const{
        return value;
    }
    
    bool operator==(const Comparable<T> &lhs) const { return lhs.getValue() == value; }
    bool operator<(const Comparable<T> &lhs) const { return lhs.getValue() < value; }
    bool operator>(const Comparable<T> &lhs) const { return lhs.getValue() > value; }
    bool operator<=(const Comparable<T> &lhs) const { return lhs.getValue() <= value; }
    bool operator>=(const Comparable<T> &lhs) const { return lhs.getValue() >= value; }
    bool operator!=(const Comparable<T> &lhs) const { return lhs.getValue() != value; }
    

    
    
private:
    T value;

};

template<typename T> ostream & operator << (ostream & out, const Comparable<T> cmp){
    cmp.print();
    return out;
}

#endif /* Comparable_h */
