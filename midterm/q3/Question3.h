/* @Author
Student Name: Ahmet Furkan Kavraz
Student ID : 150190024
Date: 08.12.2020
*/

#include <iostream>
#pragma once

struct Node{
    int data;
    Node* next;
};

struct Linkedlist{
    Node* head;
    void create();
    void add2beginning(int);
    void print_list();
    void clear();
};

void question3();

