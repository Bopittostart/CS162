/******************************************************
** Program: display.h
** Author: Quinn Roth
** Date: 11/14/23
** Description: header for display.cpp 
** Input: none
** Output:none 
******************************************************/
#ifndef DISPLAY_H
#define DISPLAY_H

#include "shop.h"

#define QUIT 8


int get_choice();


void perform_action(Shop &s, int choice);

#endif
