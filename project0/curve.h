/*
* Author: Grant Gasser
* Assignment Title: project0
* Assignment Description: Curve class
* Date Created: 1/24/2019
* Date Last Modified: 1/28/2019
* Due Date: 1/28/2019
 */

#ifndef PROJECT0_CURVE_H
#define PROJECT0_CURVE_H

#include <vector>
#include <cmath>
#include "SDL_Plotter.h"
#include "line.h"


typedef vector<pair<int,long double>> DataSet_t;
typedef vector<DataSet_t> Data_t;

class curve {
public:
    curve();
    virtual ~curve();
    void display(Data_t data, ostream&);
    void draw(Data_t data, SDL_Plotter&);
    bool getSameScale(){ return sameScale;}
    void setSameScale(bool t){sameScale = t;}

private:
    void plotAxis(int margin, int maxX, int maxY, SDL_Plotter& g);
    void plotTickMarks(int margin, int maxX, int maxY, SDL_Plotter& g);
    bool goodPoints(line a, int margin, SDL_Plotter& g);
    bool sameScale;

};

#endif //PROJECT0_CURVE_H
