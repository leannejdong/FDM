//
// Created by leanne on 6/3/21.
//

#ifndef FDM_FIELDS_H
#define FDM_FIELDS_H
#include <vector>
using std::vector;

class Fields {
public:
    Fields();
    virtual ~Fields();

    using vectorField1d = vector<Fields>;
    using vectorField2d = vector<vector<Fields>>;
    using scalardouble = double;
    using longintt = int32_t;
    double value;
    double x1d;
    double x,y;
};


#endif//FDM_FIELDS_H
