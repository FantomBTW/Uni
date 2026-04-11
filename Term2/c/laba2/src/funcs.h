#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

void ReadFile(struct Club **arr, int *cnt);

void ShowClubs(struct Club *clbArr, int cnt);

void AddClub(struct Club **arr, int *count);

void ChangeClub(struct Club *arr, int cnt);

//------------------------------------------------------------------

void WriteFile(struct Club *arr, int cnt);
