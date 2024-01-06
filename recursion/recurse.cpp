// The following is an example program that
// does some basic, limited testing of your
// ways_to_top() implementation.
/*********************************************************************
** Program Filename: recurse.cpp
** Author: Quinn Roth	
** Date: 12/10/23
** Description: Calls ways_to_top 20 timesnd prints the results 
** Input: none
** Output: results
*********************************************************************/
#include <iostream>
#include "stairs.h"

using namespace std;

int main() {
	for(int i = 0; i < 21; i++){
		cout << i << ": " << ways_to_top(i) << endl;
	}
}
