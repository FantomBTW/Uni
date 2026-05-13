#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct FootballClub {
    char name[100];
    char country[100];
    int winYears;
} FootballClub;

typedef struct Node {
    FootballClub data;
    struct Node* next;
} Node;

Node* createNode(FootballClub club){
    Node* node = (Node*)malloc(sizeof(Node));

    if (node == NULL) {
        printf("Ошибка выделения памяти\n");
        exit(1);
    }

    node->data = club;
    node->next = NULL;

    return node;
}

void pushBack(Node** head, FootballClub club){
    Node* newNode = createNode(club);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* temp = *head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void printList(Node* head){
    if (head == NULL) {
        printf("Список пуст\n");
        return;
    }

    int i = 1;

    while (head != NULL) {
        printf("\nКлуб %d\n", i++);
        printf("Название: %s\n", head->data.name);
        printf("Страна: %s\n", head->data.country);
        printf("Годы побед: %d\n", head->data.winYears);

        head = head->next;
    }
}


void deleteByName(Node** head, const char* name){
    if (*head == NULL) {
        return;
    }

    Node* temp = *head;
    Node* prev = NULL;

    while (temp != NULL &&
           strcmp(temp->data.name, name) != 0) {

        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Клуб не найден\n");
        return;
    }

    if (prev == NULL) {
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);

    printf("Клуб удалён\n");
}


void freeList(Node** head){
    Node* temp;

    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int getSize(Node* head){
    int size = 0;

    while (head != NULL) {
        size++;
        head = head->next;
    }

    return size;
}
