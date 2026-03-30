struct Club{
  char name[20];
  char country[20];
  int  victoryYr[10];
  int  victoryCnt;
};

struct DataBase{
  int count;
  struct Club* club;
};
