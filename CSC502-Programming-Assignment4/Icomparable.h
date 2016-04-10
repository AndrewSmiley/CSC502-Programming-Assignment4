////
////  Icomparable.hpp
////  inheritance
////
////  Created by Andrew Smiley on 3/27/16.
////  Copyright © 2016 Andrew Smiley. All rights reserved.
////
//
//#ifndef Icomparable_hpp
//#define Icomparable_hpp
//
//#include <stdio.h>
//
//#endif /* Icomparable_hpp */
////
////  IComparable.h
////  CSC502-Programming-Assignment3
////
////  Created by Andrew Smiley on 3/5/16.
//  Copyright © 2016 Andrew Smiley. All rights reserved.
//

#ifndef IComparable_h
#define IComparable_h
#define COMPARE_GREATER 1;
#define COMPARE_LESS -1;
#define COMPARE_EQUAL 0;
#include <iostream>
using namespace std;


class IComparable
{
public:
    IComparable(){};
    IComparable(const IComparable &i){};
    
    virtual const IComparable & operator= (const IComparable & rhs) {
        return *this; // dummy implementation
    }
    int compare( const IComparable & icmp ) const{
//        cout << "using IComparable compare()"<<endl;
        return 0;
    }
    
    virtual bool operator < ( const IComparable & rhs ) const {
        //one liners for the win
        return compare(rhs) ==  COMPARE_LESS;
    }
    // Implement this using compare()
    virtual bool operator >   ( const IComparable & rhs ) const {
        //one liners for the win
        return compare(rhs) ==  COMPARE_GREATER;
    }
    // Implement this using compare()
    bool operator ==   ( const IComparable & rhs ) const {
        //one liners for the win
        return compare(rhs) ==  COMPARE_EQUAL;
    }
    
    // Implement this using compare()
    bool operator !=   ( const IComparable & rhs ) const {
        //one liners for the win
        return compare(rhs) ==  COMPARE_EQUAL;
    }

    // Implement this using compare()
    bool operator <=   ( const IComparable & rhs ) const {
        return compare(rhs) < 1;
    }
    
    // Implement this using compare()
    bool operator >=   ( const IComparable & rhs ) const {
        //we can't use || operator because it's not a defined member function, from what I can tellk
        return compare(rhs) > -1;
    }
    

    
    virtual void print( ostream & out= cout ) const{};
    
//    ostream& operator<<( ostream & out, const IComparable & d );
    
private:
    
} ;

class Integer : public IComparable{
public:
    //no arg constructor
    Integer (){
        this->value = 0;
    }
    

    //single int argument
    Integer (const int &intval){
        this->value = intval;
    }

    
    Integer (const IComparable &ic){
        this->value=0;
    }
    
    

    bool operator < ( const Integer & rhs ) const {
        //one liners for the win
        return compare(rhs) ==  COMPARE_LESS;
    }
    // Implement this using compare()
    bool operator >   ( const Integer & rhs ) const {
        //one liners for the win
        return compare(rhs) ==  COMPARE_GREATER;
    }
    // Implement this using compare()
    bool operator ==   ( const Integer & rhs ) const {
        //one liners for the win
        return compare(rhs) ==  COMPARE_EQUAL;
    }
    
    // Implement this using compare()
    bool operator !=   ( const Integer & rhs ) const {
        //one liners for the win
        return compare(rhs) !=  COMPARE_EQUAL;
    }
    
    // Implement this using compare()
    bool operator <=   ( const Integer & rhs ) const {
        return compare(rhs) < 1;
    }
    
    // Implement this using compare()
    bool operator >=   ( const Integer & rhs ) const {
        //we can't use || operator because it's not a defined member function, from what I can tellk
        return compare(rhs) > -1;
    }
    //assignment operator
    const Integer & operator= (const Integer & rhs) {
        this-> value = rhs.getValue();
        return *this;
    }


    
    int getValue() const{
        return this->value;
    }
    
    int compare(const Integer &comparable) const{
//        cout << "using Integer compare()"<<endl;
        //stub this out for now?
        //we should be able to use the subclass
        if (value < comparable.getValue()){
            return COMPARE_LESS;
        }
        
        if (value > comparable.getValue()){
            return COMPARE_GREATER;
        }

        if (value == comparable.getValue()){
            return COMPARE_EQUAL;
        }
        //this could be more elegant
        return 0;
        
    }
    void print( ostream & out= cout ) const{
        cout << this->value;
    }
    
    
private:
    int value;
    
    
};

/*
 Couldn't we just override Integer..?
 */
class Character : public IComparable{
public:
    Character(){
        value = '?';
    }
    Character(const Character &characater){
        value = characater.getValue();
    }
    
    Character(const IComparable &ic){
        value = '?';
        
    }
    Character(char characater){
        value=characater;
    }
    
    
    const Character & operator= (const Character & rhs) {
        value =rhs.getValue();
        return *this;   // dummy implementation
    }
    
    char getValue() const{
        return value;
    }
    
    void print( ostream & out= cout ) const{
        cout << this->value;
    }

    
    bool operator < ( const Character & rhs ) const {
        //one liners for the win
        return compare(rhs) ==  COMPARE_LESS;
    }
    // Implement this using compare()
    bool operator >   ( const Character & rhs ) const {
        //one liners for the win
        return compare(rhs) ==  COMPARE_GREATER;
    }
    // Implement this using compare()
    bool operator ==   ( const Character & rhs ) const {
        //one liners for the win
        return compare(rhs) ==  COMPARE_EQUAL;
    }
    
    // Implement this using compare()
    bool operator !=   ( const Character & rhs ) const {
        //one liners for the win
        return compare(rhs) !=  COMPARE_EQUAL;
    }
    
    // Implement this using compare()
    bool operator <=   ( const Character & rhs ) const {
        return compare(rhs) < 1;
    }
    
    // Implement this using compare()
    bool operator >=   ( const Character & rhs ) const {
        //we can't use || operator because it's not a defined member function, from what I can tellk
        return compare(rhs) > -1;
    }
    
    int compare(const Character &comparable) const{

        if (value < comparable.getValue()){
            return COMPARE_LESS;
        }
        
        if (value > comparable.getValue()){
            return COMPARE_GREATER;
        }
        
        if (value == comparable.getValue()){
            return COMPARE_EQUAL;
        }
        //this could be more elegant
        return 0;
        
    }
    
    
private:
    char value;
    
};

struct LessThan{
    LessThan(){};
    bool operator()(IComparable *ic1, IComparable *ic2 ) {
        return ic1->compare(*ic2) == COMPARE_LESS;
        
    }
};

ostream& operator<<(std::ostream& outStream, const IComparable& c){
    c.print(outStream);
    return outStream;
}


#endif /* IComparable_h */