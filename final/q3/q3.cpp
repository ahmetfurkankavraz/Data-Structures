/* @Author
Student Name:Ahmet Furkan Kavraz
Student ID :150190024
Date:06.02.2021
*/

/*
Solve the following problem by filling the required places in the skeleton code. 

We want to check whether given input has proper matching parenthesis or not?  For example ( ) [ ] and [ ( ) ] has proper matching parenthesis but
 )( or ( [ ) ]  not. Let 0,1, 2, 3, 4 denote different types of left parenthesis such as (, [, ..  and 5, 6, 7, 8, 9 denote corresponding right 
 parenthesis such as ), ], ... Therefore 0-5,1-6, 2-7, 3-8, 4-9 are the parenthesis pairs that need to match. For example 1649 or 1496 has proper 
 matching parenthesis but 61 or 1946 not. We will provide you ten digit sequences such as 2334345666 and ask you to output TRUE if it is a proper 
 matching and FALSE if it is not. For example  1111166666, 2740591638 and 1327272786 should return TRUE; 3654112344 and 0000005555 should return FALSE.

You can use any library that you want. Also, you can ignore to check whether the user input contains numerical or alphabetical values.

*/


#include <iostream>
#include <bits/stdc++.h>

#define INPUT_LENGTH 10
using namespace std;

bool arePair(char a, char b){
	bool result = false;
	if (a == '0' && b == '5' ||
		a == '1' && b == '6' ||
		a == '2' && b == '7' ||
		a == '3' && b == '8' ||
		a == '4' && b == '9' ){
			result = true;
		}
	return result;
}

bool check(char input[INPUT_LENGTH])
{
	bool result = false;
	stack<char> s;
	int i = 0;
	while (i < INPUT_LENGTH){
		cout << input[i] << endl;
		if (input[i] == '0' || input[i] == '1' || input[i] == '2' || input[i] == '3' || input[i] == '4' ){
			s.push(input[i]);
		}
		else {
			if (!s.empty() && arePair(s.top(), input[i])){
				s.pop();
			}
			else {
				break;
			}
		}
		i++;
	}
	if (s.empty() && i == INPUT_LENGTH){
		result = true;
	}

	return result;
}


int main()
{	
	char input[10];
	cout<<"Enter the input:"<<endl;
	cin.getline(input,INPUT_LENGTH+1);
	if(check(input))
		cout<<"TRUE"<<endl;
	else
		cout<<"FALSE"<<endl;
	return 0;
}
