/* @Author
Student Name: Ahmet Furkan Kavraz
Student ID : 150190024
Date: 07.12.2020
*/
#include "resistor.h"
#pragma once

struct circuit{
    resistor *head;
    int resistor_count; 
    void create();
    void add_resistor(char, float);
    void remove_resistor(char);
    void delete_resistor(char);
    void circuit_print();
    void circuit_info();
    void clear();
};


void circuit::create(){ // initializes linked list.
    head = NULL;
    resistor_count =  0;
}

void circuit::add_resistor(char group_type, float num){

    if (head == NULL || (head->group > group_type)){ // adding a resistor head
        resistor* resistor_temp = new resistor;
        resistor_temp->group = group_type;
        resistor_temp->value = num;
        resistor_temp->quantity = 1;
        resistor_temp->next = NULL;
        
        if (head != NULL){ 
            resistor_temp->next = head;
        }
            
        head = resistor_temp;
        resistor_count++;
    }

    else {
        resistor *traverse = head;
        resistor *precedessor = NULL;

        while (traverse->group <= group_type){ // finding appropriate place
            precedessor = traverse;
            traverse = traverse->next;
            if (traverse == NULL)
                break;
        }

        if (precedessor->group == group_type){ // if group is already exist,
            precedessor->quantity += 1;
        }

        else if (precedessor->group < group_type) { // if group is not exist,
            resistor* resistor_temp = new resistor;
            resistor_temp->group = group_type;
            resistor_temp->value = num;
            resistor_temp->quantity = 1;
            resistor_temp->next = traverse; // if we append a resistor to tail, since traverse is equal to NULL, 
                                            //we do not need to write another if statement.
            
            precedessor->next = resistor_temp;

            resistor_count++;
        }
    }
}

void circuit::remove_resistor(char group){

    resistor *traverse = head;
    int i = 0;
    while (i < resistor_count){ // finding appropriate place
        if (traverse->group == group){
            break;
        }
        i++;
        traverse = traverse->next;
    }

    if (i == resistor_count){
        std::cout << "NO_RESISTOR\n";
    }
    else {
        if (traverse->quantity == 1){ // if there is only one resistor in that group, we delete resistor from linked list
            delete_resistor(group);
            resistor_count -= 1;
        }
        else {
            traverse->quantity -= 1; //else, the quantitiy of the group is decreased.
        }
    }
}

void circuit::delete_resistor(char group){
    resistor *traverse = head;
    resistor *precedessor = NULL;

    while (traverse->group != group){
        precedessor = traverse;
        traverse = traverse->next;
    }

    if (traverse == NULL) { // the resistor is not found
        precedessor->next = NULL; //this assignment is just for getting guarantee our code.
    }
    else {
        if (traverse == head){ // deleting from head
            head = head->next;
            delete traverse;
        }
        else { // deleting any other place
            precedessor->next = traverse->next; 
            delete traverse;
        }
    }
}

void circuit::circuit_info(){

    resistor *traverse = head;
    float total_resistans = 0;
    int max_inlist = 0;

    while (traverse){ // total resistans calculator
        total_resistans += traverse->value / traverse->quantity;
        if (traverse->value > max_inlist){
            max_inlist = traverse->value;
        }
        traverse = traverse->next;
    }

    double min_val_old = 0;

    while (true){ // printing all values from min to max.

        traverse = head;
        double min_val = max_inlist;
        int min_val_quantity = 0;

        while (traverse){
            if (traverse->value < min_val && min_val_old < traverse->value){
                min_val = traverse->value;
                min_val_quantity = traverse->quantity;        
            }
            else if (traverse->value == min_val){
                min_val_quantity += traverse->quantity;
            }
            traverse = traverse->next;        
        }

        if (min_val_old == min_val)
            break;

        std::cout << min_val << ":" << min_val_quantity << std::endl;
        min_val_old = min_val;   
    }


    std::cout << "Total resistance=" << total_resistans << " ohm"<< std::endl;
}

void circuit::circuit_print(){ //this is a print statement. our program does not need it. I write it for debugging.
    resistor *traverse = head;
    while (traverse){
        std::cout << traverse->group << " " << traverse->value << " " << traverse->quantity<< "\n";
        traverse = traverse->next;
    }
    return;
}

void circuit::clear(){ // deletes all resistors
    resistor *traverse = head;
    resistor *precedessor = NULL;

    while (traverse != NULL){
        precedessor = traverse;
        traverse = traverse->next;
        head = traverse;
        delete precedessor;
    }
}

