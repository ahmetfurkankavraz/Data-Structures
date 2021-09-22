/* @Author
Student Name: Ahmet Furkan Kavraz
Student ID : 150190024
Date: 11.11.2020
*/

/*
PLEASE DO NOT REMOVE ANY FUNCTION OR VARIABLE IN THE STRUCT, IF YOU NEED YOU CAN ADD NEW ONES 
*/

#ifndef _H
#define _H
#include <stdio.h>

#define ARRAY_SIZE 100

#include "token.h"

struct Counter{
	int token_count=0; // token_count is the number of different tokens.
	Token token_array[ARRAY_SIZE];
	void read_and_count();
	bool contains(char *,char);
	int findindex(Token [],char[]);
	Token *get_most_common_three();
};
#endif