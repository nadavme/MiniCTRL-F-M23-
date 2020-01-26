
#ifndef MAABADA_MMN23_HASH_H
#define MAABADA_MMN23_HASH_H

#include <stdio.h>
#include <stdlib.h>
#include "errno.h"
#include <string.h>

typedef struct Node
{
    int appearances;
    char *fileName;
    struct Node *next;
} Node, *ptr2Node;

typedef struct linkedList
{
    int size;
    Node *head;
}*ptr2LinkedList;

/*!
 *
 * @param fileName
 * @return
 */
ptr2Node createNewNode(char *fileName);

/*!
 *
 * @param currLinkedList
 * @param fileName
 */
void addNode(ptr2LinkedList currLinkedList, char *fileName);

/*!
 *
 * @param fileName
 * @param currLinkedList
 * @return
 */
ptr2Node  findFile(char *fileName, ptr2LinkedList currLinkedList);

/*!
 *
 * @param argv
 * @param argc
 * @param hashTable
 */
void readTheInput(char *argv[], int argc, ptr2LinkedList hashTable[]);

/*!
 *
 * @param hashTable
 * @return
 */
int initiateHashTable(ptr2LinkedList hashTable[]);

/*!
 *
 * @param hashTable
 */
void printAppearances(ptr2LinkedList hashTable[]);
/*!
 *
 * @param string
 */
void checkMemoryAllocation(void *string);


#endif /*MAABADA_MMN23_HASH_H*/
