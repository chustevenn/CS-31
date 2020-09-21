//
//  Centennial.cpp
//  CS 31 Project 7
//
//  Created by Stephen Chu on 3/5/20.
//  Copyright © 2020 Steven Chu. All rights reserved.
//

#include "Centennial.h"
#include <iostream>
#include <string>

namespace cs31
{
    // human goes first
    Centennial::Centennial() : isHumanTurn( true )
    {
        
    }
    
    // prints the state of the game play with each round of play
    std::string Centennial::display( std::string msg )
    {
        using namespace std;
        std::string s( "" );
        if (isHumanTurn)
        {
            s += "Human-";
            s += mHuman.whatWasRolled();
        }
        else
        {
            s += "Computer-";
            s += mComputer.whatWasRolled();
        }
        s += mBoard.display();

        if (isGameOver())
        {
            if (determineGameOutcome() == HUMANWONGAME)
            {
                s = s + "\n\t\tyou won Centennial!\n";
            }
            else
            {
                s = s + "\n\t\tyou lost Centennial!\n";
            }
        }
        else
        {
            s = s + msg;
        }
        return( s );
    }
    
    // CS 31 TODO: randomly play a human turn in the game
    void Centennial::humanPlay( )
    {
        //sets human turn
        isHumanTurn = true;
        bool validRollDetected = true;
        int counter = 0;
        //roll random values
        mHuman.roll();
        //assign rolled values and valid combinations to array
        int rollValues[7];
        rollValues[0] = mHuman.getDie1().getValue();
        rollValues[1] = mHuman.getDie2().getValue();
        rollValues[2] = mHuman.getDie3().getValue();
        rollValues[3] = mHuman.getDie1().getValue() + mHuman.getDie2().getValue();
        rollValues[4] = mHuman.getDie1().getValue() + mHuman.getDie3().getValue();
        rollValues[5] = mHuman.getDie2().getValue() + mHuman.getDie3().getValue();
        rollValues[6] = mHuman.getDie1().getValue() + mHuman.getDie2().getValue() + mHuman.getDie3().getValue();
        //check all combinations for valid roll total
        while(validRollDetected)
        {
            validRollDetected = false;
            for(int i = 0; i < 7; i++)
            {
                if(rollValues[i] == mHuman.whatSpotIsNeededNext())
                {
                    mHuman.rolled(rollValues[i]);
                    mBoard.setHumanSpot(rollValues[i]);
                    validRollDetected = true;
                    counter++;
                }
            }
            if(counter > 7)
            {
                break;
            }
        }
    }
    
    // CS 31 TODO: force a certain roll in the human's turn of the game by cheating...
    //same function structure as previous
    void Centennial::humanPlay( Die d1, Die d2, Die d3 )
    {
        isHumanTurn = true;
        bool validRollDetected = true;
        int counter = 0;
        mHuman.roll(d1, d2, d3);
        int rollValues[7];
        rollValues[0] = mHuman.getDie1().getValue();
        rollValues[1] = mHuman.getDie2().getValue();
        rollValues[2] = mHuman.getDie3().getValue();
        rollValues[3] = mHuman.getDie1().getValue() + mHuman.getDie2().getValue();
        rollValues[4] = mHuman.getDie1().getValue() + mHuman.getDie3().getValue();
        rollValues[5] = mHuman.getDie2().getValue() + mHuman.getDie3().getValue();
        rollValues[6] = mHuman.getDie1().getValue() + mHuman.getDie2().getValue() + mHuman.getDie3().getValue();
        while(validRollDetected)
        {
            validRollDetected = false;
            for(int i = 0; i < 7; i++)
            {
                if(rollValues[i] == mHuman.whatSpotIsNeededNext())
                {
                    mHuman.rolled(rollValues[i]);
                    mBoard.setHumanSpot(rollValues[i]);
                    validRollDetected = true;
                    counter++;
                }
            }
            if(counter > 7)
            {
                break;
            }
        }
    }

