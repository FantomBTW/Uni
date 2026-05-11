#include "worker.hpp"
#include "firm.hpp"
#include "worker.hpp"
#include <string>

int main(){
   company<std::string> Linux_Foundation;
   Linux_Foundation.addWorker(worker<std::string>("Linus"));
   Linux_Foundation.addWorker(worker<std::string>("Richard"));

   Linux_Foundation.prnWorkers();
}
