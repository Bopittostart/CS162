/*********************************************************************
** Program Filename: game.cpp
** Author: Quinn Roth
** Date: 11/28/23
** Description: does a lot of stuff, such as populating the grid and displaying the grid
** Input: direction to move and fire arrow
** Output: the grid and other information
*********************************************************************/
#include "game.h"
#include "gold.h"
#include "stalactites.h"
#include "bats.h"
#include "wumpus.h"
#include "rope.h"
#include <string>
#include <iostream>

using namespace std;

//Game Implementation

Game::Game(){
	//Game constructor
	//Your code here:
}

Game::~Game(){
	//Game destructor
	//Your code here:

}
/*********************************************************************
** Function: populate_grid
** Description: puts events into the grid
** Parameters: none
** Pre-Conditions: is called
** Post-Conditions: grid populated
*********************************************************************/
void Game::populate_grid(){
	
	for(int i = 0; i < 2; i++){
		Game::insert_event(new Bats);
	}
	for(int i = 0; i < 2; i++){
		Game::insert_event(new Stalactites);
	}
	
	Game::insert_event(new Gold);
	
	Game::insert_event(new Wumpus);

	Game::insert_player();
}

/*********************************************************************
** Function:set_up
** Description: crates the 2d vector of rooms
** Parameters: length and width
** Pre-Conditions: is called
** Post-Conditions: vector is called and filled with rooms
*********************************************************************/
void Game::set_up(int l, int w){
	//set up the game
	this->length = l;
	this->width = w;

	this->num_arrows = 3; 	//start with 3 arrows
	
	// Finish the remaining...
	//Your code here:
	// Create the game board: 2D vector of Room objects
	// randomly insert events (2 bats, 2 stalactites, 1 wumpus, 1 gold)

	// into the board
	for (int i = 0; i < l; i++){
		vector<Room> l;
		for (int j = 0; j < w; j++){
			Room r;
			l.push_back(r);
		}
		grid.push_back(l);
	}
	//choose a random row and random collumn then place bat there
}
/*********************************************************************
** Function:perform_event
** Description: calls the events encounter
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Game::perform_event(){
	char thing = grid.at(p.y_cord).at(p.x_cord).perform_function();
	if(thing == 'W' || thing == 'S'){
		p.alive = false;
	}
	if(thing == 'B'){
		p.confused = true;
		p.turns = 1;
	}
	if(thing == 'G'){
		p.has_gold = true;
		grid.at(p.y_cord).at(p.x_cord) = nullptr;
	}
}

/*********************************************************************
** Function: insert player
** Description: finds an open room an assigns the player to those cords, and puts the rope there
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: player location is known
*********************************************************************/
void Game::insert_player(){
	int row_idx;
	int col_idx;
	do {
	//choose random row
	row_idx = rand() % grid.size();
	//choose random column
	col_idx = rand() % grid.at(0).size();
	if(grid.at(row_idx).at(col_idx).get_event() == nullptr){
		p.x_cord = col_idx;
		p.y_cord = row_idx;
		start_x = col_idx;
		start_y = row_idx;
		grid.at(row_idx).at(col_idx).set_event(new Rope);
		break;
	}
	} while(grid.at(row_idx).at(col_idx).get_event() != nullptr);
//place event
}
/*********************************************************************
** Function: insert_event
** Description: finds a random open room to put an event in
** Parameters: event object pointer
** Pre-Conditions: event object exists
** Post-Conditions: grid has events in it
*********************************************************************/
void Game::insert_event(Event* e){
	int row_idx;
	int col_idx;
	do {
	//choose random row
	row_idx = rand() % grid.size();
	//choose random column
	col_idx = rand() % grid.at(0).size();
	if(grid.at(row_idx).at(col_idx).get_event() == nullptr){
		grid.at(row_idx).at(col_idx).set_event(e);
		break;
	}
	} while(grid.at(row_idx).at(col_idx).get_event() != nullptr);
//place event
}
/*********************************************************************
** Function: print_perception
** Description: prints the perception string of any event adjecent to the player
** Parameters: length width
** Pre-Conditions: grid length and width
** Post-Conditions: percept is printed
*********************************************************************/
void Game::print_perceptions(int l, int w){
	if (p.y_cord != 0){
		if(grid.at(p.y_cord - 1).at(p.x_cord).get_event()  != nullptr){
			cout << grid.at(p.y_cord - 1).at(p.x_cord).print_percept() << endl;
		}
	}
	if (p.y_cord != l - 1 ){
		if(grid.at(p.y_cord + 1).at(p.x_cord).get_event()  != nullptr){
			cout << grid.at(p.y_cord + 1).at(p.x_cord).print_percept() << endl;
		}
	}

	if (p.x_cord != 0 ){
		if(grid.at(p.y_cord).at(p.x_cord - 1).get_event()  != nullptr){
			cout << grid.at(p.y_cord).at(p.x_cord - 1).print_percept() << endl;
		}
	}
	if (p.x_cord != w - 1 ){
		if(grid.at(p.y_cord).at(p.x_cord + 1).get_event()  != nullptr){
			cout << grid.at(p.y_cord).at(p.x_cord + 1).print_percept() << endl;
		}
	}
}
/*********************************************************************
** Function:look_wumpus
** Description: searches the vector to find the wumpus
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: wunpus cords are found
*********************************************************************/
void Game::look_wumpus(){
	for(int i = 0; i < width; i++){
		for(int j = 0; j <length; j++){
			if(grid.at(j).at(i).get_event() !=NULL){
			if(grid.at(j).at(i).print_event() == 'W'){
				wumpus_x = i;
				wumpus_y = j;
			}
			}
		}
	}
}
/*********************************************************************
** Function:move_wumpus
** Description: finds a random open spot to move wumpus to
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: wumpus is in a new location
*********************************************************************/
void Game::move_wumpus(){
	int randNum = rand() % 4;
	int row_idx;
	int col_idx;
    if (randNum != 0){
		cout << "The wumpus woke up and is now on the move." << endl;
		look_wumpus();
	
		do {

        	row_idx = rand() % length;
		//choose random column
			col_idx = rand() % width;
			
			
		} while(grid.at(row_idx).at(col_idx).get_event() != nullptr);
		grid.at(row_idx).at(col_idx).set_event(grid.at(wumpus_y).at(wumpus_x).get_event());
		grid.at(wumpus_y).at(wumpus_x).set_event(nullptr);
		look_wumpus();

	}
}

