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

/*
* description: constructor
* return:
* precondition:
* postcondition: sets the point values
*/
line::line(){
    p1.setX(0);
    p1.setY(0);
    p2.setX(20);
    p2.setY(20);

    color.setR(0);
    color.setG(0);
    color.setB(0);

    currentColor = 0;
}

/*
* description: constructor, 2 parameters p1 and p2
* return:
* precondition:
* postcondition: sets the point values
*/
line::line(point p1, point p2) {
    this->p1 = p1;
    this->p2 = p2;

    color.setR(0);
    color.setG(0);
    color.setB(0);

    currentColor = 0;
}

/*
* description: destructor
* return:
* precondition:
* postcondition: sets everything to 0
*/
line::~line() {
    p1.setX(0);
    p1.setY(0);
    p2.setX(0);
    p2.setY(0);

    color.setR(0);
    color.setG(0);
    color.setB(0);

    currentColor = 0;
}

/*
* description: display, debugging
* return:
* precondition: line exists
* postcondition: sets the point values
*/
void line::display(ostream& out){
    out << "p1.x: " << p1.getX() << " p1.y: " << p1.getY() << endl;
    out << "p2.x: " << p2.getX() << " p2.y: " << p2.getY() << endl;
}

/*
* description: draw the line
* return:
* precondition: line exists
* postcondition: draw between the two points
*/
void line::draw(SDL_Plotter& g){
    double m, b;
    int y;
    double delta = 0.001;

    if(slope(m)) {
        intercept(b);
        if(p1.getX() < p2.getX()) {
            for(double x = p1.getX(); x <= p2.getX(); x += delta) {
                y = m * x + b;
                g.plotPixel(x, y, color.getR(), color.getG(), color.getB());
            }
        }
        else {
            for(double x = p1.getX(); x >= p2.getX(); x -= delta) {
                y = m * x + b;
                g.plotPixel(x, y, color.getR(), color.getG(), color.getB());
            }
        }
    }
    else {
        if(p1.getY() > p2.getY()) {
            delta = -1;
        }
        for(int y = p1.getY(); p1.getY() != p2.getY(); y += delta) {
            g.plotPixel(p1.getX(), y, color.getR(), color.getG(), color.getB());
        }
    }

    g.update();
}

/*
* description: set p1
* return:
* precondition: line exists
* postcondition: p1 is set
*/
void line::setP1(point p){
    p1 = p;
}

/*
* description: set p2
* return:
* precondition: line exists
* postcondition: p2 is set
*/
void line::setP2(point p){
    p2 = p;
}

/*
* description: go to dif rgb values, new color
* return:
* precondition: line exists
* postcondition: color_rgb has new values
*/
void line::nextColor(){
    currentColor = 75;
    int r = this->color.getR();
    int b = this->color.getB();
    color = color_rgb(r+currentColor, 0, b+currentColor);
}

/*
* description: reset to 1
* return:
* precondition: line exists
* postcondition: color reset
*/
void line::resetColor(){
    currentColor = 1;
}

/*
* description: does line have slope?
* return: bool is it has slope or not
* precondition: line exists
* postcondition: slope is calculated
*/
bool line::slope(double& m){
    bool hasSlope = false;

    hasSlope = (p1.getX() != p2.getX());

    if(hasSlope) {
        m = double(p1.getY() - p2.getY()) / (p1.getX() - p2.getX());
    }

    return hasSlope;
}
/*
* description: does line have intercept
* return: bool intercept or not
* precondition: line exists
* postcondition: intercept calculated
*/
bool line::intercept(double& b){
    bool hasIntercept = false;
    double m;

    hasIntercept = slope(m);

    if(hasIntercept) {
        b = p1.getY() - (m * p1.getX());
    }

    return hasIntercept;
}

#endif //PROJECT0_LINE_H
