/*
* Author: Grant Gasser
* Assignment Title: project0
* File Description: Line class
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

line::line(point p1, point p2) {
    this->p1 = p1;
    this->p2 = p2;

    color.setR(0);
    color.setG(0);
    color.setB(0);

    currentColor = 0;
}

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

void line::display(ostream& out){
    out << "Not sure what I'm displaying..." << endl;
}

void line::draw(SDL_Plotter& g){
    double m, b;
    int y;
    double delta = 0.001;

    if(slope(m)) {
        intercept(b);
        if(p1.getX() < p2.getX()) {
            for(double x = p1.getX(); x <= p2.getX(); x += delta) {
                y = m * x + b + 0.5;
                g.plotPixel(x, y, color.getR(), color.getG(), color.getB());
            }
        }
        else {
            for(double x = p1.getX(); x >= p2.getX(); x -= delta) {
                y = m * x + b + 0.5;
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


void line::setP1(point p){
    p1 = p;
}

void line::setP2(point p){
    p2 = p;
}

void line::nextColor(){
    currentColor += 50;
    color.setB(currentColor);
    color.setG(currentColor);
    color.setR(currentColor);
}

void line::resetColor(){
    currentColor = 0;
}

bool line::slope(double& m){
    bool hasSlope = false;

    hasSlope = (p1.getX() != p2.getX());

    if(hasSlope) {
        m = (p1.getY() - p2.getY()) / (p1.getX() - p2.getX());
    }

    return hasSlope;
}
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
