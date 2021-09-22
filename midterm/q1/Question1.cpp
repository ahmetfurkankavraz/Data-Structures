/* @Author
Student Name: Ahmet Furkan Kavraz
Student ID : 150190024
Date: 08.12.2020
*/

/*Question#1-The following function do not produce expected results since it is storing only the final entry to the array.
Please provide a solution using dynamic memory allocation techniques.
You are not allowed to use c++ strings in your answer.
Use either character arrays or pointers. You are not allowed to use any outside functions (such as STL methods)
*/
#ifndef HEADERFILE_H
#define HEADERFILE_H
	#include <iostream>
	#include <string>
#endif

using namespace std;
//15 pts
void question1(){
	char* names[5];
	
	for (int i = 0; i < 5; i++){
		cout << "Please enter " << i+1 << ". student name: ";
		char *name = new char[15];
		cin >> name;
		names[i] = name;
	}
	cout << "Printing the array members:" << endl;
	for (int i = 0; i < 5; i++){
		cout << names[i]<<endl;
	}
	for (int i = 0; i < 5; i++){
		delete [] names[i];
	}
}
