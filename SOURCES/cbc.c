#include "cbc.h"
#include <stdio.h>
#include "linkedlist.h"

// function to encrypt a block of data using the CBC mode
void encryptBlock(node **block, node *iv) {
   // check if the block is null
   if (*block == NULL) {
       return;
   }
   // encryption operation: XOR with the initialization vector (IV)
   (*block)->data ^= iv->data;
   // update the initialization vector with the current encrypted data
   iv->data = (*block)->data;
}

// function to decrypt a block of data using the CBC mode
// this function uses the same traversal as encryptBlock thanks to the XOR operation
void decryptBlock(node **block, node *iv) {
   // check if the block is null
   if (*block == NULL) {
       return;
   }
   // decryption operation: XOR with the initialization vector (IV)
   (*block)->data ^= iv->data;
   // update the initialization vector with the current decrypted data
   iv->data = (*block)->data;
}
