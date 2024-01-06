/*********************************************************************
** Program Filename: event.h
** Author: Quinn Roth
** Date: 11/28/23
** Description: the header file for event.cpp, holds the event class
** Input:
** Output:
*********************************************************************/
#ifndef EVENT_H
#define EVENT_H 
#include <string>
using namespace std;

//Event Interface
//Note: this must be an abstract class!

class Event{

protected:
	char name;
	string perception;

public:
	Event();
	Event(char name) : name(name){}
	


	virtual string print_perception() = 0;
	virtual char perform_function() = 0;
	void set_name(char name);
	void set_percept(string perception);
	void set_function(char function);
	char get_name();
	string get_percept();
	char get_function();
	virtual bool arrow();
	

};
#endif