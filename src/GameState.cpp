//  GameState.cpp
//
//  Created by Kyle Ferrigan on 9/12/20.

/* Class GameState
 This class is responsible for storing information about the state of the current game being played. To play, a player is chosen to “spin the wheel”. Spinning the wheel determines a random prize money amount. Once the prize money for the spin is determined, the player is allowed to guess a letter in the phrase. If correct, the player will earn the prize money times the number of locations the letter appeared in the phrase. The player gets to continue guessing letters until they incorrectly guess. If they incorrectly guess, play will continue with the other player. Before each guess, the player will spin the wheel to determine that guesses prize money amount.
 State: container of prize money, current phrase being played, current state of the guessed phrase, container of incorrectly guessed letters, the names of the two players, the dollar value earned by each player.
 Behavior: plays a game of Wheel of Fortune as discussed above using appropriate methods to modify state. Prize money container is populated via an input file (ifstream parameter that refers to an open input file). */

//Include Statements
#include "GameState.h"
#include <string>
#include <iostream>
#include <time.h>
using namespace std;

GameState::GameState(){
    //init variables
    _player1Money = 0;
    _player2Money = 0;
    _curPrizeMoney = 0;
    _curPhrase = "";
    _phraseState = "";
    _size = 0;

    //Fill in Prize Money
    ifstream infile("C:\\Users\\KyleF\\CLionProjects\\HW1\\PrizeMoney.txt");//Change this to the filepath of Money to use.
    if (!infile){
        cout << "Cannot find File" << endl;
        exit(-1);
    }
    for (int i = 0; !infile.eof(); i++){
        infile >> _prizeMoneyData[i]; //push money data from file to variable
        _size++; //keep track of how many elements the data file has
    }
    infile.close();
}

//set current phrase and phrase state
void GameState::setPhrase(string phraseIn){
    //Set the Current Phrase
    _curPhrase = phraseIn;
    _phraseState = "";
    //Also sets the Phrasestate
    for (int i = 0; i < _curPhrase.length(); i++){
        if (_curPhrase.at(i) == ' '){ //if blank space make the phrase state also blank
            _phraseState.append(" ");
        }
        else{// if there is a letter or number make it a star
            _phraseState.append("*");
        }
    }
}

//Return Prize Money
int GameState::spin(){
    srand(time(NULL)); //set random seed
    return _prizeMoneyData[(rand() % _size)] ; //Return prize money rng from list
}

//Count how many letters correct & change phrase state
int GameState::guess(char uInput){
    int count = 0;
    for (int i = 0; i < _curPhrase.size(); i++){
        if (uInput == _curPhrase.at(i)){
            _phraseState.at(i) = _curPhrase.at(i);
            count++;
        }
    }
    if (count == 0){
        _incorrectChars[_ttlIncorrect] = uInput; //add incorrect letters to list
        _ttlIncorrect++;
    }
    return count; //return the amount of letters correct
}

