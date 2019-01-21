/*
* Author: Grant Gasser
* Assignment Title: project0
* File Description: Curve class
* Due Date: 1/28/2019
 */

#ifndef PROJECT0_CURVE_H
#define PROJECT0_CURVE_H

#include "SDL_Plotter.h"
#include "line.h"

#include <iostream>
#include <vector>

using namespace std;

//changed from long double to double
typedef vector<pair<int, double>> DataSet_t;
typedef vector<DataSet_t> Data_t;

//dimensions of box, same as constants in main, just different names
const int MAX_ROW = 500;
const int MAX_COL = 1000;

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

curve::curve() {
    sameScale = false;
}

curve::~curve() {
    sameScale = false;
}

void curve::display(Data_t data, ostream &out) {

}

void curve::draw(Data_t data, SDL_Plotter &g) {
    int maxX = 0, maxY = 0;


    int len = data.size();

    //each iteration is a line/curve
    for(int i = 0; i < len; i++){
        int numPts = data[i].size();
        int maxX_set = 0, maxY_set = 0;



        for(int j = 0; j < numPts; j++){

            //find max points of individual data sets
            if(data[i][j].first > maxX)
                maxX_set = data[i][j].first;

            if(data[i][j].second > maxY)
                maxY_set = data[i][j].second;

        }

        //find max points of all the curves
        if(maxX_set > maxX)
            maxX = maxX_set;
        if(maxY_set > maxY)
            maxY = maxY_set;

        //test
        cout << "MaxY of set: " << maxY_set << endl;
        cout << "MaxX of set: " << maxX_set << endl;
    }
    cout << "MaxY: " << maxY << endl;
    cout << "MaxX: " << maxX << endl;

    //Plot axes
    plotAxis(25, maxX, maxY, g);
    plotTickMarks(5, maxX, maxY, g);

}

void curve::plotAxis(int margin, int maxX, int maxY, SDL_Plotter &g) {
    line yAxis, xAxis;

    //set max
    int max = 0;

    if(maxX > maxY)
        max = maxX;
    else
        max = maxY;

    //set origin and end points for both x and y objects
    point xOrigin(margin, MAX_ROW-margin);
    point xEnd(margin+max, MAX_ROW-margin);//used to be margin+maxX

    point yOrigin(margin, MAX_ROW-margin);
    point yEnd(margin, MAX_ROW-max); //used to be MAX_ROW-maxY

    //TESTING
    cout << "X origin and end: " << endl;
    yOrigin.display(cout);
    yEnd.display(cout);


    //set the origin and end points of the lines
    xAxis.setP2(xEnd);
    xAxis.setP1(xOrigin);
    yAxis.setP2(yEnd);
    yAxis.setP1(yOrigin);

    //draw X axis
    xAxis.draw(g);
    //yAxis.draw(g);

    //draw Y axis
    for(int i = yEnd.getY(); i < yOrigin.getY(); i++){
        g.plotPixel(margin, i, 0, 0, 0);
    }

    g.update();
}

void curve::plotTickMarks(int margin, int maxX, int maxY, SDL_Plotter &g) {

}

bool curve::goodPoints(line a, int margin, SDL_Plotter &g) {

}

#endif //PROJECT0_CURVE_H
