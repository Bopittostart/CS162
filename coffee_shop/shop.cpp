/******************************************************
** Program: shop.cpp
** Author: Quinn Roth
** Date: 11/14/23
** Description: Shop file, holds shop functions, and big three for shop
** Input: many choices
** Output:results from those choices
******************************************************/
#include "shop.h"

using namespace std;

//function defintions from shop.h goes here
/*********************************************************************
** Function:load_data
** Description: loads data into objects and arrays
** Parameters: none
** Pre-Conditions: program running
** Post-Conditions: order array created, coffee array populated
*********************************************************************/
void Shop::load_data(){
	//reads from files to correctly populate coffee, menu, etc.
	//Your code goes here: 

	revenue = 0;
	string filename;
	filename = "menu.txt";
	this->m.populate_coffee_arr(filename);
	this->order_arr = new Order [100];
	//populate_order_arr();
	

//	cout << "Shop::load_data() not implemented..." << endl;

	return;
}
/*********************************************************************
** Function: Shop
** Description: defualt constructor
** Parameters: none
** Pre-Conditions: program running
** Post-Conditions: order_arr = NULL
*********************************************************************/
Shop::Shop(){
	this->order_arr = NULL;
}
/*********************************************************************
** Function: ~Shop
** Description: deconstructor
** Parameters: none
** Pre-Conditions: programm running
** Post-Conditions: if order array is not null it is now null
*********************************************************************/
Shop::~Shop(){
	if(this->order_arr != NULL){
		delete[] this->order_arr;
		this->order_arr = NULL;
	}
}
/*********************************************************************
** Function: Shop::operator
** Description:assignment operator
** Parameters: Shop& s
** Pre-Conditions: clone shop
** Post-Conditions: shop is cloned
*********************************************************************/
Shop& Shop::operator=(const Shop& s){
	if(this == &s){
		return *this;
	}
	if (this ->order_arr != NULL){
		delete[] this ->order_arr;
		this->order_arr = NULL;

	}

	this->num_orders = s.num_orders;
	this->order_arr = new Order [this->num_orders];
	for(int i = 0; i < this->num_orders; i++){
		this->order_arr[i] = s.order_arr[i];
	}
	return *this;
}
/*********************************************************************
** Function:shop
** Description: copy constructor
** Parameters: Shop& s
** Pre-Conditions: clone shop
** Post-Conditions: shop cloned
*********************************************************************/
Shop::Shop(const Shop& s){
	this->num_orders = s.num_orders;
	this->order_arr = new Order [this->num_orders];
	for(int i = 0; i < this->num_orders; i++){
		this->order_arr[i] = s.order_arr[i];
	}
}

/*********************************************************************
** Function:view_shop_detail
** Description:prints the details of the shop
** Parameters: none
** Pre-Conditions: first selection is called
** Post-Conditions: shop has been printed
*********************************************************************/
void Shop::view_shop_detail(){
	//handle "View shop detail" option
	//print shop address, phone number, revenue, menu, and order
	//Your code goes here: 
	ifstream shop_info;
	shop_info.open("shop_info.txt");
	if(shop_info.fail()){
        cout << "error shop_info.txt does not exist" << endl;
		return;
	}
	getline(shop_info, phone);
	getline(shop_info, address);
	shop_info.close();
	ifstream orders_info;
	orders_info.open("orders.txt");
	if(orders_info.fail()){
        cout << "error orders.txt does not exist" << endl;
		return;
	}
	
	cout << "Address: " << address << endl;
	cout << "Phone Number: " << phone << endl;
	cout << "Revenue: " << revenue << endl; 
	cout << "Menu: " << endl;
	this->m.display_menu();

	orders_info.close();
	//cout << "Shop::view_shop_detail() not implemented..." << endl;


	return;
}


/*********************************************************************
** Function:add_to_menu
** Description:adds a coffee to the menu
** Parameters: none
** Pre-Conditions: add coffe to menu selected
** Post-Conditions: coffee added to menu
*********************************************************************/
void Shop::add_to_menu(){
	//handle "Add coffee to menu" option
	//Hint: call Menu::add_to_menu(Coffee& coffee_to_add);
	//Your code goes here: 
	Coffee coffee_to_add = m.get_coffee_to_add();
	m.add_to_menu(coffee_to_add);


	//cout << "Shop::add_to_menu() not implemented..." << endl;

	return;
}
/*********************************************************************
** Function: remove_from_menu
** Description: removes a item from the menu
** Parameters: none
** Pre-Conditions: remove from menu was selected
** Post-Conditions: item is removed from menu
*********************************************************************/
void Shop::remove_from_menu(){
	//handle "Remove coffee from menu" option
	//Hint: call Menu::remove_from_menu(int index_of_coffee_on_menu);
	//Your code goes here: 
	int index_of_coffee_on_menu = m.get_coffee_to_remove();
	if(index_of_coffee_on_menu != -1){
		m.remove_from_menu(index_of_coffee_on_menu);
	}
	else {
		cout << "coffee not recognised" << endl;
	}
	//cout << "Shop::remove_from_menu() not implemented..." << endl;

	return;
}

