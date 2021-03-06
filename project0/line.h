/*
* Author: Grant Gasser
* Assignment Title: project0
* Assignment Description: Line class
* Date Created: 1/24/2019
* Date Last Modified: 1/28/2019
* Due Date: 1/28/2019
 */

#ifndef PROJECT0_LINE_H
#define PROJECT0_LINE_H

#include "color_rgb.h"
#include "point.h"
#include "SDL_Plotter.h"

#include <iostream>

using namespace std;

class line {
public:
    line();
    line(point p1, point p2);
    virtual ~line();

    void display(ostream&  out);
    void draw(SDL_Plotter& g);

    void setP1(point p);
    void setP2(point p);
    void setColor(color_rgb c){color = c;}

    point getP1(){return p1;}
    point getP2(){return p2;}
    color_rgb getColor(){return color;}

    void nextColor();
    void resetColor();

private:
    point p1, p2;
    color_rgb color;
    bool slope(double& m);
    bool intercept(double& b);
    int currentColor;
};

#endif //PROJECT0_LINE_H
