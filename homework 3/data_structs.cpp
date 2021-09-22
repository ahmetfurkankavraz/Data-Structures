/* @Author
Student Name: Ahmet Furkan Kavraz
Student ID : 150190024
Date: 11.01.2021 
*/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

using namespace std;

#include "data_structs.h"

//Stack

void Stack::init(){
    head = NULL;
}

void Stack::close(){
    while(head){
        Subtask* temp = head;
        head = head->next;
        delete temp;
    }
    head = NULL;
}

void Stack::push(Subtask* in){
    in->next = head;
    head = in;
}

Subtask* Stack::pop(){
    Subtask* temp = head;
    head = head->next;
    return temp;
}

bool Stack::isEmpty(){
    if (head == NULL){
        return true;
    }
    return false;
}

//Queue

void Queue::init(){
    head = NULL;
    tail = NULL;
}

void Queue::close(){
    while(head){
        Process* temp = head;
        head->task_stack.close();
        head = head->next;
        delete temp;
    }
}

void Queue::queue(Process* in){
    if (tail){
        tail->next = in;
        tail = in;
    }
    else {
        head = in;
        tail = in;
    }
}

Process* Queue::dequeue(){
    Process* temp = head;

    if (head == tail){
        tail = NULL;
        head = NULL;
    }
    else {
        head = head->next;
    }

    if (isEmpty()){
        close();
    }

    return temp;
}

bool Queue::isEmpty(){
    if (head == NULL){
        return true;
    }
    return false;
}

Process* Queue::front(){
    return head;
}


//Multiqueue

void MultiQueue::init(){
    queues[0].init();
    queues[1].init();
    queues[2].init();
}

void MultiQueue::close(){
    queues[0].close();
    queues[1].close();
    queues[2].close();
}

void MultiQueue::queue(Process* in){
    if (in->priority == 1){
        queues[0].queue(in);
    }
    else if (in->priority == 2){
        queues[1].queue(in);
    }
    else if (in->priority == 3){
        queues[2].queue(in);
    }
}

Process* MultiQueue::dequeue(int priority){
    Process* temp;
    if (priority == 1){
        temp = queues[0].dequeue();
    }
    else if (priority == 2){
        temp = queues[1].dequeue();
    }
    else if (priority == 3){
        temp = queues[2].dequeue();
    }
    return temp;
}

bool MultiQueue::isEmpty(){   // bilemeyizz. bilsek de göremeyiz.
    if (queues[0].isEmpty() && queues[1].isEmpty() && queues[2].isEmpty()){
        return true;
    }
    return false;

}

Process* MultiQueue::front(int priority){
    Process* temp;
    if (priority == 1){
        temp = queues[0].front();
    }
    else if (priority == 2){
        temp = queues[1].front();
    }
    else if (priority == 3){
        temp = queues[2].front();
    }
    return temp;
}
