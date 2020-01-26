//
// Created by nadav on 20/01/2020.
//

#ifndef MAABADA_MMN23_HASH_H
#define MAABADA_MMN23_HASH_H


typedef struct Node
{
    int appearences;
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
 * @return
 */
ptr2LinkedList createLinkedList();


#endif //MAABADA_MMN23_HASH_H
