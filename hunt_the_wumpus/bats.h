/*********************************************************************
** Program Filename: bats.h
** Author: Quinn Roth
** Date: 11/28/23
** Description: header file for bats.cpp, holds the bat class which is derived from event
** Input: none
** Output:none
*********************************************************************/
#ifndef BATS_H
#define BATS_H 
#include "event.h"
//Bats Interface
class Bats: public Event{

    private:
      

    public:
        Bats();
        string print_perception();
        char perform_function();
        bool arrow();
      
    

};

#endif