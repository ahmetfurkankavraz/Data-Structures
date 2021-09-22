/* @Author
Student Name: Ahmet Furkan Kavraz
Student ID : 150190024
Date: 08.12.2020
*/

//25 pts
/*Write the multilist struct where the node structure is given. 
Each node should have two pointers (next and root).
Each node's next pointer will point to the
next integer in the list as usual.
The list should be sorted in ascending order.
If a number has an integer root (e.g. 9's root is 3 which is an integer)
its node's root pointer should point to its root's node  otherwise it should be NULL.
write the methods returnadressof and add.
The add method should add n numbers from 1 to n (the function input argument) to the multilist.
e.g. when the argument is 100 it will add 100 numbers with a single function call.
You may assume that the multilist will always be empty when the add method is called.
The root pointer of the node carrying "1" should always be  NULL.
hint you may use the sqrt and floor methods from <math.h>.
*/
#include "Question4.h"
#ifndef HEADERFILE_H
#define HEADERFILE_H
#include <iostream>
#include <string>
#include <math.h>
#endif
using namespace std;


void question4(){
	Multilist l;
	l.create();
	l.add(100);
	l.printroots(l.returnadressof(24));//will print "6561 81 9 3 \n" accordingly
}
void Multilist::printroots(mnode *start){
	while (start != NULL){
		cout << start->data << " ";
		start = start->root;
	}
	cout << endl;
}

void Multilist::create(){
	head = NULL;
}

mnode* Multilist::returnadressof(int num){
	mnode *traverse = head;
    while (traverse && traverse->data != num){
        traverse = traverse->next;
    }
	return traverse;
}

void Multilist::add(int num){
	for (int i = 1; i < num+1; i++){
		mnode* temp = new mnode;
		temp->data = i;
		if (i == 1 || i == 2 || i == 3){
			temp->root = NULL;
			temp->next = NULL;
			head = temp;
		}
		else {
			float squareroot = sqrt(i);
			if ((squareroot- floor(squareroot)) == 0){
				temp->root = returnadressof(sqrt(i));
			}
			else {
				temp->root = NULL;
			}
			temp->next = NULL;
			mnode* traverse = head;
			while (traverse->next){
				traverse = traverse->next;
			}
			traverse->next = temp;
		}
	}
}
void Multilist::print_list(){
	mnode *traverse = head;
    while (traverse){
        cout << traverse->data << " "<< traverse->root << " "<< traverse->next << endl;
        traverse = traverse->next;
    }
}