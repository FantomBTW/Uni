#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

void ReadFile(){
	char filename[128];
	printf("Please, Enter the filename\n");
	fgets(filename, 128, stdin);
	filename[strlen(filename)-1] = '\0';

	FILE *file = fopen(filename, "r");
	if (file == NULL){
		printf("file wasnt found");
		return;
	}
	
	int newClbsCnt = 0;
	fscanf(file, "%d\n", &newClbsCnt);
	
	return;
}

void ShowClubs(){
	return;
}

void AddClub(){
	return;
}

void ChangeClub(){
	return;
}

void WriteFile(){
	return;
}
