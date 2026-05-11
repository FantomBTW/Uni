#include "depart.hpp"
#include "firm.hpp"
#include "worker.hpp"
#include <iostream>
#include <string>
#include <vector>

#define F std::string
#define D std::string
#define W std::string

department<D, W> createGULAG(){
   worker<W> w1("worker 1");
   worker<W> w2("worker 2");
   worker<W> w3("worker 2");

   std::vector<worker<W>> joblesses;
   joblesses.push_back(w1);
   joblesses.push_back(w2);
   joblesses.push_back(w3);

   D mahname = "mah";

   department<D, W> mah(joblesses, mahname);
   return mah;
}

department<D, W> makeWorse(){
   std::vector<worker<W>> joblesses;

   worker<W> w100("worker 100");
   worker<W> w200("worker 200");

   joblesses.push_back(w100);
   joblesses.push_back(w200);

   D VKmsgName = "evilmessanger";

   department<D, W> VKmsg(joblesses, VKmsgName);
   return VKmsg;
};


int main(){
   F evilCorpName = "VK";
   department<D, W> mah = createGULAG();

   department<D, W> VKmsg = makeWorse();

   firm<F, D, W> evilCorp(std::vector<department<D, W>>{mah, VKmsg}, evilCorpName);

   std::cout << std::endl;

   std::cout << evilCorp.getFirmId() << std::endl;
   for (auto& i : evilCorp.getDeps()){
      std::cout << '\t' << i.getDepId() << std::endl;
      for (auto& j : i.getworkers()){
         std::cout << '\t' << '\t' << j.getId() << std::endl;
      }
   }

   std::cout << std::endl;
}
