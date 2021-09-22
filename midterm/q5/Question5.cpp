/* @Author
Student Name: Ahmet Furkan Kavraz
Student ID : 150190024
Date: 08.12.2020
*/

#include "Question3.h"
#include "Question5.h"
/*Write a function  (void change2linkedlist(....,....)) which takes two linked list as arguments and changes all their members
(in other words at the end of the operations list1 will be same as list2 and list2 will be same
as list1's earlier status) by making as few operations as possible.
*/

void change2linkedlist(Linkedlist& l1, Linkedlist& l2){
	Node *temp = l1.head;
	l1.head = l2.head;
	l2.head = temp;
}

void question5(){
	Linkedlist l1, l2;
	l1.create(); l2.create();
	for (int i = 0; i < 10; i++){
		l1.add2beginning(i);
		l2.add2beginning(i * 3);
	}
	change2linkedlist(l1, l2);
}
