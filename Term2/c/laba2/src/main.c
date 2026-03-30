#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "funcs.h"


int main(){
  struct DataBase DB;
  printf("\tChoose option\n1. Read File\n2. Show clubs\n3. Add club");
  printf("\t4. correct Club\n5. Write File");

  int choise = 0;
  scanf("%d", &choise);
  switch (choise) {
    case 1:
      ReadFile();
      break;
    case 2:
      ShowClubs();
      break;
  }
  return 0;
}
