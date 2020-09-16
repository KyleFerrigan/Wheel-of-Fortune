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
#include <stdio.h>
using namespace std;
