#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void saveToFile(Node* head, const char* filename){
    FILE* file = fopen(filename, "wb");

    if (file == NULL){
        printf("File wasn't open\n");
        return;
    }

    while (head != NULL){
        fwrite(&head->data, sizeof(FootballClub), 1, file);
        head = head->next;
    }

    fclose(file);

    printf("List saved\n");
}

void loadFromFile(Node** head, const char* filename){
    FILE* file = fopen(filename, "rb");

    if (file == NULL){
        printf("Error opening\n");
        return;
    }

    freeList(head);

    FootballClub club;

    while (fread(&club, sizeof(FootballClub), 1, file) == 1){
        pushBack(head, club);
    }

    fclose(file);

    printf("List loaded\n");
}
