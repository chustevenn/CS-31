//
//  RandomNumber.h
//  CS 31 Project 5
//
//  Created by Stephen Chu on 2/20/20.
//  Copyright © 2020 Steven Chu. All rights reserved.
//

#ifndef RandomNumber_h
#define RandomNumber_h
class RandomNumber
{
public:
    RandomNumber( int min, int max, bool minInclusive=true, bool maxInclusive=true );
    
    // supply a number between min and max inclusive
    int random( );
private:
    int  mMinimum, mMaximum;
};
#endif /* RandomNumber_h */
