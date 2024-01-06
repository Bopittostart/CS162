/*********************************************************************
** Program Filename: event.cpp
** Author: Quinn Roth
** Date: 11/28/23
** Description: event cpp file, has constructors and memebrr functions
** Input:none
** Output:none
*********************************************************************/
#include "event.h"

#include <iostream>

using namespace std;

//constructors and memeber function

Event::Event(){

}

void Event::set_name(char name){
    name = name;
}

//setter set event to null call in game


void Event::set_percept(string perception) {
    perception = perception;
}

void Event::set_function(char function){
    function = function;
}

char Event::get_name() {
    return this->name;
}

string Event::get_percept(){
    
    return print_perception();
}

char Event::get_function(){
    char thing;
    thing = perform_function();
    return thing;
}

bool Event::arrow(){
    
    return false;
}

//Event Implementation
