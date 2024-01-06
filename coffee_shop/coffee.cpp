/******************************************************
** Program: coffee.cpp
** Author: Quinn Roth
** Date: 11/14/23
** Description: coffee setters and getters 
** Input: None
** Output: display coffee
******************************************************/
#include "coffee.h"

using namespace std;
//default destructor
Coffee::Coffee(){
}
//getters
string Coffee::get_name() const{
    return this-> name;
}
float Coffee::get_small_cost() const{
    return this-> small_cost;
}
float Coffee::get_medium_cost() const{
    return this-> medium_cost;
}
float Coffee::get_large_cost() const{
    return this-> large_cost;
}


//setters
void Coffee::set_name(const string name){
    this -> name = name;
}
void Coffee::set_small_cost(const float small_cost){
    this -> small_cost = small_cost;
}
void Coffee::set_medium_cost(const float medium_cost){
    this -> medium_cost = medium_cost;
}
void Coffee::set_large_cost(const float large_cost){
    this -> large_cost = large_cost;
}
void Coffee::populate_coffee(ifstream& filename){
	filename >> this->name >> this->small_cost >> this->medium_cost  >> this->large_cost;
}
//prints the coffee details
void Coffee::display_coffee(){
	cout << "Name: " << this->name << endl;
	cout << "Small: " << this-> small_cost << endl;
	cout << "Medium: " << this->medium_cost << endl;
	cout << "Large: " << this->large_cost << endl;
	cout << endl;
}

//function defintions from coffee.h goes here