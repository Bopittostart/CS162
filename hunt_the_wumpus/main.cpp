/*********************************************************************
** Program Filename: main.cpp
** Author:Quinn Roth
** Date: 11/28/23
** Description: main.cpp file has main fucntion
** Input: width and length
** Output: none 
*********************************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "game.h"

using namespace std;

/*********************************************************************
** Function: main
** Description: main function 
** Parameters:none
** Pre-Conditions: none
** Post-Conditions: game object created
*********************************************************************/
int main()
{
	//set the random seed
	
	srand(time(NULL));
	
	int wid = 5, len = 5;
	bool debug = false;
	int input;
	Game g;

	//get two inputs: size of the cave(wid and len)
	do {
		cout << "Enter a cave width above 3: " << endl;
		cin >> wid;
		if (wid < 4){
			cout << "Invalid try again" << endl;
		}
	} while (wid < 4);
	
	do {
		cout << "Enter a cave length above 3: " << endl;
		cin >> len;
		if (len < 4){
			cout << "Invalid try again" << endl;
	}
	} while (len < 4);

	do {
		cout << "1: Debug" << endl << "2: No Debug" << endl;
		cin >> input;
		if (input == 1){
			debug = true;
		}
		if (input == 2){
			debug == false;
		}
		if (input != 1 && input != 2){
			cout << "Invalid input try again" << endl;
		}
	} while (input != 1 && input != 2);


	//get the 3rd input --> debug mode or not


	//Play game
	g.play_game(len, wid, debug);


	return 0;
}