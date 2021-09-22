/* @Author
Student Name: Ahmet Furkan Kavraz
Student ID : 150190024
Date: 08.12.2020
*/

/*Question#2-A palindrome is a word, number, phrase, or other sequence of characters 
which reads the same backward as forward, such as madam, racecar. Write a function
"char* question2answer(char *instring)" which
takes an argument string and turns it into a palindrome-like string but with a single 
difference from the classical definition. The string will consist of numerical values and 
the first half of the produced string will consist of numbers smaller (-2) than the second
half numbers such as in input=1234 output=2101234 instead of "4321234".  
If you find a negative number during subtraction put 0 instead such as in input=2002 output=0002002
You are not allowed to use c++ strings in your answer. 
Use either character arrays or pointers.
The only function that you may use from string class
is the "strlen" function*/
#ifndef HEADERFILE_H
#define HEADERFILE_H
#include <iostream>
#include <string.h>
#endif
using namespace std;

//15pts
char* question2answer(char *instring){
    int length = strlen(instring);
	char *outstring = new char[length * 3];
	int outstring_index = 0;
	for (int i = length-1; i > 0; i--){
		if (instring[i] - 2 >= '0'){
			outstring[outstring_index++] = instring[i] - 2;
		}
		else {
			outstring[outstring_index++] = '0';
		}
	}
	for (int i = 0; i < length; i++){
		outstring[outstring_index++] = instring[i];
	}
    outstring[outstring_index++] = '\0';
	return outstring;
}