/*********************************************************************
** Function:search_by_name
** Description: searches for a coffee by a given name and displays the information
** Parameters: none
** Pre-Conditions: is selected
** Post-Conditions: none
*********************************************************************/
void Shop::search_by_name(){
	//handle "Search by coffee name" option
	//Hint: call Menu::search_coffee_by_name(string name);
	//Your code goes here:
	string name; 
	cout << "What Coffee would you like to search for?" <<endl;
	cin >> name;
	Coffee found = m.search_coffee_by_name(name);
	cout << "Results: " << endl;
	cout << "Name: " << found.get_name() << endl;
	cout << "Small: " << found.get_small_cost() << endl;
	cout << "Medium: " << found.get_medium_cost() << endl;
	cout << "Large: " << found.get_large_cost() << endl;
	cout << endl;

	//cout << "Shop::search_by_name() not implemented..." << endl;

	return;
}
/*********************************************************************
** Function: search_by_price
** Description: searches for all menu items with a price below the given budget
** Parameters: none
** Pre-Conditions: is selected
** Post-Conditions: none
*********************************************************************/
void Shop::search_by_price(){
	//handle "Search by coffee price" option
	//Hint: call Menu::search_coffee_by_price(float budget);
	//Your code goes here: 
	float budget = m.get_budget();
	if(budget < 0){
		cout << "Invalid please pick a number greater than 0" << endl;
	return;
	}
	else {
		m.search_coffee_by_price(budget);
	}


	//cout << "Shop::search_by_price() not implemented..." << endl;

	return;
}
/*********************************************************************
** Function: populate_order_arr
** Description: populates order array
** Parameters: object the_order of class order
** Pre-Conditions: is called
** Post-Conditions: order array populated
*********************************************************************/
void Shop::populate_order_arr(Order the_order){

	this->order_arr[num_orders].set_id(the_order.get_id());
	this->order_arr[num_orders].set_coffee_name(the_order.get_coffee_name());
	this->order_arr[num_orders].set_coffee_size(the_order.get_coffee_size());
	this->order_arr[num_orders].set_quantity(the_order.get_quantity());
	//return float in place order
}
/*********************************************************************
** Function: get_order
** Description: gets the order by asking the user questions and saving them to an object
** Parameters: none
** Pre-Conditions: is called
** Post-Conditions: the_order is returned
*********************************************************************/
Order Shop::get_order(){
	Order the_order;
	int id;
	string name;
	char size;
	int quantity;
	Coffee* coffees = this->m.get_coffee_arr();
	
	
	this->m.display_menu();
	cout << "What drink would you like? Enter 1-" << m.get_num_coffee() << endl;
	cin >> id;
	the_order.set_id(id);
	the_order.set_coffee_name(coffees[id-1].get_name());
	cout << "What size would you like? S, M, L" << endl;
	cin >> size;
	the_order.set_coffee_size(size);
	cout << "How many would you like" << endl;
	cin >> quantity;
	the_order.set_quantity(quantity);
return the_order;
}

/*********************************************************************
** Function: place_order
** Description: adds the order to the orders.txt file and calculates the revenue
** Parameters: none
** Pre-Conditions: is selected
** Post-Conditions: item ordered
*********************************************************************/
void Shop::place_order() {
	//handle "Place order" option
	//Your code goes here:
	Coffee* coffees = this->m.get_coffee_arr();
	revenue = 0;
	ofstream order_info;
	ifstream order_ifstream;
	
	order_ifstream.open("orders.txt");
	this-> num_orders = 0;
	order_ifstream >> this->num_orders;


	Order the_order = get_order();
	populate_order_arr(the_order);
	num_orders++;

	
	order_info.open("orders.txt");
	order_info << num_orders << " "<< endl;
	for(int i = 0; i < num_orders; i++){
		order_info << i+1 << ". ";
		order_info << order_arr[i].get_coffee_name() << " ";
		order_info << order_arr[i].get_coffee_size() << " ";
		order_info << order_arr[i].get_quantity() << " ";
		order_info << endl;
		for(int j = 0; j < this->m.get_num_coffee(); j++){
			if(coffees[j].get_name() == order_arr[i].get_coffee_name()){
				if (order_arr[i].get_coffee_size() == 'S' ){
					revenue = (revenue + coffees[j].get_small_cost()) * order_arr[i].get_quantity();
				}
				else if (order_arr[i].get_coffee_size() == 'M'){
					revenue = (revenue + coffees[j].get_medium_cost()) * order_arr[i].get_quantity();
				}
				else {
					revenue = (revenue + coffees[j].get_large_cost()) * order_arr[i].get_quantity();
				}
			}
		}
	}
	
	order_info.close();
	order_ifstream.close();

	return;
}


/*********************************************************************
** Function:clone_shop
** Description: deep copy of the shop
** Parameters: none
** Pre-Conditions: is selected
** Post-Conditions: a deep copy of the shop is created
*********************************************************************/
Shop Shop::clone_shop() {
	//handle "Clone a shop" option
	//note: the purpose of this option is to test
	//your big three implementation
	Shop cloned_shop;

	cloned_shop = *this; // test AOO        

    Shop cloned_shop2 = *this; // test CC 

    cout << "Shop cloned successfully!" << endl; 

    return cloned_shop;
}