//
//  main.cpp
//  CS 31 Project 7
//
//  Created by Stephen Chu on 3/5/20.
//  Copyright © 2020 Steven Chu. All rights reserved.
//

#include <iostream>
    #include <string>
    #include <cassert>
        #include "Die.h"
        #include "Board.h"
        #include "Player.h"
        #include "Centennial.h"

    using namespace std;

    int main()
    {
           using namespace std;
           using namespace cs31;
           // Die test code
           int i, value;
           Die d, d1, d2, d3, d4, d5, d6;
           for( i = 1; i <= 50; i++)
           {
                d.roll();
                value = d.getValue( );
                assert( value >= 1 && value <= 6 );
           }

           // Player test code
           Player p, human, computer;
           // in the beginning of time, nothing has been rolled yet and the spot needed is 1...
           assert( !p.hasRolledOne( ) );
           assert( !p.hasRolledTwo( ) );
           assert( !p.hasRolledThree( ) );
           assert( !p.hasRolledFour( ) );
           assert( !p.hasRolledFive( ) );
           assert( !p.hasRolledSix( ) );
           assert( !p.hasRolledSeven( ) );
           assert( !p.hasRolledEight( ) );
           assert( !p.hasRolledNine( ) );
           assert( !p.hasRolledTen( ) );
           assert( !p.hasRolledEleven( ) );
           assert( !p.hasRolledTwelve( ) );
           assert( p.whatSpotIsNeededNext( ) == 1 );
           // now the player has rolled 1... so the spot next needed is 2...
           p.rolled( 1 );
           assert( p.hasRolledOne( ) );
           assert( !p.hasRolledTwo( ) );
           assert( p.whatSpotIsNeededNext( ) == 2 );
           // only rolls from 1-12 are relevant...
           p.rolled( 100 );
           assert( p.hasRolledOne( ) );
           assert( !p.hasRolledTwo( ) );
           assert( p.whatSpotIsNeededNext( ) == 2 );
           // rolls must be sequential for things to count...
           p.rolled( 3 );
           assert( p.hasRolledOne( ) );
           assert( !p.hasRolledTwo( ) );
           assert( !p.hasRolledThree( ) );
           assert( p.whatSpotIsNeededNext( ) == 2 );
           // work the Player via Dies
           d1.setValue( 6 );
           d2.setValue( 5 );
           d3.setValue( 4 );
           p.roll( d1, d2, d3 );
           assert( p.whatWasRolled() == "Die1: 6 Die2: 5 Die3: 4\n" );

           // Board test code
           Board b;
           assert( b.getHumanSpot( ) == 0 );
           assert( b.getComputerSpot( ) == 0 );
           assert( b.isGameOver( ) == false );
           assert( b.isHumanWinner( ) == false );
           b.setHumanSpot( 3 );
           b.setComputerSpot( 6 );
           assert( b.getHumanSpot( ) == 3 );
           assert( b.getComputerSpot( ) == 6 );
           assert( b.isGameOver( ) == false );
           assert( b.isHumanWinner( ) == false );
           b.setHumanSpot( 12 );
           assert( b.getHumanSpot( ) == 12 );
           assert( b.getComputerSpot( ) == 6 );
           assert( b.isGameOver( ) == false );
           assert( b.isHumanWinner( ) == false );
           b.setGameOver( true );
           b.markHumanAsWinner( );
           assert( b.isGameOver( ) == true );
           assert( b.isHumanWinner( ) == true );
           // Centennial test code
           Centennial game;
           assert( game.isGameOver( ) == false );
           assert( game.determineGameOutcome( ) == Centennial::GAMENOTOVER );
           human = game.getHuman( );
           computer = game.getComputer( );
           assert( human.whatSpotIsNeededNext( ) == 1 );
           assert( computer.whatSpotIsNeededNext( ) == 1 );
           d1.setValue( 1 );
           d2.setValue( 2 );
           d3.setValue( 3 );
           d4.setValue( 4 );
           d5.setValue( 5 );
           d6.setValue( 6 );
           game.humanPlay( d6, d5, d4 );
           human = game.getHuman( );
           assert( human.whatSpotIsNeededNext( ) == 1 );
           game.computerPlay( d1, d2, d3 );
           computer= game.getComputer( );
           assert( computer.whatSpotIsNeededNext( ) == 7 );
           game.humanPlay( d4, d2, d1 );
           human = game.getHuman( );
           assert( human.whatSpotIsNeededNext( ) == 8 );
           game.computerPlay( d5, d2, d1 );
           computer = game.getComputer( );
           assert( computer.whatSpotIsNeededNext( ) == 9 );
           game.humanPlay( d6, d2, d3 );
           human = game.getHuman( );
           assert( human.whatSpotIsNeededNext( ) == 10 );
           game.computerPlay( d1, d2, d3 );
           computer = game.getComputer( );
           assert( computer.whatSpotIsNeededNext( ) == 9 );
           game.humanPlay( d4, d5, d6 );
           human = game.getHuman( );
           assert( human.whatSpotIsNeededNext( ) == 12 );
           game.computerPlay( d3, d2, d1 );
           computer = game.getComputer( );
           assert( computer.whatSpotIsNeededNext( ) == 9 );
           assert( game.isGameOver( ) == false );
           assert( game.determineGameOutcome( ) == Centennial::GAMENOTOVER );
           game.humanPlay( d2, d4, d6 );
           assert( game.isGameOver( ) == true );
           assert( game.determineGameOutcome( ) == Centennial::HUMANWONGAME );

           cout << "all tests passed!" << endl;
           return 0;

}
