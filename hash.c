//
// Created by nadav on 20/01/2020.
//

#include "hash.h"
/*vnh*/

#include <stdio.h>

#define FILE_NAME NULL

typedef struct Node
{
    char *value;
    struct Node *next;
} Node;

typedef struct linkedList
{
    Node *head;
}linkedList;

int main(int argc, char * argv[]) {
    FILE *fp = fopen(FILE_NAME, "r");
    if(fp == NULL)
    {
        fclose(fp);
        fprintf(stderr, "𝐶𝑎𝑛𝑛𝑜𝑡 𝑜𝑝𝑒𝑛 𝑡ℎ𝑒 𝑓𝑖𝑙𝑒");
    }
    fclose(fp);
    printf("Hello, World!\n");
    return 0;
}