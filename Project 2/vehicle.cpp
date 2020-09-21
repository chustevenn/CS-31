#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout.setf(ios::fixed);  //display double to two decimal places
    cout.precision(2);
    string model;
    string type;
    double price = 0.0;
    cout << "Which vehicle would you like to order? "; //accept input for model
    getline(cin, model);
    cout << "Which kind would you like? ";
    getline(cin, type);  //accept input for type
    //Add to price depending on model and type
    if(model == "3" && type == "Long Range")
    {
        price += 47990;
    }
    if(model == "3" && type == "Performance")
    {
        price += 55990;
    }
    if(model == "S" && type == "Long Range")
    {
        price += 79990;
    }
    if(model == "S" && type == "Performance")
    {
        price += 99990;
    }
    if(model == "X" && type == "Long Range")
    {
        price += 84990;
    }
    if(model == "X" && type == "Performance")
    {
        price += 104990;
    }
    string color;
    cout << "What exterior color would you like? ";
    getline(cin, color); //accept input for color
    //add to price based on color
    if(color == "Black" && model == "3")
    {
        price += 500;
    }
    if(color == "Black" && model == "S")
    {
        price += 1000;
    }
    if(color == "Black" && model == "X")
    {
        price += 1000;
    }
    if(color == "Blue" && model == "3")
    {
        price += 1000;
    }
    if(color == "Blue" && model == "S")
    {
        price += 1500;
    }
    if(color == "Blue" && model == "X")
    {
        price += 1500;
    }
    if(color == "Grey" && model == "3")
    {
        price += 1000;
    }
    if(color == "Grey" && model == "S")
    {
        price += 1500;
    }
    if(color == "Grey" && model == "X")
    {
        price += 1500;
    }
    if(color == "Red" && model == "3")
    {
        price += 1500;
    }
    if(color == "Red" && model == "S")
    {
        price += 2500;
    }
    if(color == "Red" && model == "X")
    {
        price += 2500;
    }
    string wheels;
    cout << "Which wheels would you like? ";
    getline(cin,wheels); //accept input for wheel size
    //add to price depending on wheel size
    if(wheels == "19" && model == "3")
    {
        price += 1500;
    }
    if(wheels == "21" && model == "S")
    {
        price += 2500;
    }
    if(wheels == "22" && model == "X")
    {
        price += 5500;
    }
    string leather;
    cout << "Want leather interior? ";
    getline(cin, leather); //accept input for leather choice
    //add to price based on leather choice
    if(leather == "Yes")
    {
        price += 1000;
    }
    string autopilot;
    cout << "Want Auto-Pilot? ";
    getline(cin, autopilot); //accept input for autopilot choice
    //add to price based on autopilot choice
    if(autopilot == "Yes")
    {
        price += 6000;
    }
    //initialize series of booleans representing if each input was provided correctly
    bool mod = true, kind = true, col = true, wh = true, leath = true, autop = true;
    //output error message and set respective boolean to false if incorrect input is provided
    if(model != "3" && model != "S" && model != "X")
    {
        cout << "Error - Incorrect model choice." << endl;
        mod = false;
        return 0;
    }
    if(type != "Performance" && type != "Long Range")
    {
        cout << "Error - Incorrect kind choice." << endl;
        kind = false;
        return 0;
    }
    if(color != "White" && color != "Black" && color != "Grey" && color != "Blue" && color != "Red")
    {
        cout << "Error - Incorrect color choice." << endl;
        col = false;
        return 0;
    }
    if(model == "3")
    {
        if(wheels != "18" && wheels != "19")
        {
            cout << "Error - Incorrect wheel value." << endl;
            wh = false;
            return 0;
        }
    }
    if(model == "S")
    {
        if(wheels != "19" && wheels != "21")
        {
            cout << "Error - Incorrect wheel value." << endl;
            wh = false;
            return 0;
        }
    }
    if(model == "X")
    {
        if(wheels != "20" && wheels != "22")
        {
            cout << "Error - Incorrect wheel value." << endl;
            wh = false;
            return 0;
        }
    }
    if(leather != "Yes" && leather != "No")
    {
        cout << "Error - Incorrect leather choice." << endl;
        leath = false;
        return 0;
    }
    if(autopilot != "Yes" && autopilot != "No")
    {
        cout << "Error - Incorrect autopilot choice." << endl;;
        leath = false;
        return 0;
    }
    //output end message if all inputs are correct
    if(mod && kind && col && wh && leath && autop)
    {
        cout << "Enjoy your new $" << price << " " << color << " Model " << model << "!" << endl;
        return 0;
    }
}