/*********************************************************************
** Function:display_function
** Description: prints the screen
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: grid printed
*********************************************************************/
void Game::display_game(){
	cout << endl << endl;
	cout << "Arrows remaining: " << this->num_arrows << endl;
	cout << "x: " << p.x_cord << endl;
	cout << "y: " << p.y_cord << endl;
	
	string line = "";
	for (int i = 0; i < this->width; ++i)
		line += "-----";

	for (int i = 0; i < this->length; ++i)
	{
		cout << "| ";
		cout << line << endl;
		cout << "| ";

		for (int j = 0; j < this->width; ++j)
		{
			//The first char indicates whether there is a player in that room or not
			//if the room does not have the player, print space " "
			if (p.y_cord == i && p.x_cord == j){
				cout << " *";
			}
			else {
				cout << " ";
			}
			//The next two chars indicate the event in the room
			//if the room does not have an event, print "  ||" (2 spaces + ||)
			if (grid.at(i).at(j).get_event() == nullptr){
				cout << "  ||";
			}
			else {
				if(this->debug_view == true ){
					cout <<" " << grid.at(i).at(j).print_event() << " ||";
					
				}
				else {
					cout << " ||";	
				}
			}		
		}
		cout << endl;
	}
	cout << line << endl;
}
/*********************************************************************
** Function:check win
** Description: checks if the player has won or not
** Parameters: none
** Pre-Conditions:none
** Post-Conditions: game is stopped or not
*********************************************************************/
bool Game::check_win() const{
	//check if game over/win
	//Your code here:
	if(p.wump_killed == true){
		return true;
	}
	if(p.has_gold == true){
		if(p.x_cord == start_x && p.y_cord == start_y){
			cout << "You escaped!!!" <<endl;
			return true;
		}
	}

	return false;
}
/*********************************************************************
** Function:move up
** Description: moves the player up
** Parameters: none
** Pre-Conditions: up is selected
** Post-Conditions: player is moved up
*********************************************************************/
void Game::move_up() {
	//move player up
	//Your code here:
	p.y_cord--;
	if(p.y_cord < 0){
		p.y_cord++;
		cout << "You hit a wall try again" << endl;
	}
	return;

}
/*********************************************************************
** Function: move down
** Description: player is moved down
** Parameters: none
** Pre-Conditions: down is selected
** Post-Conditions:player is moved down
*********************************************************************/
void Game::move_down() {
	//move player down
	//Your code here:
	
	p.y_cord++;
	
	if(p.y_cord > this->length-1){
		p.y_cord--;
		cout << "You hit a wall try again" << endl;
	}
	return;
}
/*********************************************************************
** Function: move left
** Description: player is moved left
** Parameters: none
** Pre-Conditions: left is selected
** Post-Conditions: player is moved left
*********************************************************************/
void Game::move_left() {
	//move player left
	//Your code here:
	p.x_cord--;
	if(p.x_cord < 0){
		p.x_cord++;
		cout << "You hit a wall try again" << endl;
	}
	return;
}
/*********************************************************************
** Function: move right
** Description: move the player right
** Parameters: none
** Pre-Conditions: right is selected
** Post-Conditions: player is moved right
*********************************************************************/
void Game::move_right() {
	//move player right
	//Your code here:
	p.x_cord++;
	if(p.x_cord > this->width-1){
		p.x_cord--;
		cout << "You hit a wall try again" << endl;
	}
	return;
}
/*********************************************************************
** Function: get_dir
** Description: gets the direction to shoot the arrow
** Parameters: none
** Pre-Conditions: arrow is selected
** Post-Conditions: dirrection is chosen
*********************************************************************/
char Game::get_dir(){
	//get direction of arrow:
	char dir = 'L';
	//Note: error checking is needed!! 
	//Your code here:
	while(dir != 'W' && dir != 'A' && dir != 'S' && dir != 'D'){
	cout << "Fire an arrow...." << endl;cout << "W-up" << endl;cout << "A-left" << endl;cout << "S-down" << endl;cout << "D-right" << endl;
	

	cout << "Enter direction: " << endl;
	cin >> dir;
	cin.ignore(256, '\n');

	if (dir != 'W' && dir != 'A' && dir != 'S' && dir != 'D'){
		cout << "Invalid input try again" << endl;
	}
	}

	return dir;
}

