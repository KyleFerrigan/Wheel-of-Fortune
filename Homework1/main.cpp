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
#include "GameState.cpp"
#include "GamePhrases.cpp"
using namespace std;

//Main
int main() {
    cout << "Starting the Game" << endl;
    GameState gs; //Starts the game
    GamePhrases gp(20);//Gets phrase list and sets size
    gs.setPhrase(gp.getPhrase());//Sets phrase into gamestate


    char gChar = ' ';
    int lettersCorrect = 0;
    bool userplaying = true;
    while (userplaying){
        bool turnActive = true;
        while(turnActive){// while P1 turn
            cout << "Current Board" << endl;
            cout << gs.getPhraseState() << endl; //print out current board
            cout << "Spin?" << endl; //TODO change to user prompt and a if statement
            gs.setPrizeMoney(gs.spin());

            cout << "What is your letter guess?";
            cin >> gChar;
            lettersCorrect = gs.guess(gChar); // Take in user char for guess
            if (lettersCorrect != 0){
                turnActive = false;
            }
            else{
                gs.setP1Money(gs.getP1Money()+(lettersCorrect * gs.getPrizeMoney()));
            }
        }

        cout << "continue playing?";
        string temp;
        cin >> temp;
        if (temp == "n" || temp == "no"){
            userplaying = false;
        }
    }
    return 0;
}
