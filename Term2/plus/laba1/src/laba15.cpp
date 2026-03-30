#include <cstring>
#include <iostream>
#include <string.h>

struct Students{
  int age;
  char * name;
  double grade;
};

int main(int argc, char* argv[])
{
  int N = std::stoi(argv[1]);
  
  Students* studs = new Students[N];
  
  for (int i=0; i < N; i++)
  {
    std::cout << "student №" << i+1 << std::endl;
    char buffer[100];
   
    std::cout<<"name:";
    std::cin>>buffer;
    int namelen = std::strlen(buffer);

    studs[i].name = new (std::nothrow)char[namelen+1];
    if (studs[i].name == nullptr)
    {
      std::cerr << "memory error";
      return 1;
    }
    std::strcpy(studs[i].name, buffer);
    std::cout << "age:";
    std::cin >> studs[i].age;

    std::cout << "grade:";
    std::cin >> studs[i].grade;

    std::cout<<std::endl;
  }

  for (int i=0; i < N; i++)
  {
    std::cout << "student №" << i+1 << std::endl;
    std::cout << "stud name" << studs[i].name << '\n';
    std::cout << "age" << studs[i].age << '\n';
    std::cout << "stud grade" << studs[i].grade << '\n';
    std::cout<<std::endl;
  }

  for (int i = 0; i < N; ++i){
    delete[] studs[i].name;
    studs[i].name=nullptr;
  }

  delete[] studs;
    
  return 0;
}
