/******************************************************
** Program: menu.cpp
** Author: Quinn Roth
** Date: 11/14/23
** Description: Has the menu functions, and big three for menu 
** Input: many user inputs
** Output: many outputs determined by the inputs
******************************************************/
#include "menu.h"

using namespace std;

//default constructor
Menu::Menu(){
this->num_coffee = 0;
this->coffee_arr = NULL;
}

Coffee* Menu::get_coffee_arr(){
    return this-> coffee_arr;
}

int Menu::get_num_coffee(){
	return this-> num_coffee;
}

void Menu::set_coffee_arr(Coffee* coffee_arr){
    this -> coffee_arr = coffee_arr;
}

void Menu::set_num_coffee(int num_coffee){
	this -> num_coffee = num_coffee;
}
//non-default 
Menu::Menu (int size) {
    this->num_coffee = size;
    this->coffee_arr = new Coffee [size];
  }
//deconstructor
Menu::~Menu(){
	if(this->coffee_arr != NULL){
		delete[] this->coffee_arr;
		this->coffee_arr = NULL;
	}
}
//copy constructor
Menu& Menu::operator=(const Menu& m){
	if(this == &m){
		return *this;
	}
	if (this ->coffee_arr != NULL){
		delete[] this ->coffee_arr;
	}

	this->num_coffee = m.num_coffee;
	this->coffee_arr = new Coffee [this->num_coffee];
	for(int i = 0; i < this->num_coffee; i++){
		this->coffee_arr[i] = m.coffee_arr[i];
	}
	return *this;
}
//accessor operator overload
Menu::Menu(const Menu& m){
	this->num_coffee = m.num_coffee;
	this->coffee_arr = new Coffee [this->num_coffee];
	for(int i = 0; i < this->num_coffee; i++){
		this->coffee_arr[i] = m.coffee_arr[i];
	}
}
/*********************************************************************
** Function:populate_coffee_arr
** Description: populates coffee array
** Parameters: string filename
** Pre-Conditions: filename, called
** Post-Conditions: coffee array is populated
*********************************************************************/
void Menu::populate_coffee_arr(string filename){
	ifstream menu_info;
	menu_info.open(filename.c_str());
	menu_info >> this->num_coffee;
	string name;
	float cost;
	if (this ->coffee_arr != NULL){
		delete[] this ->coffee_arr;
	}
	this->coffee_arr = new Coffee[this->num_coffee];
	for(int i = 0; i < this->num_coffee; i++){
		this->coffee_arr[i].populate_coffee(menu_info);
	}
	menu_info.close();
}
/*********************************************************************
** Function: display_menu
** Description: calls display_coffee in a for loop
** Parameters:none
** Pre-Conditions: is called
** Post-Conditions: display_coffee is called
*********************************************************************/
void Menu::display_menu() {
	for (int i = 0; i < this->num_coffee; ++i)
	{
		//print out a single coffee obj
		this->coffee_arr[i].display_coffee();

	}
}
/*********************************************************************
** Function: search_coffee_by_name
** Description: searches through the coffee array to find the coffee that matches the provided name
** Parameters: string name
** Pre-Conditions: is called, string name exists
** Post-Conditions: outputs the details of the coffee
*********************************************************************/
Coffee Menu::search_coffee_by_name(string name) {
	Coffee found; 
	for( int i = 0; i < this->num_coffee; i++){
		if (coffee_arr[i].get_name() == name){
			found.set_name(coffee_arr[i].get_name());
			found.set_small_cost(coffee_arr[i].get_small_cost());
			found.set_medium_cost(coffee_arr[i].get_medium_cost());
			found.set_large_cost(coffee_arr[i].get_large_cost());
		}
		
		
	}
	return found;
}
/*********************************************************************
** Function:get_budget
** Description: gets the budget for the search by price
** Parameters: none
** Pre-Conditions: is called
** Post-Conditions: budget
*********************************************************************/
float Menu::get_budget(){
	float budget = 0;
	cout << "What is your budget?" << endl;
	cin >> budget;
	return budget;
}
/*********************************************************************
** Function: search_coffee_by_price
** Description: goes through the coffee array, prints the coffee and price and size if the price is below or equal to the budget
** Parameters: float budget
** Pre-Conditions: is called, float budget exist
** Post-Conditions: prints all coffees with sizes that fit budget
*********************************************************************/
void Menu::search_coffee_by_price(float budget){
	
	
	for(int i = 0; i < this->num_coffee; i++){
			
		if (coffee_arr[i].get_small_cost() <= budget || coffee_arr[i].get_medium_cost() <= budget || coffee_arr[i].get_large_cost() <= budget){
			cout << coffee_arr[i].get_name() << ":" << endl;
		}

		if (coffee_arr[i].get_small_cost() <= budget){
			cout <<"Small - "<< coffee_arr[i].get_small_cost() << endl;
		}
		if (coffee_arr[i].get_medium_cost() <= budget){
			cout <<"Medium - " << coffee_arr[i].get_medium_cost() << endl;
		}
		if (coffee_arr[i].get_large_cost() <= budget){
			cout <<"Large - "<< coffee_arr[i].get_large_cost() << endl;

		}
	
		cout << endl;
	}
	return;

}
/*********************************************************************
** Function: get_coffee_to_add
** Description: asks the user for waht coffee they would like to add to the menu
** Parameters: none
** Pre-Conditions: is called
** Post-Conditions: coffee_to_add is returned
*********************************************************************/
Coffee Menu::get_coffee_to_add(){
	Coffee coffee_to_add;
	string name;
	float small_cost;
	float medium_cost;
	float large_cost;

	
	cout << "What is the name of the coffee you want to add?" << endl;
	cin >> name;
	coffee_to_add.set_name(name);
	cout << "Enter the small price: " << endl;
	cin >> small_cost;
	coffee_to_add.set_small_cost(small_cost);
	cout << "Enter the medium price: " << endl;
	cin >> medium_cost;
	coffee_to_add.set_medium_cost(medium_cost);
	cout << "Enter the large price: " << endl;
	cin >> large_cost;
	coffee_to_add.set_large_cost(large_cost);

	return coffee_to_add;
}
/*********************************************************************
** Function: add_to_menu
** Description: adds the new item to the coffee array and to the txt file
** Parameters: Coffee& coffee_to_add
** Pre-Conditions: Coffee& coffee_to_add exists, is called
** Post-Conditions: item is added to the txt file and array
*********************************************************************/
void Menu::add_to_menu(Coffee& coffee_to_add){
	//add a coffee object into the Menu
	//Your code goes here: 
	Coffee* temp_arr = new Coffee [(this->num_coffee) +1];
	for (int i = 0; i < this->num_coffee; ++i) {
    temp_arr[i] = this->coffee_arr[i];
	}
	temp_arr[this->num_coffee] = coffee_to_add;
	coffee_arr = temp_arr;
	delete[] temp_arr;
	temp_arr = NULL;
	ofstream my_ofstream;
	my_ofstream.open("menu.txt");
	my_ofstream << num_coffee+1 << endl;
	for(int i = 0; i < (this->num_coffee)+1; i++){
	my_ofstream << coffee_arr[i].get_name() << " ";
	my_ofstream << coffee_arr[i].get_small_cost() << " ";
	my_ofstream << coffee_arr[i].get_medium_cost() << " ";
	my_ofstream << coffee_arr[i].get_large_cost() << endl;
	}
	this->num_coffee +=1;
	my_ofstream.close();

	return;
} 
/*********************************************************************
** Function:get_coffee_to_remove
** Description:asks for the coffee to remove, finds the index of that coffee
** Parameters:none
** Pre-Conditions: is called
** Post-Conditions: index is retuned
*********************************************************************/
int Menu::get_coffee_to_remove(){
	int index_of_coffee_on_menu = -1;
	string name;
	cout <<"What is the name of the coffee you want to remove?" << endl;
	cin >> name;
	for(int i = 0; i < (this->num_coffee); i++){
		if (coffee_arr[i].get_name() == name){
			index_of_coffee_on_menu = i;
		}
		
	}
	return index_of_coffee_on_menu;
}

/*********************************************************************
** Function: remove_from_menu
** Description: removes the coffee from the array and txt file
** Parameters: int index_of_cofee_on_menu
** Pre-Conditions: index exists/ is given
** Post-Conditions: item is removed
*********************************************************************/
void Menu::remove_from_menu(int index_of_coffee_on_menu){
	//remove a coffee object from the Menu
	//Your code goes here: 
	ofstream my_ofstream;
	my_ofstream.open("menu.txt");

	for (int i = index_of_coffee_on_menu; i < (this->num_coffee) - 1; ++i) {
        coffee_arr[i] = coffee_arr[i + 1];
    }
	my_ofstream << num_coffee-1 << endl;
	for(int i = 0; i < (this->num_coffee)-1; i++){
		my_ofstream << coffee_arr[i].get_name() << " ";
		my_ofstream << coffee_arr[i].get_small_cost() << " ";
		my_ofstream << coffee_arr[i].get_medium_cost() << " ";
		my_ofstream << coffee_arr[i].get_large_cost() << endl;
	}
    this-> num_coffee -=1;
	my_ofstream.close();
    // Decrease the size of the array
	return;
} 
