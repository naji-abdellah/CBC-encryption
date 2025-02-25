# CBC Encryption Project (C)  

This project implements **Cipher Block Chaining (CBC) encryption and decryption** using a linked list to process data read from a file. The encryption ensures that each block depends on the previous one, enhancing security by preventing identical plaintext blocks from producing identical ciphertext blocks.  

## Features  
✅ **File-based Encryption & Decryption**: Reads data from a file, encrypts it using CBC mode, and writes the encrypted output back to a file.  
✅ **Linked List Implementation**: Uses a linked list structure to store and process data block by block.  
✅ **Custom IV Handling**: Implements an **Initialization Vector (IV)** to ensure proper chaining between encrypted blocks.  
✅ **Memory Management**: Dynamically allocates and frees memory for efficient data processing.  

## File Structure  
- `main.c` – Implements encryption and decryption logic.  
- `cbc.h` – Defines CBC encryption and decryption functions.  
- `fileio.h` – Handles file operations (reading/writing data).  
- `linkedlist.h` – Manages linked list operations.  

## How It Works  
1. **Read Input**: Loads data from `input.txt` into a linked list.  
2. **Encryption**: Encrypts the linked list using CBC mode.  
3. **Write Encrypted Data**: Saves the encrypted output to `file.txt`.  
4. **Decryption**: Decrypts the encrypted linked list using CBC mode.  
5. **Write Decrypted Data**: Saves the decrypted output to `output.txt`.  

## Compilation & Execution  
Compile the project using `gcc`:  
```bash
gcc main.c -o cbc_project
./cbc_project
```  

## Why CBC?  
Cipher Block Chaining (CBC) mode ensures that each block of plaintext is XORed with the previous ciphertext block before encryption, making the encryption more secure against pattern detection.  
