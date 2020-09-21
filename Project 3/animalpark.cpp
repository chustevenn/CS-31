//
//  main.cpp
//  CS 31 Project 3
//
//  Created by Stephen Chu on 1/22/20.
//  Copyright © 2020 Steven Chu. All rights reserved.
//
#include <cassert>
#include <iostream>
#include <string>
using namespace std;

bool isValidAnimalParkString(string animalparkString)
{
    //brute force empty string edge case
    if(animalparkString == "")
    {
        return false;
    }
    //string cannot begin with anything other than an entering dog or cat
    if(animalparkString.at(0) != 'c' && animalparkString.at(0) != 'C' && animalparkString.at(0) != 'D' && animalparkString.at(0) != 'd')
    {
        return false;
    }
    //string cannot end with anything other than a person
    if(animalparkString.at(animalparkString.size()-1) != 'p' && animalparkString.at(animalparkString.size()-1) != 'P')
    {
        return false;
    }
    //initialize counter and tracking numbers for each type of individual
    int numKittens = 0;
    int numPuppies = 0;
    int numDoggos = 0;
    int numCats = 0;
    int numAdults = 0;
    int numKids = 0;
    int i = 0;
    //begin looping through starting segment of string
    while(i < animalparkString.size()-1)
    {
        //count cats, return false if dogs or any other character is present, end loop when person appears
        if(animalparkString.at(i) == 'C' || animalparkString.at(i) == 'c')
        {
            while(animalparkString.at(i) != 'P' && animalparkString.at(i) != 'p')
            {
                if(animalparkString.at(i) == 'c')
                {
                    numKittens++;
                    i++;
                }
                else if(animalparkString.at(i) == 'C')
                {
                    numCats++;
                    i++;
                }
                else
                {
                    return false;
                }
            }
        }
        //count dogs, return false if cats or any other character is present, end loop when person appears
        if(animalparkString.at(i) == 'D' || animalparkString.at(i) == 'd')
        {
            while(animalparkString.at(i) != 'P' && animalparkString.at(i) != 'p')
            {
                if(animalparkString.at(i) == 'd')
                {
                    numPuppies++;
                    i++;
                }
                else if(animalparkString.at(i) == 'D')
                {
                    numDoggos++;
                    i++;
                }
                else
                {
                    return false;
                }
            }
        }
        //count people, end loop at end of segment
        if(animalparkString.at(i) == 'P' || animalparkString.at(i) == 'p')
        {
            while(animalparkString.at(i) != '+' && animalparkString.at(i) != '-')
            {
                if(animalparkString.at(i) == 'P')
                {
                    numAdults++;
                    i++;
                }
                else if(animalparkString.at(i) == 'p')
                {
                    numKids++;
                    i++;
                }
                else
                {
                    return false;
                }
                if(i == animalparkString.size())
                {
                    break;
                }
            }
        }
        //break out of loop if end of string is reached
        if(i == animalparkString.size())
        {
            break;
        }
        //coming in, send back to top of loop
        if(animalparkString.at(i) == '+')
        {
            if(animalparkString.at(i+1) != 'c' && animalparkString.at(i+1) != 'C' && animalparkString.at(i+1) != 'D' && animalparkString.at(i+1) != 'd')
            {
                return false;
            }
            i++;
        }
        //leaving, proceed with same process as above except we now decrement the tracking number
        if(animalparkString.at(i) == '-')
        {
            if(animalparkString.at(i+1) != 'c' && animalparkString.at(i+1) != 'C' && animalparkString.at(i+1) != 'D' && animalparkString.at(i+1) != 'd')
            {
                return false;
            }
            i++;
            if(animalparkString.at(i) == 'C' || animalparkString.at(i) == 'c')
            {
                while(animalparkString.at(i) != 'P' && animalparkString.at(i) != 'p')
                {
                    if(animalparkString.at(i) == 'c')
                    {
                        numKittens--;
                        i++;
                    }
                    else if(animalparkString.at(i) == 'C')
                    {
                        numCats--;
                        i++;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            if(animalparkString.at(i) == 'D' || animalparkString.at(i) == 'd')
            {
                while(animalparkString.at(i) != 'P' && animalparkString.at(i) != 'p')
                {
                    if(animalparkString.at(i) == 'd')
                    {
                        numPuppies--;
                        i++;
                    }
                    else if(animalparkString.at(i) == 'D')
                    {
                        numDoggos--;
                        i++;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            if(animalparkString.at(i) == 'P' || animalparkString.at(i) == 'p')
            {
                while(animalparkString.at(i) != '+' && animalparkString.at(i) != '-')
                {
                    if(animalparkString.at(i) == 'P')
                    {
                        numAdults--;
                        i++;
                    }
                    else if(animalparkString.at(i) == 'p')
                    {
                        numKids--;
                        i++;
                    }
                    else
                    {
                        return false;
                    }
                    if(i == animalparkString.size())
                    {
                        break;
                    }
                }
            }
        }
    }
    //check that no more of each individual left than entered
    if(numDoggos >= 0 && numKittens >= 0 && numKids >= 0 && numPuppies >= 0 && numAdults >= 0 && numCats >= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int dogsLeft(string animalparkString)
{
    int doggos = 0;
    if(!isValidAnimalParkString(animalparkString))
    {
        return -1;
    }
    int i = 0;
    while(i < animalparkString.size())
    {
        while(animalparkString.at(i) != '+' && animalparkString.at(i) != '-')
        {
            if(animalparkString.at(i) != 'd' && animalparkString.at(i) != 'D')
            {
                i++;
            }
            else
            {
                doggos++;
                i++;
            }
            if(i == animalparkString.size())
            {
                break;
            }
        }
        if(i == animalparkString.size())
        {
            break;
        }
        if(animalparkString.at(i) == '+')
        {
            i++;
        }
        if(animalparkString.at(i) == '-')
        {
            i++;
            while(animalparkString.at(i) != '+' && animalparkString.at(i) != '-')
            {
                if(animalparkString.at(i) != 'd' && animalparkString.at(i) != 'D')
                {
                    i++;
                }
                else
                {
                    doggos--;
                    i++;
                }
                if(i == animalparkString.size())
                {
                    break;
                }
            }
        }
    }
    return doggos;
}

int catsLeft(string animalparkString)
{
    int cats = 0;
    if(!isValidAnimalParkString(animalparkString))
    {
        return -1;
    }
    int i = 0;
    while(i < animalparkString.size())
    {
        while(animalparkString.at(i) != '+' && animalparkString.at(i) != '-')
        {
            if(animalparkString.at(i) != 'c' && animalparkString.at(i) != 'C')
            {
                i++;
            }
            else
            {
                cats++;
                i++;
            }
            if(i == animalparkString.size())
            {
                break;
            }
        }
        if(i == animalparkString.size())
        {
            break;
        }
        if(animalparkString.at(i) == '+')
        {
            i++;
        }
        if(animalparkString.at(i) == '-')
        {
            i++;
            while(animalparkString.at(i) != '+' && animalparkString.at(i) != '-')
            {
                if(animalparkString.at(i) != 'c' && animalparkString.at(i) != 'C')
                {
                    i++;
                }
                else
                {
                    cats--;
                    i++;
                }
                if(i == animalparkString.size())
                {
                    break;
                }
            }
        }
    }
    return cats;
}

int peopleLeft(string animalparkString)
{
    int ppl = 0;
    if(!isValidAnimalParkString(animalparkString))
    {
        return -1;
    }
    int i = 0;
    while(i < animalparkString.size())
    {
        while(animalparkString.at(i) != '+' && animalparkString.at(i) != '-')
        {
            if(animalparkString.at(i) != 'p' && animalparkString.at(i) != 'P')
            {
                i++;
            }
            else
            {
                ppl++;
                i++;
            }
            if(i == animalparkString.size())
            {
                break;
            }
        }
        if(i == animalparkString.size())
        {
            break;
        }
        if(animalparkString.at(i) == '+')
        {
            i++;
        }
        if(animalparkString.at(i) == '-')
        {
            i++;
            while(animalparkString.at(i) != '+' && animalparkString.at(i) != '-')
            {
                if(animalparkString.at(i) != 'p' && animalparkString.at(i) != 'P')
                {
                    i++;
                }
                else
                {
                    ppl--;
                    i++;
                }
                if(i == animalparkString.size())
                {
                    break;
                }
            }
        }
    }
    return ppl;
}

int main()
{
    assert(!isValidAnimalParkString(""));
    assert(isValidAnimalParkString("ccPp+dP+cCP+dddP+dp"));
    assert(isValidAnimalParkString("cp+CCP-cp+dDPPp-dp"));
    assert(isValidAnimalParkString("cccP+dp+dPPpP+ccCCcP+ccP"));
    assert(!isValidAnimalParkString("d p + c p"));
    assert(isValidAnimalParkString("ccP+dDdp-ddP"));
    assert(!isValidAnimalParkString("asdf1ABC000:2-55"));
    assert(!isValidAnimalParkString("cp+P-cpP"));
    assert(!isValidAnimalParkString("cpP-P"));
    assert(!isValidAnimalParkString("dp-CP"));
    assert(isValidAnimalParkString("DP+CP+cp+dp-Dp-Cp-dP-cP"));
    assert(!isValidAnimalParkString("cCcDP"));
    assert(!isValidAnimalParkString("cP+dP-cdPP"));
    cerr << " " << dogsLeft("cp+CCP-cp+dDPPp-dp") << endl;
    cerr << " " << dogsLeft("ccPp+dP+cCP+dddP+dp") << endl;
    cerr << " " << catsLeft("cp+CCP-cp+dDPPp-dp") << endl;
    cerr << " " << catsLeft("ccPp+dP+cCP+dddP+dp") << endl;
    cerr << " " << peopleLeft("cp+CCP-cp+dDPPp-dp") << endl;
    cerr << " " << peopleLeft("ccPp+dP+cCP+dddP+dp") << endl;
    cerr << " " << dogsLeft("      ") << endl;
    cerr << " " << dogsLeft("cp+P-cpP") << endl;
    cerr << "All tests succeeded" << endl;
    return 0;
}
