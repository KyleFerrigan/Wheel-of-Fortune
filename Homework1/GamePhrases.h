//  GamePhrases.h
//  Homework1
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
#include <fstream>
#include <stdio.h>
using namespace std;

class GamePhrases{
private:
    int _size;
    string _phrases[0]; //this works but I dont know why
    
public:
    //Constructor
    GamePhrases(int phraseSize){string _phrases[phraseSize];}//Size set correctly
    //Setter
    void setPhrases(string phrase,int pNum){_phrases[pNum] = phrase;} //TODO Change from string to file, add error handling for larger than phrase size, make input argument just a file name." this will need to go into cpp file since it will be long.
    //Getter
    string getPhrases(int pNum){return _phrases[pNum];} //This beahvior should be fine even when the file
    
    
};

#endif /* GamePhrases_h */
