//
// Created by leanne on 6/3/21.
//

#ifndef FDM_HELPER_H
#define FDM_HELPER_H
#include <iostream>
void print1dVec(std::vector<double>& vec)
{
    for(const auto &v : vec){
        std::cerr << v << "\n";
    }


}
#endif//FDM_HELPER_H
