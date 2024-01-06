/*********************************************************************
** Program Filename: stalactites.h
** Author: Quinn Roth
** Date: 11/28/23
** Description: header for stalactite.h has stalactite class derived from event
** Input:none
** Output:none
*********************************************************************/
#ifndef STALACTITES_H
#define STALACTITES_H 
#include "event.h"

//Stalactites Interface
class Stalactites: public Event{
    private:

    public:
        Stalactites();
        string print_perception();
        char perform_function();
        bool arrow();

};

#endif
