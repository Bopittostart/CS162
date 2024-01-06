/*********************************************************************
** Program Filename: stairs.h
** Author: Quinn Roth	
** Date: 12/10/23
** Description: Calculates how mant ways you can get to the top of stairs
** Input: none
** Output:none
*********************************************************************/
#include "stairs.h"
/**
 *	Function: ways_to_top(int)
 *	Description: Computes the number of ways to get to the
 * 		top of a staircase with N steps using small (size 1),
 * 		medium (size 2), and large (size 3) steps
 *	Parameters:
 * 		int n: The number of steps in the staircase
 * 	Returns: The number of ways to get to the top. See the
 *		examples in the assignment description for more info.
 */
int ways_to_top(int n) {
	  if (n < 0) {
        return 0;
    }
	else if (n == 0) {
        return 1;
    }
	else {
        return ways_to_top(n - 1) + ways_to_top(n - 2) + ways_to_top(n - 3);
    }
}

