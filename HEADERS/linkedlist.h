#ifndef LINKEDLIST_H // check if LINKEDLIST_H is not defined
#define LINKEDLIST_H // define LINKEDLIST_H

// definition of the structure for a node in a linked list
typedef struct node {
    char data;            // data stored in the node
    struct node* next;    // pointer to the next node in the list
} node;

// function signature to create a new node
node* createNode(char value);

// function signature to insert a new node at the head of the list
node* insertNode(node* head, char value);

// function signature to delete a specific node from the list
node* deleteNode(node* head, char value);

// function signature to display the data of the list
void displayList(node* head);

#endif // end of LINKEDLIST_H
