/*********************************************************************
** Program Filename: room.cpp
** Author: Quinn Roth
** Date: 11/28/23
** Description: room cpp file has constructor and memeber functions
** Input: none
** Output: none
*********************************************************************/
#include "room.h"

using namespace std;


//room constructors and memeber functions


Room::Room(){
	this->e = nullptr;

}

Room::Room(Event* new_event){
	this->e = nullptr;
}

char Room::print_event(){
	return this->e->get_name();
}


bool Room::arrow(){
	return this->e->arrow();
}

char Room::perform_function(){
	return this->e->get_function();
}

string Room::print_percept(){
	return this->e->get_percept();
}

void Room::set_event(Event* new_event){
   // if (this->e != nullptr){
		//delete this->e;
	//}
    this->e = new_event;
}

Event* Room::get_event() const {
		return this->e;
}

//Room Implementation
