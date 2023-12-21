/*
* Author: Ultador
* Project: Final Project Week 2/3
* Date: 4/27/2022
* CIS 127 Section 6280
* Purpose: Starting point for skill trainer for power management in Star Wars: Squadrons
* NOTE: Placeholders used to facilitate construction of functions without requiring the next two to three weeks of work to be done first
* NOTE: Contains a marked, commented out section that is used for testing to prevent infinite loops if conditions are set wrong, left in to facilitate later versions.
* Special thanks to Discord User @Alcom Isst for all his help in getting the numbers needed for this as well as being a sounding board 
*   for logic and bugs
*/
//Placeholders used to allow for proof of concept of BuildBoost and SpendBoost functions
//  Output is not the cleanest, but this is deemed irrelevant as end goal is to have GUI and this is proof of concept
//  only SLAM engine ships used to remove need to track boost decay rather than just spending boost



#include "boostManagement.h"
#include "generalShips.h"
#include <exception>
#include <Windows.h>
#include <mmsystem.h>

int main()
{
    //variable declaration

    chrono::time_point<chrono::system_clock> timerStart, timerEnd;
    chrono::duration<double> timeElapsed;
    string enginesKey = "q";
    string weaponsKey = "w";
    string shieldsKey = "e";
    string boostKey = "Space";
    string driftKey = "Left Shift";
    string escapeKey = "p";
    string input;
    string previousInput;
    double timeTaken;
    double boostTank = 1.00;
    const double BOOST_TANK_MAX = 1.00;
    double boostDecayRate = .105;
    string shipTypeInput;
    bool powerInEngines;
    bool boosting;
    bool inLoop = true;
    //loop failsafe variable
    //unsigned short int breakaway = 0;

    //declaration of keybinds
    cout << enginesKey << " is Max engines" << endl;
    cout << weaponsKey << " is Max weapons" << endl;
    cout << shieldsKey << " is Max shields" << endl;
    cout << boostKey << " is the Go Fast Button" << endl;
    cout << driftKey << " is the Go Sideways Button" << endl;
    cout << escapeKey << " ends the session" << endl;
    
    try
    {
        cout << "Only SLAM Engine Shielded ships are available in this version" << endl << "Press Y for a Y-wing, or any other key for another SLAM ship.";
        cin >> shipTypeInput;
        if (isalpha(shipTypeInput.at(0)))
        {
            generalShips userShip(shipTypeInput);

            cout << "Power is in Engines, go as long as you can. \n BEGIN!" << endl;
            //input loop
            powerInEngines = true;
            boosting = false;
            timerStart = chrono::system_clock::now();
            do
            {

                if (boosting == true)
                {
                    timerEnd = chrono::system_clock::now();
                    timeElapsed = timerEnd - timerStart;
                    boostLoss(boostTank, boostDecayRate, timeElapsed.count());
                    timerStart = chrono::system_clock::now();
                    
                }

                else if (powerInEngines == true && boosting == false)
                {
                    timerEnd = chrono::system_clock::now();
                    timeElapsed = timerEnd - timerStart;
                    boostGain(boostTank, calcBuildRate(boostTank, userShip.getTotalChargeTime()), timeElapsed.count());
                    timerStart = chrono::system_clock::now();
                    
                }

                if (GetKeyState('Q') & 0x8000)
                {
                    powerInEngines = true;
                    cout << endl << "Boost tank is at " << boostTank * 100 << " percent";
                }
                if (GetKeyState(VK_SPACE) & 0x8000)
                {
                    boosting = true;
                }
                if (GetKeyState(VK_SHIFT) & 0x8000)
                {
                    boosting = false;
                    cout << endl << "Boost tank is at " << boostTank * 100 << " percent";
                }
                if (GetKeyState('P') & 0x8000)
                    inLoop = false;
                if (GetKeyState('W') & 0x8000)
                {
                    powerInEngines = false;
                    cout << endl << "Boost tank is at " << boostTank * 100 << " percent";
                }
                if (GetKeyState('E') & 0x8000)
                {
                    powerInEngines = false;
                    cout << endl << "Boost tank is at " << boostTank * 100 << " percent";
                }
                if (boostTank == 0)
                {
                    cout << "Out of boost, out of life. \n GAME OVER!";
                    break;
                }

                //loop failsafe
                /*
                //safety mechanism to prevent infinite loops while testing will comment out later
                breakaway++;
                //cout << breakaway;
                if (breakaway > 10)
                {
                    cout << "Breaking loop";
                    break;
                }
                */
            } while (inLoop);

        }
        else
        {
            generalShips userShip();
            throw;
        }
            


    }
    catch (...)
    {
        cout << endl << "There was an error";
    }

    
    
    /*generalShips ship1("Y");
    cout << ship1.getTotalChargeTime();
    cout << endl << ship1.getBoostPercent();
    */



    return 0;
}

