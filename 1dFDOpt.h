//
// Created by leanne on 6/3/21.
//

#ifndef FDM_1DFDOPT_H
#define FDM_1DFDOPT_H
#include <vector>
#include <cmath>
#include "Fields.h"

using std::vector;

namespace fvd1d
{
    Fields::vectorField1d gradX(Fields::vectorField1d& vec)
    {
        Fields::vectorField1d temp(vec.size());

        for(int i=1; i< vec.size(); ++i)
        {
            temp[i].value = (vec[i].value-vec[i-1].value)/(vec[i].x1d - vec[i-1].x1d);
        }
        return temp;
    }

    Fields::vectorField1d LaplacianX(Fields::vectorField1d& vec)
    {
        Fields::vectorField1d temp(vec.size());
        for(int i=1; i< vec.size()-1; ++i)
        {
            temp[i].value = (vec[i+1].value-2.0*vec[i].value + vec[i-1].value)/pow((vec[i].x1d - vec[i-1].x1d),2.0);
        }
        return temp;
    }

}

namespace fd
{


    Fields::vectorField2d gradX(Fields::vectorField2d vec)
    {
        Fields::vectorField2d temp(vec.size(), vector<Fields>(vec[0].size()));

        for(int i=1; i< vec.size()-1; i++)
        {
            for(int j=1; j< vec[i].size()-1; ++j)
            {
                temp[i][j].value = (vec[i][j].value - vec[i-1][j].value)/(vec[i][j].x - vec[i-1][j].x);
            }
        }
        return temp;
    }

    Fields::vectorField2d gradY(Fields::vectorField2d vec)
    {
        Fields::vectorField2d temp(vec.size(), vector<Fields>(vec[0].size()));

        for(int i=1; i< vec.size()-1; i++)
        {
            for(int j=1; j< vec[i].size()-1; ++j)
            {
                temp[i][j].value = (vec[i][j].value - vec[i][j-1].value)/(vec[i][j].y - vec[i][j-1].y);
            }
        }
        return temp;
    }

    Fields::vectorField2d gradXCDS(Fields::vectorField2d vec)
    {
        Fields::vectorField2d temp(vec.size(), vector<Fields>(vec[0].size()));

        for(int i=1; i< vec.size()-1; ++i)
        {
            for(int j=1; j< vec[i].size()-1; ++j)
            {
                temp[i][j].value = (vec[i+1][j].value - vec[i-1][j].value)/((vec[i+1][j].x - vec[i-1][j].x));
            }
        }
        return temp;
    }

    Fields::vectorField2d gradYCDS(Fields::vectorField2d vec)
    {
        Fields::vectorField2d temp(vec.size(), vector<Fields>(vec[0].size()));

        for(int i=1; i< vec.size()-1; ++i)
        {
            for(int j=1; j< vec[i].size()-1; ++j)
            {
                temp[i][j].value = (vec[i][j+1].value - vec[i][j-1].value)/((vec[i][j+1].y - vec[i][j-1].y));
            }
        }
        return temp;
    }
    Fields::vectorField2d LaplacianX(Fields::vectorField2d vec)
    {
        Fields::vectorField2d temp(vec.size(), vector<Fields>(vec[0].size()));

        for(int i=1; i< vec.size()-1; ++i)
        {
            for(int j=1; j< vec[i].size()-1; ++j)
            {
                temp[i][j].value = (vec[i+1][j].value - 2.0*vec[i][j].value + vec[i-1][j].value)/pow((vec[i][j].x - vec[i-1][j].x),2.0);
            }
        }
        return temp;
    }

    Fields::vectorField2d LaplacianY(Fields::vectorField2d vec)
    {
        Fields::vectorField2d temp(vec.size(), vector<Fields>(vec[0].size()));

        for(int i=1; i< vec.size()-1; ++i)
        {
            for(int j=1; j< vec[i].size()-1; ++j)
            {
                temp[i][j].value = (vec[i][j+1].value - 2.0*vec[i][j].value + vec[i][j-1].value)/pow((vec[i][j].y - vec[i][j-1].y),2.0);
            }
        }
        return temp;
    }

    Fields::vectorField2d lapOp(Fields::vectorField2d vec)
    {
        Fields::vectorField2d temp(vec.size(), vector<Fields>(vec[0].size()));

        for(int i=1; i< vec.size()-1; ++i)
        {
            for(int j=1; j< vec[i].size()-1; ++j)
            {
                double dxsq = pow((vec[i][j].x-vec[i-1][j].x),2.0);
                double dysq = dxsq;
                temp[i][j].value = (((vec[i+1][j].value-vec[i-1][j].value))*dysq + ((vec[i][j+1].value-vec[i][j-1].value))*dxsq)/(2.0*(dxsq+dysq));
            }
        }
        return temp;
    }

    Fields::vectorField2d poissonX(Fields::vectorField2d& vec)
    {
        Fields::vectorField2d result(vec.size(),vector<Fields>(vec[0].size()));
        Fields::vectorField2d vectemp(vec.size(),vector<Fields>(vec[0].size()));
        for(int i=1; i< vec.size()-1; ++i)
        {
            for(int j=1; j< vec[i].size()-1; ++j)
            {
                double spacingSqrY = pow((vec[i][j].y-vec[i][j-1].y),2);
                double spacingSqrX = pow((vec[i][j].x-vec[i-1][j].x),2);

                double denominator = 2.0 * (spacingSqrX + spacingSqrY);

                //   cout << " denominator "  << denominator << endl;

                vectemp[i][j].value= ( spacingSqrY*(vec[i+1][j].value+vec[i-1][j].value) )/(denominator);
                result[i][j].value=   vectemp[i][j].value;
            }
        }

        return result;
    }

    Fields::vectorField2d poissonY(Fields::vectorField2d& vec)
    {
        Fields::vectorField2d result(vec.size(),vector<Fields>(vec[0].size()));
        Fields::vectorField2d vectemp(vec.size(),vector<Fields>(vec[0].size()));
        for(int i=1; i< vec.size()-1; ++i)
        {
            for(int j=1; j< vec[i].size()-1; ++j)
            {
                double spacingSqrY = pow((vec[i][j].y-vec[i][j-1].y),2);
                double spacingSqrX = pow((vec[i][j].x-vec[i-1][j].x),2);
                double denominator = 2.0 * (spacingSqrX + spacingSqrY);


                vectemp[i][j].value= ( spacingSqrX*(vec[i][j+1].value+vec[i][j-1].value) )/(denominator);
                result[i][j].value=   vectemp[i][j].value;
            }
        }

        return result;
    }
}   // end namespace fd
#endif//FDM_1DFDOPT_H

