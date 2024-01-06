/*********************************************************************
** Program Filename: game.h
** Author: Quinn Roth
** Date: 11/28/23
** Description: header file for game.cpp
** Input:none
** Output:none
*********************************************************************/
#ifndef GAME_H
#define GAME_H 

#include <vector>
#include <iostream> 
#include "room.h"
#include "event.h"

using namespace std;

struct player{
	int x_cord;
	int y_cord;
	bool alive = true;
	bool has_gold = false;
	bool confused = false;
	int turns;
	bool wump_killed = false;
};

//Game interface 
class Game
{
private:
	
	//declare a 2D vector of Room objects:
	player p;
	//other member variables:
	int length; 			//length of the board
	int width;  			//width of the board
	int num_arrows; 		//keep track of number of errors remaining
	bool debug_view;		//debug mode or not
	vector<vector<Room>> grid;
	int wumpus_x;
	int wumpus_y;
	int start_x;
	int start_y;
	//feel free to add more variables...

public:
	//suggested functions:
	Game();
	~Game();
	
	void set_up(int rows, int columns);
	void insert_event(Event* e);
	void insert_player();
	void print_perceptions(int l, int w);
	void populate_grid();
	void display_game();
	void perform_event();
	bool check_win() const;

	char get_dir();
	void fire_arrow();

	void move_up();
	void move_down();
	void move_left();
	void move_right();
	void move(char);
	void move_wumpus();
	char get_input();
	void look_wumpus();
	void play_game(int, int, bool);

	//feel free (and you will need) to add more functions...




};
#endif