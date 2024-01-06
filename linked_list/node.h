/*********************************************************************
** Program Filename: node.h
** Author: Quinn Roth	
** Date: 12/10/23
** Description: Contains the node class
** Input: none
** Output:none
*********************************************************************/
#ifndef NODE_H
#define NODE_H
#include <iostream>

class Node{
public:
	int val; // the value that this node stores
	Node *next; // a pointer to the next node in the list
	// you can add constructors or other functionality if you find it useful or necessary
	Node(){
		val =0;
		next = nullptr;
	}

	Node(int val){
		this->val = val;
		this->next = nullptr;
	}
};

#endif