/*********************************************************************
** Program Filename: bats.cpp
** Author: Quinn Roth
** Date: 11/28/23
** Description: bat cpp file has constructor and member functions for bat class
** Input:none
** Output: percept, and encounter
*********************************************************************/
#include "bats.h"

#include <iostream>

using namespace std;

//constructors and memeber function



Bats::Bats() : Event('B'){}

string Bats::print_perception(){
     return "You hear wings flapping";
}

char Bats::perform_function(){
   
   cout << "The bats stardled at your sudden appearance create a storm of wings and screaches. You are left confused." << endl;
  
   return 'B';
   
}
bool Bats::arrow(){
    return false;
}

//Bats Implementation
