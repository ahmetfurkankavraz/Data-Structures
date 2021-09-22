/* @Author
Student Name: Ahmet Furkan Kavraz
Student ID : 150190024
Date: 11.01.2021 
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

#include "data_structs.h"

using namespace std;

int main(int argc, char* argv[]){
    
    char *file_name = argv[1];
    ifstream fp(file_name);

    /// all_in_queue contains all processes.
    Queue all_in_queue;
    all_in_queue.init();

    do {    //reading inputs from file to all_in_queue
        Process* process = new Process;


        fp >> process->name;
        fp.get();
        fp >> process->priority;
        fp.get();
        fp >> process->arrival_time;
        fp.get();
        fp >> process->task_count;
        fp.get();

        (process->task_stack).init();
        process->next = NULL;

        int sum_of_durations= 0;

        for (int i = 0; i < process->task_count; i++){
            Subtask *subtask = new Subtask; 
            fp >> subtask->name;
            fp.get();
            fp >> subtask->duration;
            fp.get();
            sum_of_durations += subtask->duration;
            (process->task_stack).push(subtask);
        }

        process->deadline = process->arrival_time + sum_of_durations;

        all_in_queue.queue(process);
        
        fp.get();

    } while(!fp.eof());




    MultiQueue multiqueue; //initializing multique
    multiqueue.init();

    int time = 0;
    int lateness = 0;
    int special_condition = 1;

    while ((!all_in_queue.isEmpty() || !multiqueue.isEmpty() )) { //program ending condition 

        while ( !all_in_queue.isEmpty() && (time >= all_in_queue.front()->arrival_time)){ 
            Process* in = all_in_queue.dequeue(); //appending processes which's arrival time is smaller than time. 
            multiqueue.queue(in);
        }

        if (!(multiqueue.queues[0].isEmpty())){ // priority 1
            Subtask* subtask = (multiqueue.front(1)->task_stack).pop();
            time += subtask->duration;
            std::cout << multiqueue.front(1)->name << " " << subtask->name<< endl;
            delete subtask;
            if ((multiqueue.front(1))->task_stack.isEmpty()){
                if (time > multiqueue.front(1)->deadline){
                    lateness += time - multiqueue.front(1)->deadline;
                }
                delete multiqueue.dequeue(1);
            }
        }
        else {

            if (special_condition > 0 && !(multiqueue.queues[1].isEmpty())){ // priority 2
                Subtask* subtask = (multiqueue.front(2)->task_stack).pop();
                time += subtask->duration;
                std::cout << multiqueue.front(2)->name << " " << subtask->name<< endl;
                delete subtask;
                if ((multiqueue.front(2))->task_stack.isEmpty()){
                    if (time > multiqueue.front(2)->deadline){
                        lateness += time - multiqueue.front(2)->deadline;
                    }
                    delete multiqueue.dequeue(2);
                }
            }

            else if (special_condition == 0 && !(multiqueue.queues[2].isEmpty())){ // priority 3
                Subtask* subtask = (multiqueue.front(3)->task_stack).pop();
                time += subtask->duration;
                std::cout << multiqueue.front(3)->name << " " << subtask->name<< endl;
                delete subtask;
                if ((multiqueue.front(3))->task_stack.isEmpty()){
                    if (time > multiqueue.front(3)->deadline){
                        lateness += time - multiqueue.front(3)->deadline;
                    }
                    delete multiqueue.dequeue(3);
                }
            }

            else if (all_in_queue.front() && time <= all_in_queue.front()->arrival_time && multiqueue.isEmpty()){ // time is not enough for processes so we need to increment time for avoiding infinite loop
                time++;
                special_condition -= 1;
            }

            special_condition += 1;
            special_condition = special_condition % 3;
        }
    }
    
    multiqueue.close(); //freeing memories
    all_in_queue.close(); //freeing memories
    std::cout << "Cumulative Lateness: " << lateness;

    fp.close();
    return EXIT_SUCCESS;
}
