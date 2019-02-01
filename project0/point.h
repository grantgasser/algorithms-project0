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

/*
* description: constructor
* return:
* precondition:
* postcondition: point obj exists, values set
*/
point::point() {
    x = 10;
    y = 10;
    color.setR(0);
    color.setG(0);
    color.setB(0);
}

/*
* description: constructor, 2 params
* return:
* precondition:
* postcondition: point obj exists, values set
*/
point::point(int x, int y) {
    this->x = x;
    this->y = y;
    color.setR(0);
    color.setG(0);
    color.setB(0);
}

/*
* description: copy constructor
* return:
* precondition: point obj exists
* postcondition: both point obj exists, values set
*/
point::point(const point& p){
    this->color = p.color;
    this->x = p.x;
    this->y = p.y;
}

/*
* description: destructor
* return:
* precondition:
* postcondition: point obj exists, values set
*/
point::~point(){
    x = -1;
    y = -1;

    color.setR(0);
    color.setB(0);
    color.setG(0);
}

/*
* description: setY
* return:
* precondition: point exists
* postcondition: y val is set
*/
void point::setY(int y){
    this->y = y;
}

/*
* description: setX
* return:
* precondition: point exists
* postcondition: x val is set
*/
void point::setX(int x){
    this->x = x;
}

/*
* description: setColor
* return:
* precondition: point exists
* postcondition: color val is set
*/
void point::setColor(color_rgb c){
    this->color = c;
}

/*
* description: getX
* return: returns int x
* precondition: point exists
* postcondition:
*/
int point::getX(){
    return x;
}

/*
* description: getY
* return: returns int x
* precondition: point exists
* postcondition:
*/
int point::getY(){
    return y;
}

/*
* description: getColor
* return: returns color_rgb exists
* precondition: point exists
* postcondition:
*/
color_rgb point::getColor(){
    return color;
}

/*
* description: Overloaded assigment operator
* return: returns reference to point obj
* precondition: point exists
* postcondition: lhs set to rhs
*/
point& point::operator=(const point& rhs){
    this->x = rhs.x;
    this->y = rhs.y;
    this->color = rhs.color;

    return *this;
}

/*
* description: display, debugging
* return:
* precondition: line exists
* postcondition: sets the point values
*/
void point::display(ostream& out){
    out << "(" << x << ", " << y << ")" << endl;
}

/*
* description: draw the point, one pixel
* return:
* precondition: point exists
* postcondition: pixel drawn
*/
void point::draw(SDL_Plotter& g) {

    g.plotPixel(x, y, color.getR(), color.getG(), color.getB());

    g.update();
}


#endif //PROJECT0_POINT_H
