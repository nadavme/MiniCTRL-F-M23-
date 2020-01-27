
#ifndef MAABADA_MMN23_HASH_H
#define MAABADA_MMN23_HASH_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/*!
 *
 */
typedef struct Node
{
    int appearances;
    char *fileName;
    struct Node *next;
} Node, *ptr2Node;

/*!
 *
 */
typedef struct linkedList
{
    int size;
    Node *head;
}*ptr2LinkedList;

/*!
 * The function  creates new node initiate it,  and allocates memory for it.
 * @param fileName
 * @return a new node.
 */
ptr2Node createNewNode(char *fileName);

/*!
 * The function  adds a node in the beginning of a linked list.
 * @param currLinkedList is the linked list we work on.
 * @param fileName
 */
void addNode(ptr2LinkedList currLinkedList, char *fileName);

/*!
 * The function  find the node at the values linked list parallel to the files.
 * @param fileName
 * @param currLinkedList is the linked list we work on.
 * @return a pointer to the requested node.
 */
ptr2Node  findFile(char *fileName, ptr2LinkedList currLinkedList);

/*!
 * The function reads the input from files and creates the linked lists.
 * @param argv is the arguments in the input.
 * @param argc is the number og arguments in input.
 * @param hashTable of appearances.
 */
void readTheInput(char *argv[], int argc, ptr2LinkedList hashTable[]);

/*!
 * The function initiates the appearances hash table.
 * @param hashTable
 * @return 0 when finished.
 */
int initiateHashTable(ptr2LinkedList hashTable[]);

/*!
 * The function prints the results of counting the appearances of the numbers in the files.
 * @param hashTable
 */
void printAppearances(ptr2LinkedList hashTable[]);
/*!
 *
 * @param string
 */
void checkMemoryAllocation(void *string);


#endif /*MAABADA_MMN23_HASH_H*/
