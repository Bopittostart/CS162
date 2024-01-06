/*********************************************************************
** Program Filename: wumpus.cpp
** Author: Quinn Roth
** Date: 11/28/23
** Description: constructors and memeber function of wumpus class
** Input:
** Output:
*********************************************************************/
#include "wumpus.h"

#include <iostream>

using namespace std;

//constructors and memeber function

Wumpus::Wumpus() : Event('W'){}

string Wumpus::print_perception(){
    return "You smell a terrible stench";
}


char Wumpus::perform_function(){
    cout << "You enter the room. A wave of stench runs through your nose. You gag and cough. When you open your eyes and look forward you see the wumpus." << endl;
    cout << "You try to run but it is too late, he has awoken. His growl echos off the cave walls. As you run you look behind, but nothing is there." << endl;
    cout << "You look back ahead of you, he is blocking the entrance. Overwelming fear makes you fall to your knees. The thumping of his steps" << endl;
    cout << "sound like small earthquakes. Your brain is screaming at you to move, but your muscles won't budge. Finally he reaches you." << endl;
    cout << "He leans down, making his head level with your. His stench is nauseating. You think of your wife, you think of the promise you made her. That this would be the last adventure."<< endl;
    cout << "You think about how long it will take before she knows, how long will it take for her to move on, how long will it take till the next unfortunate adventurer to " << endl;
    cout << "find their way down here and be met with the same ending." << endl;
    cout << "None of that matters anymore, the wumpus has you. There is no escaping. " << endl;
    cout << "It is unknown wether you died from fear first or wether you were alive to experience how the wumpus prepares its meals." << endl;

    return 'W';
}

bool Wumpus::arrow(){
    return true;
}


Wumpus::~Wumpus(){
    
}

//Wumpus Implementation
