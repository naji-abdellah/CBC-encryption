#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

// function to create a new node in the linked list
node* createNode(char value) {
    node* new_node = (node*)malloc(sizeof(node));
    // in case of memory allocation failure
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    // initialize the data of the new node
    new_node->data = value;
    new_node->next = NULL;
    return new_node;
}

// function to insert a new node at the head of the linked list
node* insertNode(node* head, char value) {
    node* new_node, *last;
    // create a new node
    new_node = createNode(value);
    // update links to insert the new node at the head
    if (head == NULL) {
        head = new_node;
    } else {
        last = head;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = new_node;
    }
    return head;
}

// function to delete a specific node from the linked list
node* deleteNode(node* head, char value) {
    if (head == NULL) {
        printf("The list is empty\n");
        return head;
    }
    // initialize current and previous pointers
    node* current, *previous;

    current = head;
    previous = head;

    if (current->data == value) {
        head = current->next;
        free(current);
        return head;
    }
    // search for the node to delete
    while (current != NULL && current->data != value) {
        previous = current;
        current = current->next;
    }
    // if the node is not found
    if (current == NULL) {
        printf("Value not found in the list\n");
        return head;
    }
    // update links to remove the node from the list
    if (previous == NULL) {
        head = current->next;
    } else {
        previous->next = current->next;
    }
    // free the memory of the deleted node
    free(current);
    return head;
}

// function to display the data of the linked list
void displayList(node* head) {
    if (head == NULL)
        printf("The list is empty\n");
    else {
        node* current;
        current = head;
        while (current != NULL) {
            printf("%c", current->data); // display the data of the node
            current = current->next;
        }
    }
    printf("\n");
}
