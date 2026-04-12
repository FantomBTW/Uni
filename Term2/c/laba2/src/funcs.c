#include "funcs.h"
#include <stdio.h>

void ReadFile(struct Club **arr, int *cnt){
	char filename[128];
	printf("Please, Enter the filename\n");
	while (getchar() != '\n');
	fgets(filename, 128, stdin);

	filename[strcspn(filename, "\n")] = '\0';
	FILE *file = fopen(filename, "r");
	if (file == NULL){
		printf("file wasnt found");
		return;
	}

	int newClbsCnt = 0;
	fscanf(file, "%d\n", &newClbsCnt);

	if (*arr != NULL) {
  	free(*arr);
  }

	struct Club *newArrClb = (struct Club*) malloc(newClbsCnt * sizeof(struct Club));

	for (int i = 0; i < newClbsCnt; i++){
		fscanf(file, "%[^;];", newArrClb[i].name);
		fscanf(file, "%[^;];", newArrClb[i].country);
		fscanf(file, "%d", &newArrClb[i].victoryCnt);

		for (int q = 0; q < newArrClb[i].victoryCnt; q++){
			fscanf(file, ";%d", &newArrClb[i].victoryYr[q]);
		}
		fscanf(file, "\n");
	}

	fclose(file);
	*arr = newArrClb;
	*cnt = newClbsCnt;
	return;
}

void ShowClubs(struct Club *clbArr, int cnt){
	if (cnt == 0){
		printf("list is empty");
		return;
	}


	printf("\n");
  printf("|  № | name                | Country             | Years                          |\n");
  printf("|----|---------------------|---------------------|--------------------------------|\n");
	for (int i = 0; i < cnt; i++) {
		printf("| %2d | %-19s | %-19s | ", i + 1, clbArr[i].name, clbArr[i].country);
		
		for (int j = 0; j < clbArr[i].victoryCnt; j++) {
			printf("%d", clbArr[i].victoryYr[j]);
		  if (j < clbArr[i].victoryCnt - 1) {
		    printf(", ");
		  }
		}
		
		if (clbArr[i].victoryCnt == 0) {
		    printf("Нет побед");
		}
		printf("\n");
    }

	return;
}
void AddClub(struct Club **arr, int *count) {
  struct Club new_club;
  
  while (getchar() != '\n');
  
  printf("Enter Club name: ");
  fgets(new_club.name, sizeof(new_club.name), stdin);
  new_club.name[strcspn(new_club.name, "\n")] = '\0';
  
  printf("Enter country: ");
  fgets(new_club.country, sizeof(new_club.country), stdin);
  new_club.country[strcspn(new_club.country, "\n")] = '\0';
  
  printf("Enter Count of Years of wins(up to 10): ");
  scanf("%d", &new_club.victoryCnt);
  
  if (new_club.victoryCnt > 10) {
  	new_club.victoryCnt = 10;
  	printf("UP TO 10\n");
  }
  
  if (new_club.victoryCnt > 0) {
  	printf("Enter Years:\n");
  	for (int i = 0; i < new_club.victoryCnt; i++) {
  		printf("Year №%d: ", i + 1);
  		scanf("%d", &new_club.victoryYr[i]);
  	}
  }
  
  // Перевыделение памяти
  struct Club *new_arr = (struct Club*)realloc(*arr, (*count + 1) * sizeof(struct Club));
  if (new_arr == NULL) {
  	printf("realloc error!\n");
  	return;
  }
  
  new_arr[*count] = new_club;
  (*count)++;
  *arr = new_arr;
  printf("Club added succesful!\n");
}

//------------------------------------------------------------------

void ChangeClub(struct Club *arr, int cnt){
	if (cnt == 0){
		printf("nothing to change");
		return;
	};

input_of_index:
	int clbToChange;
	printf("Enter number of club to change");
	scanf("%d", &clbToChange);

	if (clbToChange < 1 || clbToChange > cnt){
		printf("wrong club index");
		goto input_of_index;
	}

	clbToChange--;
	while (getchar() != '\n');	

	printf("Editing the %s\n", arr[clbToChange].name);

	char buffer[100];

	printf("Pls, Enter new name (Return to save existing): ");
  fgets(buffer, sizeof(buffer), stdin);
  buffer[strcspn(buffer, "\n")] = '\0';
  if (strlen(buffer) > 0)
    strcpy(arr[clbToChange].name, buffer);

  printf("Pls, Enter new Country (Return to save existing): ");
  fgets(buffer, sizeof(buffer), stdin);
  buffer[strcspn(buffer, "\n")] = '\0';
  if (strlen(buffer) > 0)
  	strcpy(arr[clbToChange].country, buffer);
  
  char cnt_buf[20];
input_new_victory_cnt:
  printf("Pls, Enter new wins Count (Return to save existing): ");
  fgets(cnt_buf, sizeof(cnt_buf), stdin);
  cnt_buf[strcspn(cnt_buf, "\n")] = '\0';
  if (strlen(cnt_buf) > 0) {
  	int new_cnt = atoi(cnt_buf);
  	if (new_cnt <= 10) {
  		arr[clbToChange].victoryCnt = new_cnt;
  	} else {
  		printf("UP TO 10\n");
  		goto input_new_victory_cnt;
  	}
  }

	if (arr[clbToChange].victoryCnt > 0) {
  printf("Pls, Enter new wins Count (Return to save existing): \n");
  for (int i = 0; i < arr[clbToChange].victoryCnt; i++) {
    printf("Victory Year №%d: ", i + 1);
    char year_buf[20];
    fgets(year_buf, sizeof(year_buf), stdin);
    year_buf[strcspn(year_buf, "\n")] = '\0';
  	if (strlen(year_buf) > 0) {
        arr[clbToChange].victoryYr[i] = atoi(year_buf);
      }
  	}
	}
    
  printf("Update successful!\n");
	return;
}

//------------------------------------------------------------------

void WriteFile(struct Club *arr, int cnt){
  if (cnt == 0) {
    printf("\nNothing to save.\n");
    return;
  }
    
  char filename[128];
  printf("Pls, Enter filename: ");
    
  while (getchar() != '\n');
  fgets(filename, 128, stdin);
  filename[strcspn(filename, "\n")] = '\0';
    
  FILE *file = fopen(filename, "w");
  if (file == NULL) {
    printf("Error open %s to write!\n", filename);
    return;
  }
    
  fprintf(file, "%d\n", cnt);
    
  for (int i = 0; i < cnt; i++) {
    fprintf(file, "%s;%s;%d", 
      arr[i].name, 
      arr[i].country, 
      arr[i].victoryCnt);
        
  	for (int j = 0; j < arr[i].victoryCnt; j++) {
    	fprintf(file, ";%d", arr[i].victoryYr[j]);
  	}
  	fprintf(file, "\n");
  }
    
  fclose(file);
  printf("Save successful to file %s\n", filename);

	return;
}
