//
//  Board.h
//  CS 31 Project 7
//
//  Created by Stephen Chu on 3/5/20.
//  Copyright © 2020 Steven Chu. All rights reserved.
//

#ifndef Board_h
#define Board_h
#include <string>

namespace cs31
{
    
    /*
     This class is used to display the game state with each round of play.
     CS 31 Students have work to do here.
     */
    class Board
    {
    public:
        Board();
        
        // a spot on the board is a value between 0-12
        // spot 0 is the opening position, before any rolls of 1-12 have taken place
        // once a player has rolled desired value, adjust the spot accordingly
        void setHumanSpot( int spot );
        void setComputerSpot( int spot );
        int  getHumanSpot();
        int  getComputerSpot();
 
        // CS 31 TODO: identify  that computer won
        void markComputerAsWinner();
        // CS 31 TODO: identify that the human won
        void markHumanAsWinner();
        // CS 31 TODO: if the game is over, determine if the human has won
        bool isHumanWinner() const;
        // CS 31 TODO: identify whether or not the game has ended
        void setGameOver( bool value );
        // CS 31 TODO: determine if the game has ended
        bool isGameOver( ) const;
        
        // the major operation of board
        // prints the state of the game play with each round of play
        std::string display( ) const;
    private:
        int  mHumanSpot, mComputerSpot; // how far along are the two players?
        bool mGameOver;  // is the game over?
        bool mHumanWon;  // has the human won?
    };
}

#endif /* Board_h */
