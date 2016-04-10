//
//  Comparable.h
//  CSC502-Programming-Assignment4
//
//  Created by Andrew Smiley on 4/10/16.
//  Copyright © 2016 Andrew Smiley. All rights reserved.
//

#ifndef Comparable_h
#define Comparable_h
￼template <typename T>
￼class Comparable
￼
/* You will document your assumptions about T here:
 */
public:
// There is no suitable built-in type such as int, double, etc.,
//   to serve as the default parameter, but we can assume
//   something and create a default (no-arg) constructor.
//   Document that assumption along with others above.
Comparable( const T & initialValue = T() )
:  value( initialValue )    { }
￼// Implement the 6 relational operators: <, >, ==, !=, <=, and >=
￼//   as member functions without using any other member function
￼// print is again used to assist with the external << operator
￼void print( ostream & out= cout ) const
￼{ out << value ; }
￼private:
￼};
T value ;
￼

#endif /* Comparable_h */
