/******************************************************
** Program: prog.cpp
** Author: Quinn Roth
** Date: 11/14/23
** Description: Holds the main function of the program, 
** Input: None
** Output:welcome, and bye
******************************************************/
#include <iostream>
#include "display.h"

using namespace std;
/*********************************************************************
** Function: Main
** Description: main function 
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: program ran, actions performed
*********************************************************************/
int main()
{
	//your main function lives here
	cout << "Welcome to Coffee++" << endl;
	int choice = -1;
	Shop s;
	//populate your Shop:
	//your code here:
	
	
	s.load_data();

	while (choice != QUIT){
		choice = get_choice();
		perform_action(s, choice);
	}

	
	cout << "Bye!" << endl;

	return 0;
}
