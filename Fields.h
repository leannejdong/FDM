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

    using vec1dField = vector<Fields>;

    double value;
};


#endif//FDM_FIELDS_H
