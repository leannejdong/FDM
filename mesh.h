//
// Created by leanne on 6/2/21.
//

#ifndef FDM_MESH_H
#define FDM_MESH_H
#include <vector>
using std::vector;

class Mesh {
public:
    Mesh();
    // overloaded ctor
    Mesh(int&, double&);
    virtual ~Mesh();

    int NumberOfNodes;
    double lengthx;
    double dx1d;
    vector<double> xgrid;

    void discretized1dgrid(vector<double>& vec);



};

#endif//FDM_MESH_H
