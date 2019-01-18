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

typedef vector<pair<int, double>> DataSet_t;
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

            //find max of individual data sets
            if(data[i][j].first > maxX)
                maxX_set = data[i][j].first;

            if(data[i][j].second > maxY)
                maxY_set = data[i][j].second;


            //
        }

        //find max of all the curves
        if(maxX_set > maxX)
            maxX = maxX_set;
        if(maxY_set > maxY)
            maxY = maxY_set;

        //test
        cout << maxY << endl;
        cout << maxY_set << endl;
    }

    //Plot axes
    plotAxis(15, maxX, maxY, g);
    plotTickMarks(20, maxX, maxY, g);
}

void curve::plotAxis(int margin, int maxX, int maxY, SDL_Plotter &g) {
    line yAxis, xAxis;

    //set origin and end points for both x and y objects
    point xOrigin(margin, margin);
    point xEnd(margin+maxX, margin);

    point yOrigin(margin, margin);
    point yEnd(margin, margin+maxY);


    //set the origin and end points of the lines
    xAxis.setP2(xEnd);
    xAxis.setP1(xOrigin);
    yAxis.setP2(yEnd);
    yAxis.setP1(yOrigin);

    xAxis.draw(g);
    yAxis.draw(g);
}

void curve::plotTickMarks(int margin, int maxX, int maxY, SDL_Plotter &g) {

}

bool curve::goodPoints(line a, int margin, SDL_Plotter &g) {

}

#endif //PROJECT0_CURVE_H
