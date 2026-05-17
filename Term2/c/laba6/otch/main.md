<div align="center">

МИНИСТЕРСТВО ТРАНСПОРТА РОССИЙСКОЙ ФЕДЕРАЦИИ  
ФЕДЕРАЛЬНОЕ АГЕНТСТВО ЖЕЛЕЗНОДОРОЖНОГО ТРАНСПОРТА  
Государственное бюджетное образовательное учреждение  
высшего образования  
**«ПЕТЕРБУРГСКИЙ ГОСУДАРСТВЕННЫЙ УНИВЕРСИТЕТ  
ПУТЕЙ СООБЩЕНИЯ ИМПЕРАТОРА АЛЕКСАНДРА I»**  

Кафедра «ИНФОРМАЦИОННЫЕ И ВЫЧИСЛИТЕЛЬНЫЕ СИСТЕМЫ»  

---

Дисциплина: «Программирование C»

<br><br><br>
<br><br><br>

### О Т Ч Е Т

### по лабораторной работе № 6

</div>

<br><br><br>
<br><br><br>

<div align="right">
  <table align="right" style="border: none;">
    <tr>
      <td style="text-align: left; border: none;">
        Выполнил студент<br>
        Факультета АИТ<br>
        Группы ИВБ-515<br>
        Принял
      </td>
      <td style="text-align: right; border: none; vertical-align: bottom; padding-left: 50px;">
        Нартов С. А.<br>
        <br>
        <br>
        Носонов В.Ю.
      </td>
    </tr>
  </table>
</div>

<br><br><br>
<br><br><br>
<br><br><br>
<br><br><br><br><br>

<div align="center">
  Санкт-Петербург<br>  
  2026<br>
</div>


## Задача
Создать односвязный список. Данными списка должны быть структуры соответствующего варианта. Создать функции для записи списка в файл и чтения списка из файла.
Реализовать минимум все функции, приведённые в лекции, предложить  свои варианты функций работы со списком.
Создать массив указателей на элементы списка, отсортировать его по выбранному полю элемента списка.
Создать меню для управления работы со списком.
В меню должны быть также пункты для сохранения списка на диске (имя файла запрашивается), чтения и просмотра файла, сортировки списка (с помощью массива указателей).

Листинг

main.c
```c
#include <stdio.h>
#include "list.h"
#include "file.h"

void inputClub(FootballClub* club){
    printf("Enter name: ");
    scanf(" %[^\n]", club->name);

    printf("Enter country: ");
    scanf(" %[^\n]", club->country);

    printf("Enter win years: ");
    scanf("%d", &club->winYears);
}

int main(){
    Node* head = NULL;

    int choice;
    char filename[100];
    char name[100];

    FootballClub club;

    do {
        printf("choose option");
        printf("1. Add club\n");
        printf("2. Show List\n");
        printf("3. Delete Club\n");
        printf("4. saveToFile\n");
        printf("5. loadFromFile\n");
        printf("6. sort by winYears\n");
        printf("0. Exit\n");

        scanf("%d", &choice);

        switch (choice){
            case 1:
                inputClub(&club);
                pushBack(&head, club);
                break;
            case 2:
                printList(head);
                break;
            case 3:
                printf("Enter club name: ");
                fgets(name, 100, stdin);
                deleteByName(&head, name);
                break;
            case 4:
                printf("filename: ");
                scanf("%s", filename);
                saveToFile(head, filename);
                break;
            case 5:
                printf("filename: ");
                scanf("%s", filename);
                loadFromFile(&head, filename);
                break;
            case 0:
                break;
            default:
                printf("Error\n");
        }
    } while (choice != 0);

    freeList(&head);

    return 0;
}
```

list.h
```c
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

    if (node == NULL){
        printf("Memory error\n");
        exit(1);
    }

    node->data = club;
    node->next = NULL;

    return node;
}

void pushBack(Node** head, FootballClub club){
    Node* newNode = createNode(club);

    if (*head == NULL){
        *head = newNode;
        return;
    }

    Node* temp = *head;

    while (temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newNode;
}

void printList(Node* head){
    if (head == NULL){
        printf("Empty list\n");
        return;
    }

    int i = 1;

    while (head != NULL){
        printf("\nClub %d\n", i++);
        printf("Name: %s\n", head->data.name);
        printf("Country: %s\n", head->data.country);
        printf("Winning years: %d\n", head->data.winYears);

        head = head->next;
    }
}


void deleteByName(Node** head, const char* name){
    if (*head == NULL){
        return;
    }

    Node* temp = *head;
    Node* prev = NULL;

    while (temp != NULL && strcmp(temp->data.name, name) != 0){
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL){
        printf("Club wasn't found\n");
        return;
    }

    if (prev == NULL){
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);

    printf("Club deleted\n");
}


void freeList(Node** head){
    Node* temp;

    while (*head != NULL){
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int getSize(Node* head){
    int size = 0;

    while (head != NULL){
        size++;
        head = head->next;
    }

    return size;
}
```

file.h
```c
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
```
