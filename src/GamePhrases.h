//  GamePhrases.h
//
//  Created by Kyle Ferrigan on 9/12/20.

/*Class GamePhrases
 This class is a container of game phrases. When an object of this type is instantiated, it must be supplied the size of the container. The size of the container will not change during the life of the object.
State: container of phrases
Behavior: populates the phrases via an input file (ifstream parameter that refers to an open input file), accesses a random phrase from the container */

#ifndef GamePhrases_h
#define GamePhrases_h

//Include Statements
#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;

class GamePhrases{
private:
    int _size = 0;
    string _phrases[100]; //Conservative Max Value
public:
    //Default constructor
    GamePhrases(int PhraseAmnt);
    //Getter
    string getPhrase();
};

#endif /* GamePhrases_h */
