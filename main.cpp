#include <iostream>
#include "mesh.h"
#include "Fields.h"
#include "helper.h"
#include "1dFDOpt.h"
using std::cerr;
/*!
 * 1d -linear convection
 * Grid, discretized that grid
 * Fields class, U, V, P in 1d we only need U
 * solution class that will hold stuff like dt, number of time steps
 * write U using a fileWriter class
 * class for grid // class for soln // class for fields // class for equations
 * @return
 */
int main() {
    // 1d linear convection
    // du/dt + c*(du/dx) = 0;

    int N{10};
    double totallength{1.0};

    Mesh mesh_(N, totallength);
//    std::cerr << mesh_.NumberOfNodes << "\n";
//    std::cerr << mesh_.xgrid.size() << "\n";
    Fields UField;
    #include "createFields.h"

    vector<Fields> UFieldvec(5);
    for(const auto& uvec : UFieldvec){
        cerr << uvec.value << ' ';
    }

    mesh_.discretized1dgrid(mesh_.xgrid);

    print1dVec(mesh_.xgrid);


    return 0;
}
