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
    int _player1Money;
    int _player2Money;
    int _curPrizeMoney;
    int _prizeMoneyData[500]; //Store Prize money data from file
    string _curPhrase;
    string _phraseState;
    int _size; //How big the _prizeMoneyData is
    int _ttlIncorrect = 0;
    char _incorrectChars[26];

public:
    //Constructor
    GameState();
    
    //Game vars
    int spin();//start turn and rng the input file for the prize money
    int guess(char uInput); //add logic in cpp file, turn ends if user incorrectly guess if correct multiply the number of correct letters by prize money
    void setPrizeMoney(int prizeMoneyIn){_curPrizeMoney = prizeMoneyIn;} //setter for prize money
    int getPrizeMoney(){return _curPrizeMoney;}//getter for prize money
    void setP1Money(int playerMoneyIn){_player1Money = playerMoneyIn;} //setter for player 1's money
    int getP1Money() {return _player1Money;} //getter for player 1's money
    void setP2Money(int playerMoneyIn){_player2Money = playerMoneyIn;} //setter for player 2's money
    int getP2Money() {return _player2Money;} //getter for player 2's money
    void setPhrase(string phraseIn); //setter for the phrase
    string getPhraseState(){return _phraseState;} //getter for the phrase state
        
};

#endif /* GameState_h */
