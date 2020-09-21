//
//  MegaMillionsLottery.cpp
//  CS 31 Project 5
//
//  Created by Stephen Chu on 2/20/20.
//  Copyright © 2020 Steven Chu. All rights reserved.
//

#include <stdio.h>
#include "MegaMillionsLottery.h"
#include "MegaMillionsTicket.h"
#include "RandomNumber.h"
#include <iostream>
#include <string>
using namespace std;

//default constructor
MegaMillionsLottery::MegaMillionsLottery()
{
    RandomNumber ball(1,70);
    RandomNumber mega(1,25);
    mBall1 = ball.random();
    mBall2 = ball.random();
    mBall3 = ball.random();
    mBall4 = ball.random();
    mBall5 = ball.random();
    mMegaBall = mega.random();
    while(mBall1 == mBall2 || mBall1 == mBall3 || mBall1 == mBall4 || mBall1 == mBall5 || mBall2 == mBall3 || mBall2 == mBall4 || mBall2 == mBall5 || mBall3 == mBall4 || mBall3 == mBall5 || mBall4 == mBall5)
    {
        mBall1 = ball.random();
        mBall2 = ball.random();
        mBall3 = ball.random();
        mBall4 = ball.random();
        mBall5 = ball.random();
        mMegaBall = mega.random();
    }
}
// constructor with passed parameters for ball values
MegaMillionsLottery::MegaMillionsLottery(int ball1, int ball2, int ball3, int ball4, int ball5, int megaBall)
{
    mBall1 = ball1;
    mBall2 = ball2;
    mBall3 = ball3;
    mBall4 = ball4;
    mBall5 = ball5;
    mMegaBall = megaBall;
}

//getters
int MegaMillionsLottery::getBall1()
{
    return mBall1;
}

int MegaMillionsLottery::getBall2()
{
    return mBall2;
}

int MegaMillionsLottery::getBall3()
{
    return mBall3;
}

int MegaMillionsLottery::getBall4()
{
    return mBall4;
}

int MegaMillionsLottery::getBall5()
{
    return mBall5;
}

int MegaMillionsLottery::getMegaBall()
{
    return mMegaBall;
}


MegaMillionsTicket MegaMillionsLottery::quickPick()
{
    //set random values for all balls
    RandomNumber ball(1,70);
    RandomNumber mega(1,25);
    int ball1 = ball.random();
    int ball2 = ball.random();
    int ball3 = ball.random();
    int ball4 = ball.random();
    int ball5 = ball.random();
    int megaBall = mega.random();
    //make sure there are no repeating values in balls 1-5
    while(ball1 == ball2 || ball1 == ball3 || ball1 == ball4 || ball1 == ball5 || ball2 == ball3 || ball2 == ball4 || ball2 == ball5 || ball3 == ball4 || ball3 == ball5 || ball4 == ball5)
    {
        ball1 = ball.random();
        ball2 = ball.random();
        ball3 = ball.random();
        ball4 = ball.random();
        ball5 = ball.random();
        megaBall = mega.random();
    }
    //create the ticket object with the generated ball values
    MegaMillionsTicket ticket(ball1, ball2, ball3, ball4, ball5, megaBall);
    return ticket;
}


MegaMillionsLottery::WinningPossibility MegaMillionsLottery::checkTicket(MegaMillionsTicket ticket)
{
    // check for number of matches in regular balls
    int count = 0;
    bool megaMatch = false;
    MegaMillionsLottery::WinningPossibility result;
    if(ticket.getBall1() == mBall1 || ticket.getBall1() == mBall2 || ticket.getBall1() == mBall3 || ticket.getBall1() == mBall4 || ticket.getBall1() == mBall5)
    {
        count++;
    }
    if(ticket.getBall2() == mBall1 || ticket.getBall2() == mBall2 || ticket.getBall2() == mBall3 || ticket.getBall2() == mBall4 || ticket.getBall2() == mBall5)
    {
        count++;
    }
    if(ticket.getBall3() == mBall1 || ticket.getBall3() == mBall2 || ticket.getBall3() == mBall3 || ticket.getBall3() == mBall4 || ticket.getBall3() == mBall5)
    {
        count++;
    }
    if(ticket.getBall4() == mBall1 || ticket.getBall4() == mBall2 || ticket.getBall4() == mBall3 || ticket.getBall4() == mBall4 || ticket.getBall4() == mBall5)
    {
        count++;
    }
    if(ticket.getBall5() == mBall1 || ticket.getBall5() == mBall2 || ticket.getBall5() == mBall3 || ticket.getBall5() == mBall4 || ticket.getBall5() == mBall5)
    {
        count++;
    }
    //check megaball match
    if(ticket.getMegaBall() == mMegaBall)
    {
        megaMatch = true;
    }
    //check cases return appropriate case
    if(count == 1 && megaMatch)
    {
        result = ONEPLUSMEGABALL;
        return result;
    }
    if(count == 2 && megaMatch)
    {
        result = TWOPLUSMEGABALL;
        return result;
    }
    if(count == 3 && megaMatch)
    {
        result = THREEPLUSMEGABALL;
        return result;
    }
    if(count == 4 && megaMatch)
    {
        result = FOURPLUSMEGABALL;
        return result;
    }
    if(count == 5 && megaMatch)
    {
        result = FIVEPLUSMEGABALL;
        return result;
    }
    if(count == 3)
    {
        result = THREE;
        return result;
    }
    if(count == 4)
    {
        result = FOUR;
        return result;
    }
    if(count == 5)
    {
        result = FIVE;
        return result;
    }
    if(megaMatch)
    {
        result = MEGABALL;
        return result;
    }
    else
    {
        result = NOTWINNING;
        return result;
    }
}

string MegaMillionsLottery::whatHappened(MegaMillionsTicket ticket)
{
    //check enum result and return appropriate corresponding string
    MegaMillionsLottery::WinningPossibility result = checkTicket(ticket);
    if(result == NOTWINNING)
    {
        return "You didn't win anything at all!";
    }
    if(result == MEGABALL)
    {
        return "You matched the megaball!";
    }
    if(result == ONEPLUSMEGABALL)
    {
        return "You matched 1 ball plus the megaball!";
    }
    if(result == TWOPLUSMEGABALL)
    {
        return "You matched 2 balls plus the megaball!";
    }
    if(result == THREEPLUSMEGABALL)
    {
        return "You matched 3 balls plus the megaball!";
    }
    if(result == THREE)
    {
        return "You matched 3 balls!";
    }
    if(result == FOURPLUSMEGABALL)
    {
        return "You matched 4 balls plus the megaball!";
    }
    if(result == FOUR)
    {
        return "You matched 4 balls!";
    }
    if(result == FIVE)
    {
        return "You matched 5 balls!";
    }
    if(result == FIVEPLUSMEGABALL)
    {
        return "You matched 5 balls plus the megaball!";
    }
    else
    {
        return "You didn't win anything at all!";
    }
}
