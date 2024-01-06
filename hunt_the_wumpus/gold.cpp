/*********************************************************************
** Program Filename: gold.cpp
** Author: Quinn Roth
** Date: 11/28/23
** Description: has memeber variables and constructors of gold
** Input:none
** Output:percept encounter
*********************************************************************/
#include "gold.h"

#include <iostream>

using namespace std;

//constructors and memeber function


Gold::Gold() : Event('G'){}

string Gold::print_perception(){
    return "You see a glimmer neaby";
}

char Gold::perform_function(){
   
    cout << "That glimmer caught your eye. You enter the room and find a pile of gold next to a an unlucky adventurers skeleton. Return to the rope you entered from to escape!" << endl;
       
    return 'G';
   
}

bool Gold::arrow(){
    return false;
}

Gold::~Gold(){

}


//Gold Implementation
