//  GamePhrases.hpp
//  Homework1
//
//  Created by Kyle Ferrigan on 9/12/20.

/*Class GamePhrases
 This class is a container of game phrases. When an object of this type is instantiated, it must be supplied the size of the container. The size of the container will not change during the life of the object.
State: container of phrases
Behavior: populates the phrases via an input file (ifstream parameter that refers to an open input file), accesses a random phrase from the container */

#ifndef GamePhrases_hpp
#define GamePhrases_hpp

//Include Statements
#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;

class GamePhrases{
private:
    int _size;
    string _phrase;
    
public:
    //Constructor
    GamePhrases(int phraseSize){_size = phraseSize;}
    //Setter
    void setPhrases(string input){_phrase = input;} //TODO Change from string to file
    //Getter
    string getPhrases(){return _phrase;}
    
    
};

#endif /* GamePhrases_hpp */