    // CS 31 TODO: randomly play a computer turn in the game
    //same function structure as previous
    void Centennial::computerPlay( )
    {
        isHumanTurn = false;
        bool validRollDetected = true;
        int counter = 0;
        mComputer.roll();
        int rollValues[7];
        rollValues[0] = mComputer.getDie1().getValue();
        rollValues[1] = mComputer.getDie2().getValue();
        rollValues[2] = mComputer.getDie3().getValue();
        rollValues[3] = mComputer.getDie1().getValue() + mComputer.getDie2().getValue();
        rollValues[4] = mComputer.getDie1().getValue() + mComputer.getDie3().getValue();
        rollValues[5] = mComputer.getDie2().getValue() + mComputer.getDie3().getValue();
        rollValues[6] = mComputer.getDie1().getValue() + mComputer.getDie2().getValue() + mComputer.getDie3().getValue();
        while(validRollDetected)
        {
            validRollDetected = false;
            for(int i = 0; i < 7; i++)
            {
                if(rollValues[i] == mComputer.whatSpotIsNeededNext())
                {
                    mComputer.rolled(rollValues[i]);
                    mBoard.setComputerSpot(rollValues[i]);
                    validRollDetected = true;
                    counter++;
                }
            }
            if(counter > 7)
            {
                break;
            }
        }
    }
    
    // CS 31 TODO: force a certain roll in the computer's turn of the game by cheating...
    //same function structure as previous
    void Centennial::computerPlay( Die d1, Die d2, Die d3 )
    {
       isHumanTurn = false;
        bool validRollDetected = true;
        int counter = 0;
        mComputer.roll(d1, d2, d3);
        int rollValues[7];
        rollValues[0] = mComputer.getDie1().getValue();
        rollValues[1] = mComputer.getDie2().getValue();
        rollValues[2] = mComputer.getDie3().getValue();
        rollValues[3] = mComputer.getDie1().getValue() + mComputer.getDie2().getValue();
        rollValues[4] = mComputer.getDie1().getValue() + mComputer.getDie3().getValue();
        rollValues[5] = mComputer.getDie2().getValue() + mComputer.getDie3().getValue();
        rollValues[6] = mComputer.getDie1().getValue() + mComputer.getDie2().getValue() + mComputer.getDie3().getValue();
        while(validRollDetected)
        {
            validRollDetected = false;
            for(int i = 0; i < 7; i++)
            {
                if(rollValues[i] == mComputer.whatSpotIsNeededNext())
                {
                    mComputer.rolled(rollValues[i]);
                    mBoard.setComputerSpot(rollValues[i]);
                    validRollDetected = true;
                    counter++;
                }
            }
            if(counter > 7)
            {
                break;
            }
        }
    }
    
    // CS 31 TODO: determine the current state of the game
    // Officially, the human won if that player has rolled 12,11,10,9,8,7,6,5,4,3,2 & 1
    // Officially, the computer won if that player has rolled 12,11,10,9,8,7,6,5,4,3,2 & 1
    // If neither, then the game is still underway
    Centennial::GAMEOUTCOME  Centennial::determineGameOutcome( ) const
    {
        GAMEOUTCOME result = GAMEOUTCOME::GAMENOTOVER;
        if(mHuman.hasRolledOne() && mHuman.hasRolledTwo() && mHuman.hasRolledThree() && mHuman.hasRolledFour() && mHuman.hasRolledFive() && mHuman.hasRolledSix() && mHuman.hasRolledSeven() && mHuman.hasRolledEight() && mHuman.hasRolledNine() && mHuman.hasRolledTen() && mHuman.hasRolledEleven() && mHuman.hasRolledTwelve())
        {
            result = GAMEOUTCOME::HUMANWONGAME;
            return result;
        }
        if(mComputer.hasRolledOne() && mComputer.hasRolledTwo() && mComputer.hasRolledThree() && mComputer.hasRolledFour() && mComputer.hasRolledFive() && mComputer.hasRolledSix() && mComputer.hasRolledSeven() && mComputer.hasRolledEight() && mComputer.hasRolledNine() && mComputer.hasRolledTen() && mComputer.hasRolledEleven() && mComputer.hasRolledTwelve())
        {
            result = GAMEOUTCOME::COMPUTERWONGAME;
            return result;
        }
        return( result );
    }
    
    // CS 31 TODO: determine if the game has ended
    // HINT: call determineGameOutcome( )
    bool Centennial::isGameOver()
    {
        if(Centennial::determineGameOutcome() == GAMEOUTCOME::COMPUTERWONGAME || Centennial::determineGameOutcome() == GAMEOUTCOME::HUMANWONGAME)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // trivial getter operation
    Player Centennial::getHuman() const
    {
        return( mHuman );
    }
    
    // trivial getter operation
    Player Centennial::getComputer() const
    {
        return( mComputer );
    }
    
    // trivial getter operation
    Board  Centennial::getBoard() const
    {
        return( mBoard );
    }
}
