/* @Author
Student Name: Ahmet Furkan Kavraz
Student ID : 150190024
Date: 11.11.2020
*/

/*
YOU HAVE TO WRITE THE REQUIRED  FUNCTIONS. YOU CAN ADD NEW FUNCTIONS IF YOU NEED.
*/
#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "counter.h"

using namespace std;

	
int Counter::findindex(Token *arr,char elem[]){

	// return index if exist in list, if not return -1

	for (int index = 0; index < token_count; index++){
		if (!strncmp(arr[index].token, elem, TOKEN_LENGTH)){
			return index;
		}
	}
	return -1;
} 

bool Counter::contains(char *token, char target){

	// checking that token contains target or not
	// if contains, counter is greater than 0

	bool boolean = false;
	int counter = 0;

	for (int i = 0; i < TOKEN_LENGTH; i++){
		if (token[i] == target)
			counter++;
	}
	if (counter > 0)
		boolean = true;

	return boolean;
}

void Counter::read_and_count(){

	const char *filename = "pi_approximate";
	FILE *file = fopen(filename, "r+"); // opening file

	char pi_last;
	char pi_current;

	int index_counter = 0;
	bool decimal_part = false;

	while(fscanf(file, "%c", &pi_current) != EOF && pi_current != '\n'){ 
		// while loop ends with end of the file or newline character
		
		if (index_counter == 0) { // no any operation in first
			index_counter++;
			continue;
		}
		
		char target[TOKEN_LENGTH]; // target is our control variable.
		target[0] = pi_last; 
		target[1] = pi_current;
		target[2] = '\0';

		int index = findindex(token_array, target);

		if (decimal_part == false){ // check decimal part
			decimal_part = contains(target, '.');			
		}


		if (!(contains(target, '.')) && (decimal_part == true)){
			if (index == -1){ // if target does not exist in list, append
				strncpy(token_array[token_count].token, target, TOKEN_LENGTH);
				token_array[token_count].count = 1;
				token_count += 1;
			}
			else { // if target exist in list, increase counter
				token_array[index].count += 1;
			}
		}
		pi_last = pi_current;
		index_counter++;
	}

	fclose(file);
}


Token *Counter::get_most_common_three(){

	static Token most_three_token[3];
	
	for (int i = 0; i < token_count; i++){  // getting first most common
		if (token_array[i].count > most_three_token[0].count){ //check the count value. if it is bigger, assign
			strncpy(most_three_token[0].token, token_array[i].token, TOKEN_LENGTH);
			most_three_token[0].count = token_array[i].count;
		}
	}

	for (int i = 0; i < token_count; i++){  // getting second most common
		if  (
			token_array[i].count > most_three_token[1].count && //check the count value. if it is bigger:
				( 	
					// control count is not equal to first common's count. if count is equal, check the tokens are not equal
					token_array[i].count < most_three_token[0].count ||
					(token_array[i].count == most_three_token[0].count && strncmp(token_array[i].token, most_three_token[0].token, TOKEN_LENGTH) )
				)
			)
		{
			strncpy(most_three_token[1].token, token_array[i].token, TOKEN_LENGTH);
			most_three_token[1].count = token_array[i].count;
		}
	}

	for (int i = 0; i < token_count; i++){  // getting third most common
		if  (
			token_array[i].count > most_three_token[2].count && //check the count value. if it is bigger:
				(
					// control count is not equal to second common's count. if count is equal, check the tokens are not equal
					token_array[i].count < most_three_token[1].count || 
					(token_array[i].count == most_three_token[1].count && strncmp(token_array[i].token, most_three_token[1].token, TOKEN_LENGTH) )
				)
			)
		
		{
			strncpy(most_three_token[2].token, token_array[i].token, TOKEN_LENGTH);
			most_three_token[2].count = token_array[i].count;
		}
	}

	return most_three_token;
}
