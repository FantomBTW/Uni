#include "vec.hpp"
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <numeric>
#include <vector>

void vecDemonstation(int n, int max){
    srand(time(NULL));

    std::vector<int> vec;

    int newNum = 0;
    for (int i = 0; i < n; i++){
        newNum = rand()%max+1;
        vec.push_back(newNum);
        std::cout << newNum << "\thas added" << std::endl;
    }

    std::sort(vec.begin(), vec.end());

    std::cout << "sorted vector" << std::endl;
    for (auto i : vec){
        std::cout << i << " ";
    }

    int sum = std::accumulate(vec.begin(), vec.end(), 0);
    std::cout << "sum: " << sum << std::endl;
}
