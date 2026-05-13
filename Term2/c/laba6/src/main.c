#include <stdio.h>
#include "list.h"
#include "file.h"
#include "sort.h"

void inputClub(FootballClub* club){
    printf("Введите название клуба: ");
    scanf(" %[^\n]", club->name);

    printf("Введите страну: ");
    scanf(" %[^\n]", club->country);

    printf("Введите годы побед: ");
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
                break;
            case 5:
                printf("filename: ");
                scanf("%s", filename);
                loadFromFile(&head, filename);
                break;
            case 6:
                sortByWinYears(head);
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
