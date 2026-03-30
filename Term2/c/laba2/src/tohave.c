#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
    char country[100];
    int victory_years[50];
    int victory_count;
} FootballClub;

typedef struct {
    FootballClub* clubs;
    int count;
    int capacity;
} ClubDatabase;

void initDatabase(ClubDatabase* db) {
    db->capacity = 10;
    db->count = 0;
    db->clubs = (FootballClub*)malloc(db->capacity * sizeof(FootballClub));
}

void addClub(ClubDatabase* db) {
    if (db->count >= db->capacity) {
        db->capacity *= 2;
        db->clubs = (FootballClub*)realloc(db->clubs, db->capacity * sizeof(FootballClub));
    }
    FootballClub* newClub = &db->clubs[db->count];
    printf("Введите название клуба: ");
    scanf(" %99[^\n]", newClub->name);
    printf("Введите страну: ");
    scanf(" %99[^\n]", newClub->country);
    printf("Введите количество побед: ");
    scanf("%d", &newClub->victory_count);
    for (int i = 0; i < newClub->victory_count; i++) {
        printf("Год победы %d: ", i + 1);
        scanf("%d", &newClub->victory_years[i]);
    }
    db->count++;
    printf("Клуб добавлен!\n");
}

void saveToFile(ClubDatabase* db) {
    char filename[100];
    printf("Введите имя файла для сохранения: ");
    scanf(" %99s", filename);
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Ошибка открытия файла!\n");        return;
    }
    fwrite(&db->count, sizeof(int), 1, file);
    fwrite(db->clubs, sizeof(FootballClub), db->count, file);
    fclose(file);
    printf("Данные сохранены!\n");
}

void loadFromFile(ClubDatabase* db) {
    char filename[100];
    printf("Введите имя файла для загрузки: ");
    scanf(" %99s", filename);
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Файл не найден!\n");
        return;
    }
    free(db->clubs);
    initDatabase(db);
    fread(&db->count, sizeof(int), 1, file);
    db->capacity = db->count;
    db->clubs = (FootballClub*)malloc(db->capacity * sizeof(FootballClub));
    fread(db->clubs, sizeof(FootballClub), db->count, file);
    fclose(file);
    printf("Данные загружены!\n");
}

void viewClubs(ClubDatabase* db) {
    if (db->count == 0) {
        printf("Список пуст.\n");
        return;
    }
    for (int i = 0; i < db->count; i++) {
        printf("\n--- Клуб %d ---\n", i + 1);
        printf("Название: %s\n", db->clubs[i].name);
        printf("Страна: %s\n", db->clubs[i].country);
        printf("Побед: %d\n", db->clubs[i].victory_count);
    }
}

void freeDatabase(ClubDatabase* db) {
    free(db->clubs);
    db->clubs = NULL;
    db->count = 0;
    db->capacity = 0;
}

int main() {
    ClubDatabase db;
    initDatabase(&db);    int choice;
    while (1) {
        printf("\n=== Меню ===\n");
        printf("1. Добавить клуб\n");
        printf("2. Показать все клубы\n");
        printf("3. Сохранить в файл\n");
        printf("4. Загрузить из файла\n");
        printf("5. Выход\n");
        printf("Выберите пункт: ");
        scanf("%d", &choice);
        if (choice == 1) {
            addClub(&db);
        } else if (choice == 2) {
            viewClubs(&db);
        } else if (choice == 3) {
            saveToFile(&db);
        } else if (choice == 4) {
            loadFromFile(&db);
        } else if (choice == 5) {
            break;
        } else {
            printf("Неверный выбор!\n");
        }
    }
    freeDatabase(&db);
    return 0;
}
