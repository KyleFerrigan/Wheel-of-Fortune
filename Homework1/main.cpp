//  main.cpp
//  Homework1
//
//  Created by Kyle Ferrigan on 9/11/20.

/* Main
Main should start by constructing a GamePhrases object making sure the container is populated with phrases. Main should then prompt the user to play a game of Wheel of Fortune using a sentinel controlled loop until the user no longer chooses to play. If the user chooses to play, a GameState object should be instantiated. Main will need to pass the random word to the GameState object prior to the start of play. Main will transfer control to GameState once play begins. When a new game starts, a new GameState object must be instantiated and a new random phrase chosen. Once the user chooses to exit, each player’s name and total prize money should be displayed. */

//Include Statements
#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include "GamePhrases.cpp"
#include "GameState.cpp"

using namespace std;

//Main
int main(int argc, const char * argv[]) {
    GamePhrases gp(5);
    gp.setPhrases("hi",4);
    gp.setPhrases("ho",3);
    cout << gp.getPhrases(4) << endl;
    cout << gp.getPhrases(3) << endl;
    cout << gp.getPhrases(4) << endl;
    
    
    return 0;
}
