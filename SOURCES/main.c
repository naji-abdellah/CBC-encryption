#include"cbc.h"  /* file names */
#include"fileio.h"
#include"linkedlist.h"

#include<stdio.h>//this library provides functions for standard input/output operations, such as printf and scanf.
#include<stdlib.h>//this library offers functions for dynamic memory management, such as malloc and free.
#include<string.h>//this library contains functions for manipulating strings, such as strcpy and strlen.

int main(){

 //read data from a file into a linked list
 node* data = readFileToList("input.txt");
 printf("original data : \n");
 displayList(data);

 //encrypt a linked list using CBC encryption
 node* iv = createNode('0');
 node* current = data;

 while(current != NULL){
    encryptBlock(&current, iv);
    current = current->next;
 }
 printf("encrypted data : \n");
 displayList(data);
 writeListToFile("file.txt",data);//write the encrypted data to a file

 //prepare for decryption
 current = data;
 node* prev_iv = createNode('0'); // initial IV used for the first block
 node* temp_iv;
 //decrypt the blocks
 while (current != NULL) {
 temp_iv = createNode(current->data); // save the current block (to become the new IV)
 decryptBlock(&current, prev_iv); // decrypt the block with the previous IV
 free(prev_iv); // free the old IV
 prev_iv = temp_iv; // update the IV for the next block
 current = current->next;
 }
 printf("decrypted data : \n");
 displayList(data);
 writeListToFile("output.txt",data); //write the decrypted data to a file

 //free memory
 while(data != NULL){
    node*temp = data;
    data = data->next;
    free(temp);
 }
 free(iv);
 free(prev_iv);
 return 0;
}

//test operations on linked lists
/*int main(){
   node* head = NULL ;
   head = insertNode(head ,  'a');
   head = insertNode(head ,  'b');
   head = insertNode(head ,  'c');
   head = insertNode(head , 'd');
   displayList(head);
   head = deleteNode(head , 'c');
   displayList(head);
   head = insertNode(head , 'd');
   displayList(head);
   return 0 ;
}*/

//test file functions
/*int main(){
   node* head = NULL ;
   node* root = NULL ;
   head = insertNode(head ,  'a');
   head = insertNode(head ,  'b');
   head = insertNode(head ,  'c');
   head = insertNode(head , 'd');
   displayList(head);
   writeListToFile("file.txt" , head);
   root = readFileToList("file.txt");
   root = deleteNode(root , 'c');
   displayList(root);

   return 0 ;
}*/
