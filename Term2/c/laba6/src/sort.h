#include <stdio.h>
#include <stdlib.h>
#include "list.h"

static int compare(const void* a, const void* b){
    Node* nodeA = *(Node**)a;
    Node* nodeB = *(Node**)b;

    return nodeA->data.winYears - nodeB->data.winYears;
}

void sortByWinYears(Node* head){
    int size = getSize(head);

    if (size == 0)return;

    Node** array = (Node**)malloc(size * sizeof(Node*));

    Node* temp = head;

    for (int i = 0; i < size; i++){
        array[i] = temp;
        temp = temp->next;
    }

    qsort(array, size, sizeof(Node*), compare);

    printf("\nSorted List:\n");

    for (int i = 0; i < size; i++){
        printf("\nClub %d\n", i + 1);
        printf("Name: %s\n",
               array[i]->data.name);

        printf("country: %s\n",
               array[i]->data.country);

        printf("winYears: %d\n",
               array[i]->data.winYears);
    }

    free(array);
}
