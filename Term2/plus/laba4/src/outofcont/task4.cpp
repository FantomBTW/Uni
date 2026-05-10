#include <iostream>
#include <ostream>
#include <vector>

class race {
public:
   virtual void replic() = 0;
   virtual ~race() = default;
};

class human : public race{
public:
   void replic(){
      std::cout << "glory for the mankind" << std::endl;
   }
};

class elf : public race{
public:
   void replic(){
      std::cout << "im Friren" << std::endl;
   }
};

int main(){
   std::vector<race*> team;

   team.push_back(new human());
   team.push_back(new elf());

   for ( auto smne : team ){
      smne->replic();
   }

   for ( auto smne : team ){
      delete smne;
   }
   
   team.clear();
}
