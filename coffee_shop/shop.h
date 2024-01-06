/******************************************************
** Program: shop.h
** Author: Quinn Roth
** Date: 11/14/23
** Description: header file for Shop, has the shop class,  
** Input: None
** Output: None
******************************************************/
#ifndef SHOP_H
#define SHOP_H

#include <string>
#include <fstream>
#include <iostream>
#include "menu.h"
#include "order.h"

using namespace std;
// class shop
class Shop {
  private:
    Menu m;
    string phone;
    string address; 
    float revenue;      //shop revenue
    Order *order_arr;   //order array
    int num_orders;     //number or orders
  public:
    //need to include accessor functions and mutator functions for private member when appropriate
    //need to include constructors and destructors where appropriate
    //need to use 'const' when appropriate

    //Suggested functions
    Shop();
    void populate_order_arr(Order the_order);
    Order get_order();
    void load_data(); //reads from files to correctly populate coffee, menu, etc.
    void view_shop_detail();
    void add_to_menu();
    void remove_from_menu();
    void search_by_name();
    void search_by_price();
    void place_order();
    Shop clone_shop();

    ~Shop();
    Shop& operator=(const Shop &);
    Shop (const Shop &);
    
};
    void populate_menu_arr(Menu*);


#endif
