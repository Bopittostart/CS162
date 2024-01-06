/******************************************************
** Program: prog.cpp
** Author: Quinn Roth
** Date: 11/14/23
** Description: setters and getters for order class 
** Input: None
** Output: order to file
******************************************************/
#include "order.h"

using namespace std;
//order class
Order::Order(){
}


//order getters
int Order::get_id() const{
    return this-> id;
}
string Order::get_coffee_name() const{
    return this-> coffee_name;
}
char Order::get_coffee_size() const{
    return this-> coffee_size;
} 
int Order::get_quantity() const{
    return this-> quantity;
}


//order setters
void Order::set_id(const int id){
    this -> id  = id;
}
void Order::set_coffee_name(const string coffee_name){
    this -> coffee_name = coffee_name;
}
void Order::set_coffee_size(const char size){
    this -> coffee_size = size;
}
void Order::set_quantity(const int quantity){
    this -> quantity = quantity;
}
/*********************************************************************
** Function: populate_order
** Description:populates the orders text file with order information
** Parameters: ifstream& filename
** Pre-Conditions: parameter exists, is called
** Post-Conditions: info is printed to file
*********************************************************************/
void Order::populate_order(ifstream& filename){
	filename >> this->id;
    filename >> this->coffee_name;
    filename >> this->coffee_size;
    filename >> this->quantity;
}



//function defintions from order.h goes here