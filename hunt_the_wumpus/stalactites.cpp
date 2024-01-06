/*********************************************************************
** Program Filename: stalactites.cpp
** Author: Quinn Roth
** Date: 11/28/23
** Description: has memeber functions and constructors for 
** Input: none
** Output: percept and encounter 
*********************************************************************/
#include "stalactites.h"

#include <iostream>

using namespace std;

//constructors and memeber function



Stalactites::Stalactites() : Event('S'){}


string Stalactites::print_perception(){
   return "You hear water dropping";
}

char Stalactites::perform_function(){
   int randNum = rand() % 2;
   if(randNum == 1){
      cout << "A drop of water lands on your head, you look up and the last thing you see is a stalactite falling, you die" << endl;
      return 'S';
   }
   else{
      cout << "A drop of water lands on your head, you look up and see a stalactite. Hopefully it doesn't fall on you." << endl;
      return 'X';
   }
}
bool Stalactites::arrow(){
    return false;
}

//Stalactites Implementation
