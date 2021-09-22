/* @Author
Student Name: Ahmet Furkan Kavraz
Student ID : 150190024
Date: 08.12.2020
*/

#include "Question3.h"
#ifndef HEADERFILE_H
#define HEADERFILE_H
#include <iostream>
#include <string>
#endif
using namespace std;
/*Write the necessary C++ data structures and methods in order to execute question3.
Please  also keep in mind that your code must have no memory leaks.
So please also provide extra methods which are necessary to escape memory leaks
although not invoked within the below function.
*/

void Linkedlist::create(){
    head = NULL;
}

void Linkedlist::add2beginning(int a){
    Node* temp = new Node;
    temp->data = a;
    temp->next = head;
    head = temp;
}

void Linkedlist::print_list(){
	Node *traverse = head;
    while (traverse){
        cout << traverse->data << endl;
        traverse = traverse->next;
    }
}

void Linkedlist::clear(){
    while (head != NULL){
        Node* previous = head;
        head = head->next;
        delete previous;
    }
}

void question3(){
	Linkedlist l;
	l.create();
	for (int i = 0; i < 4; i++)
		l.add2beginning(i);
	l.print_list();
	l.clear();
	l.print_list();
}
