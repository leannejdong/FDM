//
// Created by leanne on 6/2/21.
//

#include "mesh.h"

Mesh::Mesh(int& n, double& txlength):
NumberOfNodes(n),
lengthx(txlength),
xgrid(NumberOfNodes, 1.0)
{
    dx1d = lengthx/(n - 1);
}

Mesh::~Mesh() {

}

void Mesh::discretized1dgrid(vector<double>& vec)
{
    for(int i = 1; i < vec.size(); ++i)
    {
        vec[i] = vec[i-1] + dx1d;

    }
}