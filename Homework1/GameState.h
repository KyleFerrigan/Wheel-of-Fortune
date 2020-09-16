//  GameState.h
//  Homework1
//
//  Created by Kyle Ferrigan on 9/12/20.

/* Class GameState
 This class is responsible for storing information about the state of the current game being played. To play, a player is chosen to “spin the wheel”. Spinning the wheel determines a random prize money amount. Once the prize money for the spin is determined, the player is allowed to guess a letter in the phrase. If correct, the player will earn the prize money times the number of locations the letter appeared in the phrase. The player gets to continue guessing letters until they incorrectly guess. If they incorrectly guess, play will continue with the other player. Before each guess, the player will spin the wheel to determine that guesses prize money amount.
 State: container of prize money, current phrase being played, current state of the guessed phrase, container of incorrectly guessed letters, the names of the two players, the dollar value earned by each player.
 Behavior: plays a game of Wheel of Fortune as discussed above using appropriate methods to modify state. Prize money container is populated via an input file (ifstream parameter that refers to an open input file). */

#ifndef GameState_h
#define GameState_h

//Include Statements
#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;
class GameState{
private:
    int _playerMoney;
    int _prizeMoney; //When spin is called use a random number generator to pick from ifstream.
    bool _endOfTurn;//use this to reset prize money/ cash out prize money/ goto next player
    
public:
    //Constructor
    GameState(); //Hardcode the name of the ifstream file for prizemoney or ask for it in default constructor? Set player money to 0, init prize money.
    
    //Game vars
    int spin();//add logic in cpp file, start turn and rng the input file for the prize money
    int guess(char uInput); //add logic in cpp file, turn ends if user incorrectly guess if correct multiply the number of correct letters by prize money
    
    
};

#endif /* GameState_h */
