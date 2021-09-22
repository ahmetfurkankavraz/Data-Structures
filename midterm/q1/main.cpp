#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "Question1.h"

using namespace std;

int main(){
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
}