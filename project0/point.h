/*
* Author: Grant Gasser
* Assignment Title: project0
* Assignment Description: Point class
* Date Created: 1/24/2019
* Date Last Modified: 1/28/2019
* Due Date: 1/28/2019
 */



#ifndef PROJECT0_POINT_H
#define PROJECT0_POINT_H

#include <iostream>
#include "color_rgb.h"
#include "SDL_Plotter.h"

using namespace std;

class point {
public:
    point();
    point(int x, int y);
    point(const point& p);
    virtual ~point();
    void setY(int y);
    void setX(int x);
    void setColor(color_rgb c);
    int getX();
    int getY();
    color_rgb getColor();
    point& operator=(const point& rhs);
    void display(ostream&);
    void draw(SDL_Plotter&);

private:
    int x, y;
    color_rgb color;
};

#endif //PROJECT0_POINT_H
