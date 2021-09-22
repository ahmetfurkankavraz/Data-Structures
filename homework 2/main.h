#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "circuit.h"
#include "resistor.h"
#pragma once

int main(int argc, char **argv){

    FILE *fp = fopen(argv[1] , "r");
    if (!fp){
        std::cout << "There is no file name = " << argv[1] << std::endl;
    }

    circuit Circuit;
    Circuit.create(); // create circuit
    
    char group;
    float resistans_value;

    while (fscanf(fp, "%c %f\n", &group, &resistans_value) != EOF){ //performing operations according to lines inside file.
        
        if (resistans_value == 0){
            Circuit.circuit_info();
        }
        else if (resistans_value < 0){
            Circuit.remove_resistor(group);
        }
        else if (resistans_value > 0){
            Circuit.add_resistor(group, resistans_value);
        }
    }
    
    Circuit.clear(); //free all linked list elements.
    fclose(fp);
    return EXIT_SUCCESS;
}
