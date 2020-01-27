
#include "hash.h"



int initiateHashTable(ptr2LinkedList hashTable[])
{
    int i;
    for (i = 0; i < 29; i++)
    {
        hashTable[i] = malloc(sizeof(struct linkedList));
        checkMemoryAllocation(hashTable[i]);
        hashTable[i]->head = NULL;
        hashTable[i]->size = 0;
    }
    return 0;
}


void readTheInput(char *argv[], int argc, ptr2LinkedList hashTable[])
{
    int i;
    FILE *fp;
    int temp;
    i = 1;
    initiateHashTable(hashTable);
    while(i < argc)
    {
        fp = fopen(argv[i], "r");
        if (fp == NULL)
        {
            fprintf(stderr, "File error.");
            exit(EXIT_FAILURE);
        }
        while((fscanf(fp, "%d", &temp) != EOF))
        {
            if(findFile(argv[i], hashTable[temp]) == NULL)
            {
                addNode(hashTable[temp], argv[i]);
                hashTable[temp]->head->appearances++;
            }
            else findFile(argv[i], hashTable[temp])->appearances++;
        }
        fclose(fp);
        i++;
    }
}


void checkMemoryAllocation(void *string)
{
    if (string == NULL)
    {
        fprintf(stderr, "Memory allocation failed.");
        exit(0);
    }
}


ptr2Node createNewNode(char *fileName)
{
    ptr2Node newNode;
    newNode = malloc(sizeof(Node));
    newNode->fileName = malloc(strlen(fileName) * sizeof(char));
    checkMemoryAllocation(newNode->fileName);
    strcpy(newNode->fileName, fileName);
    newNode->next = 0;
    newNode->appearances = 0;
    return newNode;
}

void freeNodeMemory(ptr2Node node)
{
    if (node == NULL) return;
    if (node->fileName != NULL) free(node->fileName);
    freeNodeMemory(node->next);
    free(node);
}

void addNode(ptr2LinkedList currLinkedList, char *fileName)
{
    ptr2Node newNode;
    newNode = createNewNode(fileName);
    newNode->next = currLinkedList->head;
    currLinkedList-> head = newNode;
    currLinkedList->size++;
}

ptr2Node findFile(char *fileName, ptr2LinkedList currLinkedList)
{
    ptr2Node requestedNode = NULL;
    requestedNode = currLinkedList->head;
    while (requestedNode != NULL)
    {
        if (strcmp(requestedNode->fileName, fileName) == 0) return requestedNode;
        requestedNode = requestedNode->next;
    }
    return NULL;
}


void printAppearances(ptr2LinkedList hashTable[])
{
    int i;
    ptr2Node node;
    for (i = 0; i < 28; i++)
    {
        node = hashTable[i]->head;
        if (node != NULL)
        {
            printf("%d appears in", i);
            while(node != NULL)
            {
                if (node->appearances > 0) printf(" file %s - %d times",
                        node->fileName, node->appearances);
                node = node->next;
            }
            printf("\n");
        }
        freeNodeMemory(node);
        free(hashTable[i]);
    }
}


int main(int argc, char * argv[])
{
    ptr2LinkedList hashTable[29];
    readTheInput(argv, argc, hashTable);
    printAppearances(hashTable);

    return 0;
}
