/*
* Author: Grant Gasser
* Assignment Title: project0
* File Description: Point class
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

point::point() {
    x = 10;
    y = 10;
    color.setR(0);
    color.setG(0);
    color.setB(0);
}

point::point(int x, int y) {
    this->x = x;
    this->y = y;
    color.setR(0);
    color.setG(0);
    color.setB(0);
}


point::point(const point& p){
    this->color = p.color;
    this->x = p.x;
    this->y = p.y;
}

//WHAT TO SET TO?
point::~point(){
    x = -1;
    y = -1;

    //what to do with color?
    color.setR(0);
    color.setB(0);
    color.setG(0);
}

void point::setY(int y){
    this->y = y;
}

void point::setX(int x){
    this->x = x;
}

void point::setColor(color_rgb c){
    this->color = c;
}

int point::getX(){
    return x;
}

int point::getY(){
    return y;
}

color_rgb point::getColor(){
    return color;
}

point& point::operator=(const point& rhs){
    this->x = rhs.x;
    this->y = rhs.y;
    this->color = rhs.color;

    cout << "Called operator=" << endl;

    return *this;
}

void point::display(ostream& out){
    out << "(" << x << ", " << y << ")" << endl;
}

void point::draw(SDL_Plotter& g) {

    g.plotPixel(x, y, color.getR(), color.getG(), color.getB());

    g.update();
}





#endif //PROJECT0_POINT_H
