#include "linkedlist.h"

// function to read data from a file and store it in a linked list
node* readFileToList(const char* filename);

// function to write data from a linked list to a file
void writeListToFile(const char* filename, node* head);
