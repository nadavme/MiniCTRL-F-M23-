

#include "hash.h"



int initiateHashTable(ptr2LinkedList hashTable[])
{
    int i;
    for (i = 0; i < 29; i++)
    {
        hashTable[i] = 0;
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
    fp = NULL;
    while(i < argc +1)
    {
        if(fopen(argv[i], "r"))
        {
            fp = fopen(argv[i], "r");
            while((fscanf(fp, "%d", &temp) != EOF))
                {
                    if(temp != ' ')
                        {
                          if(findFile(argv[i], hashTable[temp - 1]) == NULL)
                            {
                                addNode(hashTable[temp - 1], argv[i]);
                                hashTable[temp - 1]->head->appearances++;
                            }
                          else findFile(argv[i], hashTable[temp - 1])->appearances++;
                        }
                }
            fclose(fp);
            i++;
        }else
        {
            fclose(fp);
            fprintf(stderr, "𝐶𝑎𝑛𝑛𝑜𝑡 𝑜𝑝𝑒𝑛 𝑡ℎ𝑒 𝑓𝑖𝑙𝑒");
        }
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
}

ptr2Node findFile(char *fileName, ptr2LinkedList currLinkedList)
{
    ptr2Node requestedNode;
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
                if(node->next == NULL) break;
                node = node->next;
            }
        }
        printf("\n");
        freeNodeMemory(node);
    }
}


int main(int argc, char * argv[])
{
    ptr2LinkedList hashTable[29];
    readTheInput(argv, argc, hashTable);
    printAppearances(hashTable);


    return 0;
}
