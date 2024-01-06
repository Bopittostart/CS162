/*********************************************************************
** Program Filename: room.h
** Author: Quinn Roth
** Date: 11/28/23
** Description: the header file for room.cpp, has the room class
** Input: none
** Output:none
*********************************************************************/
#ifndef ROOM_H
#define ROOM_H 

#include "event.h"

using namespace std;

//Room Interface
//Note: Each room may be empty or has an event (bat, gold, pit, or wumpus);
//		Use event polymorphically

class Room
{
private: 

	Event *e;

public:
	Room();
	Room(Event* new_event);
	void set_event(Event *new_event);
	string print_percept();
	char perform_function();
	char print_event();
	Event* get_event() const;
	bool arrow();
	
    

};

#endif