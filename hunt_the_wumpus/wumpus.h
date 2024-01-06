/*********************************************************************
** Program Filename: wumpus.h
** Author: Quinn Roth
** Date: 11/28/23
** Description: header file for wumpus.cpp holds wumpus class
** Input:none
** Output: none
*********************************************************************/
#ifndef WUMPUS_H
#define WUMPUS_H 
#include "event.h"

//Wumpus Interface
class Wumpus: public Event{
    private:
        
    public:
        Wumpus();
        ~Wumpus();
        string print_perception();
        char perform_function();
        bool arrow();
};


#endif