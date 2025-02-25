#ifndef CBC_H // check if CBC_H is not defined
#define CBC_H // define CBC_H

#include "linkedlist.h"

// define the CBC structure context
typedef struct cbc {
    struct node* iv; // initialization vector (IV)
} cbc;

// function to encrypt a block of data using the CBC mode
void encryptBlock(node** block, node* iv);

// function to decrypt a block of data using the CBC mode
void decryptBlock(node** block, node* iv);

#endif // end of CBC_H
