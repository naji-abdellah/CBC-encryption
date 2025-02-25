#include <stdio.h>
#include <stdlib.h>
#include "fileio.h"

// function to read data from a file and store it in a linked list
node* readFileToList(const char* filename) {
    // open the file in read mode
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("The file is empty");
        return NULL;
    }

    // initialize the linked list
    char value;
    node* head = NULL;

    // read each character from the file and insert it into the linked list
    while (fscanf(file, "%c", &value) > 0) {
        head = insertNode(head, value);
    }

    // close the file after reading
    fclose(file);
    return head;
}

// function to write data from a linked list to a file
void writeListToFile(const char* filename, node* head) {
    // open the file in write mode
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return;
    }

    // write each node of the linked list to the file
    for (node* current = head; current != NULL; current = current->next) {
        fprintf(file, "%c", current->data);
    }

    // close the file after writing
    fclose(file);
}
