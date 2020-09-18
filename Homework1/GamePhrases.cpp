//  GamePhrases.cpp
//  Homework1
//
//  Created by Kyle Ferrigan on 9/12/20.

/*Class GamePhrases
 This class is a container of game phrases. When an object of this type is instantiated, it must be supplied the size of the container. The size of the container will not change during the life of the object.
State: container of phrases
Behavior: populates the phrases via an input file (ifstream parameter that refers to an open input file), accesses a random phrase from the container */
#include "GamePhrases.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
using namespace std;

GamePhrases::GamePhrases(int phraseAmnt){
    //_phrases = new string[phraseAmnt];
    ifstream infile("C:\\Users\\KyleF\\CLionProjects\\HW1\\GamePhrase.txt");//Change this to the filepath of phrases to use.
    if (!infile){
        cout << "Cannot find File" << endl;
        exit(-1);
    }
    _size = 0;
    for (int i = 0; !infile.eof(); i++){
        infile >> _phrases[i];
        _size++;
    }
    infile.close();
}
string GamePhrases::getPhrase(){
    srand(time(NULL));
    int temp =  rand() % _size;
    cout << "DEBUG " << temp << endl; //TODO Delete this line
    return _phrases[temp];
}
