/*********************************************************************
** Program Filename: gold.h
** Author: Quinn Roth
** Date: 11/28/23
** Description: header file for hold.cpp 
** Input:none
** Output:none
*********************************************************************/
#ifndef GOLD_H
#define GOLD_H 
#include "event.h"

//Gold Interface
class Gold: public Event{
    private:
        
    public:
        Gold();
        ~Gold();
        string print_perception();
        char perform_function();
        bool arrow();

};

#endif