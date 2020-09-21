#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int locateMaximum( const string array[], int n )
{
    if(n <= 0)
    {
        return -1;
    }
    int maxIndex = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(array[i] < array[j])
            {
                maxIndex = j;
                break;
            }
        }
        if(maxIndex == i)
        {
            return maxIndex;
        }
    }
    return maxIndex;
}

bool hasDuplicates(const string array[], int  n )
{
    if(n <= 0)
    {
        return false;
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(array[i] == array[j])
            {
                return true;
            }
        }
    }
    return false;
}

int countSs(const string array[], int n)
{
    if(n <= 0)
    {
        return -1;
    }
    int counter = 0;
    for(int i = 0; i < n; i++)
    {
        string s = array[i];
        for(int j = 0; j < s.size(); j++)
        {
            if(s.at(j) == 'S' || s.at(j) == 's')
            {
                counter++;
            }
        }
    }
    return counter;
}

int shiftLeft(string array[], int n, int amount, string placeholderToFillEmpties)
{
    if(n <= 0 || amount == 0)
    {
        return 0;
    }
    if(amount > n)
    {
        for(int i = 0; i < n; i++)
        {
            array[i] = placeholderToFillEmpties;
        }
        return n;
    }
    for(int i = 0; i < n - amount; i++)
    {
        array[i] = array[i + amount];
    }
    for(int j = n - amount; j < n; j++)
    {
        array[j] = placeholderToFillEmpties;
    }
    return amount;
}

bool isInDecreasingOrder(const string array[], int n)
{
    if(n <= 0)
    {
        return false;
    }
    for(int i = 1; i < n; i++)
    {
        if(array[i] >= array[i-1])
        {
            return false;
        }
    }
    return true;
}

bool matchingValuesTogether(const string array[], int n)
{
    if(!hasDuplicates(array, n))
    {
        return true;
    }
    if(n <= 0)
    {
        return false;
    }
    for(int i  = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(array[i] == array[j] && (j-i) != 1)
            {
                for(int k = i; k < j; k++)
                {
                    if(array[k] != array[i])
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int divide(string array[], int n, string divider)
{
    if(n <= 0)
    {
        return 0;
    }
    string stringHold;
    int index;
    int lowerCount = 0;
    for(int i = 1; i < n; i++)
    {
        stringHold = array[i];
        index = i-1;
        while(index >= 0 && array[index] > stringHold)
        {
            array[index+1] = array[index];
            index--;
        }
        array[index+1] = stringHold;
    }
    for(int i = 0; i < n; i++)
    {
        if(array[i] < divider)
        {
            lowerCount++;
        }
    }
    return lowerCount;
}

int main()
{
    string folks[10] = {"samwell", "jon", "jon", "margaery", "margaery", "daenerys",
    "tyrion", "sansa", "jon", "howard123"};
    string ppl[8] = {"bek", "jfbd", "ahjrkl", "sjfzghk", "ajzbk", "zndohia", "skzgkl", "sd"};
    string test[5] = {"3","5", "2", "4","2"};
    string test2[4] = {"sgsht", "SDsd", "wagrusb", "sgn"};
    string matchingVals1[5] = {"bob", "jane", "rob", "me", "rob"};
    string matchingVals2[5] = {"iphone", "iphone", "iphone","iphone","iphone"};
    assert(hasDuplicates(matchingVals1, 5));
    assert(!matchingValuesTogether(matchingVals1, 5));
    assert(hasDuplicates(matchingVals2, 5));
    assert(matchingValuesTogether(matchingVals2, 5));
    int i = locateMaximum(folks, 8);
    cerr << i << endl;
    int j = locateMaximum(ppl, 8);
    cerr << j << endl;
    int k = countSs(ppl, 8);
    cerr << k << endl;
    shiftLeft(folks, 8, 3, "foo");
    for(int i = 0; i < 8; i++)
    {
        cerr << folks[i] << endl;
    }
    assert(!isInDecreasingOrder(ppl, 8));
    assert(hasDuplicates(folks, 8));
    assert(!hasDuplicates(test2, 4));
    assert(matchingValuesTogether(folks, 10));
    assert(matchingValuesTogether(test2, 4));
    int e = divide(folks, 10, "rip");
    cerr << e << endl;
    for(int i = 0; i < 10; i++)
    {
        cerr << folks[i] << endl;
    }
    int l = divide(test, 5, "3");
    cerr << l << endl;
    for(int i = 0; i < 5; i++)
    {
        cerr << test[i] << endl;
    }
    int w = divide(matchingVals1, 5, "me");
    for(int i = 0; i < 5; i++)
    {
        cerr << matchingVals1[i] << endl;
    }
    cerr << w << endl;
    return 0;
}
