/******************************************************
** Program: menu.h
** Author: Quinn Roth
** Date: 11/14/23
** Description: header file for menu, has manu class,  
** Input: None
** Output:None
******************************************************/
#ifndef MENU_H
#define MENU_H 

#include <string>
#include <fstream>
#include "coffee.h"

using namespace std;
//menu class
class Menu {
  private:
    int num_coffee;
    Coffee* coffee_arr;
  public:
    //need to include accessor functions and mutator functions for private member when appropriate
    //need to include constructors, copy constructors, assignment operator overload,
    //and destructors where appropriate
    //need to use 'const' when appropriate
    Menu();
    Menu (int size);
    // Suggested functions:
    void set_coffee_arr(Coffee*);
    void set_num_coffee(int);
    void populate_coffee_arr(string);
    Coffee search_coffee_by_name(string name);
    float get_budget(); 
    void search_coffee_by_price(float budget); 
    int get_coffee_to_remove();
    Coffee get_coffee_to_add();
    void add_to_menu(Coffee& coffee_to_add); //add a coffee object into the Menu
    void remove_from_menu(int index_of_coffee_on_menu); //remove a coffee object from the Menu

    void display_menu();
    Coffee* get_coffee_arr();
    int get_num_coffee();
    ~Menu();
    Menu& operator=(const Menu &);
    Menu (const Menu &);
    // feel free to add more member functions
};

#endif