/*********************************************************************
** Function: fire arrow
** Description: fires the arrow in the specified direction
** Parameters: none
** Pre-Conditions: arrow is selected
** Post-Conditions: arrow is fired
*********************************************************************/

//this function is long because of if statements
void Game::fire_arrow(){
	// The player may fire arrow...
	if(num_arrows > 0){
	num_arrows = num_arrows-1;
	int x = p.x_cord;
	int y = p.y_cord;
	char dir = get_dir();
	//Your code here:
		for(int i = 0; i <3; i++){
			if(dir == 'W'){
				if(y-1 > 0){
				y--;					
				}
			}
			if(dir == 'A'){
				if(x-1 > 0){
				x--;
				}
			}
			if(dir == 'S'){
				if(y+1 < length-1){
				y++;
				}
			}
			if(dir == 'D'){
				if(x+1 < width -1){
				x++;
				}
			}
			if(grid.at(y).at(x).get_event() != nullptr){
				p.wump_killed = grid.at(y).at(x).arrow();
				if(p.wump_killed == true){
					grid.at(y).at(x) = nullptr;
				}
			}
			
		}
		if(p.wump_killed == false){
			cout << "You missed." << endl;
			move_wumpus();
		}
		else {

			cout << "You have killed the wumpus!! You win!" << endl;;
		}
	
	return;
	}
	cout << "you are out of arrows" << endl;
	return;

}
/*********************************************************************
** Function: move
** Description: calls move functions depending on what direction is selected
** Parameters: char c
** Pre-Conditions: direction is chosen
** Post-Conditions: character is moved
*********************************************************************/
void Game::move(char c) {
	// Handle player's action: move or fire an arrow
	if (c == 'f'){
		Game::fire_arrow();
		return;
	}
	if(p.confused == false){
	switch(c){
		case 'w':
			Game::move_up();
			break;
		case 'a':
			Game::move_left();
			break;
		case 's':
			Game::move_down();
			break;
		case 'd':
			Game::move_right();
			break;
	}
	}
	else{
		switch(c){
		case 's':
			Game::move_up();
			break;
		case 'd':
			Game::move_left();
			break;
		case 'w':
			Game::move_down();
			break;
		case 'a':
			Game::move_right();
			break;
	}
	}
}
/*********************************************************************
** Function: get inout
** Description: gets the input for what direction to go or fire arrow
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: char c is returned
*********************************************************************/
char Game::get_input(){
	//get action, move direction or firing an arrow

	//Note: error checking is needed!!
	//Your code here:
	char c;

	cout << endl << endl << "Player move..." << endl << endl;
	cout << "w-up" << endl;
	cout << "a-left" << endl;
	cout << "s-down" << endl;
	cout << "d-right" << endl;
	cout << "f-fire an arrow" << endl;

	cout << "Enter input: " << endl;
	cin >> c;
	cin.ignore(256, '\n');

	
	return c;
}

/*********************************************************************
** Function:play_gane
** Description: calls crucial functions for the game, is the main functin of the game.cpp
** Parameters:length width debug bool
** Pre-Conditions: game running
** Post-Conditions: game ended
*********************************************************************/
void Game::play_game(int l, int w, bool d){


	struct player;

	set_up(l, w);
	
	this->debug_view = d;

	char input, arrow_input;
	populate_grid();

	while (check_win() == false && p.alive == true){
		
		//print game board
		display_game();

		//display percerts around player's location
		//Your code here:

		//Player move...
		//1. get input
		input = get_input();

		//2. move player
		move(input);
		if(p.confused == true){
			if(p.turns > 4){
				p.confused = false;
			}
			else{
			p.turns = p.turns + 1;
			}
		}
		//3. may or may not encounter events
		//Your code here:
		print_perceptions(l, w);

		if(grid.at(p.y_cord).at(p.x_cord).get_event()  != nullptr){
			perform_event();
		}
		
		
		
	}
	
	
	return;

}