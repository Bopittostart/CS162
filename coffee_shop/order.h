/******************************************************
** Program: order.h
** Author: Quinn Roth
** Date: 11/14/23
** Description: header for order.cpp, has order class 
** Input: None
** Output: None
******************************************************/
#ifndef ORDER_H
#define ORDER_H 

#include <string>
#include <fstream>

using namespace std;
//order class
class Order
{
private:
	int id;
	string coffee_name;
	char coffee_size;
	int quantity;

public:
	Order();
	void set_id(const int);
	void set_coffee_name(const string);
	void set_coffee_size(const char);
	void set_quantity(const int);

    int get_id() const;
    string get_coffee_name() const;
    char get_coffee_size() const;
    int get_quantity() const;

    void populate_order(ifstream&);


	//need to include accessor functions and mutator functions for private member when appropriate
    //need to include constructors and destructors where appropriate
    //need to use 'const' when appropriate
};
#endif