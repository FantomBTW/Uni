#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "funcs.h"


int main(){
  struct Club *clubs = NULL;
  int clbCnt = 0;

  printf("\tChoose option\n1. Read File\n2. Show clubs\n3. Add club");
  printf("\t4. correct Club\n5. Write File");

  int choise = 0;
  scanf("%d", &choise);
  switch (choise) {
    case 1:
      ReadFile(&clubs, &clbCnt);
      break;

    case 2:
      ShowClubs(clubs, clbCnt);
      break;

    case 3:
      AddClub(&clubs, &clbCnt);
      break;

    case 4:
      ChangeClub(clubs, clbCnt);
      break;

    case 5:
      WriteFile(clubs, clbCnt);
      break;

    case 6:
      printf("Exiting...\n");
      free(clubs);
      break;

    default:
      printf("WIP(or u enter wrong number)");
      break;
  }
  return 0;
}
