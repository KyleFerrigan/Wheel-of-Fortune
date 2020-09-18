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


    char gChar = ' '; //Guessing Character
    int lettersCorrect = 0;
    bool userplaying = true; //sentinel value for outer loop that controls the game
    bool p1 = true; //player 1's turn
    bool p2 = false; //player 2's turn
    string temp1, temp2; //temp values for cin's

    while (userplaying){
        bool turnActive = true;
        while(turnActive){
            cout << "\nCurrent Board" << endl;
            //Print out current board
            cout << gs.getPhraseState() << endl;

            //Ask user if they want to spin
            cout << "Spin? (y/n)" << endl;
            cin >> temp1;
            if (temp1 == "y"){gs.setPrizeMoney(gs.spin());}
            cout << "Prize Money: "<< gs.getPrizeMoney() << endl;

            //Ask user what letter to guess
            cout << "What is your letter guess?: ";
            cin >> gChar;
            lettersCorrect = gs.guess(gChar); // Take in user char for guess

            //If User Guesses Incorrectly Change turns
            if (lettersCorrect == 0){
                if (p1 == true) {//if player 1's turn make it player 2's turn
                    p1 = false;
                    p2 = true;
                    cout << "Player 2 Turn" << endl;
                }
                else{ //if player 2's turn make it player 1's turn
                    p1 = true;
                    p2 = false;
                    cout << "Player 1 Turn" << endl;
                }
                //change turns
                turnActive = false;
            }
            //If user guesses correctly multiply number correct by prize money and add to their winnings.
            else{
                if (p1= true) {
                    gs.setP1Money(gs.getP1Money()+(lettersCorrect * gs.getPrizeMoney()));
                }
                else{
                    gs.setP2Money(gs.getP2Money()+(lettersCorrect * gs.getPrizeMoney()));
                }
            }
        }

        //Ask user if they want to continue playing
        cout << "\nContinue playing? (y/n): ";
        cin >> temp2;
        if (temp2 == "n"){
            //print out user name and money
            cout << "Player 1" << endl;
            cout << "Money: " << gs.getP1Money() << endl;
            cout << "Player 2" << endl;
            cout << "Money: " << gs.getP2Money() << endl;
            userplaying = false; //Switch sentinel value
        }
    }
    return 0;
}
