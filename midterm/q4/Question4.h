/* @Author
Student Name: Ahmet Furkan Kavraz
Student ID : 150190024
Date: 08.12.2020
*/

void question4();

struct mnode{
	int data;
    mnode *root;
    mnode *next;
};

struct Multilist{
    mnode *head; 
    mnode *returnadressof(int);
    void create();
    void add(int );
    void printroots(mnode*);
    void print_list();
};