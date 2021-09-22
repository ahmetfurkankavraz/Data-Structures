/* @Author
Student Name: Ahmet Furkan Kavraz
Student ID : 150190024
Date: 07.12.2020
*/
#pragma once

struct resistor{
    char group;
    double value;
    int quantity;
    resistor *next;
};