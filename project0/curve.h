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
#include <iostream>
#include "SDL_Plotter.h"
#include "line.h"


typedef vector<pair<int,long double>> DataSet_t;
typedef vector<DataSet_t> Data_t;

//const double MAX_ROW = 300; //300
//const double MAX_COL = 600; //600
//const int MARGIN = MAX_COL/20; //MAX_COL/20

class curve {
public:
    curve();
    virtual ~curve();
    void display(Data_t data, ostream&);
    void draw(Data_t data, SDL_Plotter&);
    bool getSameScale(){ return sameScale;}
    void setSameScale(bool t){sameScale = t;}
    void setMaxConstants(SDL_Plotter &);

private:
    void plotAxis(int margin, int maxX, int maxY, SDL_Plotter& g);
    void plotTickMarks(int margin, int maxX, int maxY, SDL_Plotter& g);
    bool goodPoints(line a, int margin, SDL_Plotter& g);
    bool sameScale;
    int max_row, max_col, margin;
};

//sets the dimensions of the graph given from the driver
void curve::setMaxConstants(SDL_Plotter &g){
    max_row = g.getRow();
    max_col = g.getCol();
    margin = max_col / 20;

    //cout << max_row << ", " << max_col  << ", " << margin << endl;
}

/*
* description: constructor
* return:
* precondition:
* postcondition: point obj exists, values set
*/
curve::curve() {
    sameScale = true;
}

/*
* description: destructor
* return:
* precondition:
* postcondition: point obj exists, values set
*/
curve::~curve() {
    sameScale = false;
}

//unused
void curve::display(Data_t data, ostream &out) {

}

/*
* description: draw the curve, lines between pixels, call plot axes and ticks
* return:
* precondition: data obj exists and is populated, plotter
* postcondition: curve drawn
*/
void curve::draw(Data_t data, SDL_Plotter &g) {
    int maxX = 0, maxY = 0;
    int x_1, y_1, x_2, y_2;
    point p1, p2;
    double x_scale, y_scale;
    line line;
    line.setColor(color_rgb(0,150,0));

    int len = data.size();

    //set size of graph
    setMaxConstants(g);


    //each iteration is a line/curve
    for(int i = 0; i < len; i++){
        int numPts = data[i].size();
        double maxX_set = 0, maxY_set = 0;

        for(int j = 0; j < numPts; j++){
            //use scale variable to scale or divide the data
            if(sameScale){
                x_scale = 1;
                y_scale = 1;
            }
            else {
                //exp
                if(i == 0){
                    x_scale = (0.15*max_col);
                    y_scale = 1;
                }
                //linear
                if (i == 1) {
                    x_scale = max_col/max_row;
                    y_scale = 1;
                }
                //quadratic
                if (i == 2) {
                    x_scale = max_col/sqrt(max_row);
                    y_scale = 1;
                }
                //cubic
                if (i == 3) {
                    x_scale = max_col/cbrt(max_row);
                    y_scale = 1;
                }
                //log
                if(i == 4){
                    x_scale = 1.0/(.035*max_col);
                    y_scale = (.035*max_col);
                }
            }

            //set the scaled point values
            x_1 = (data[i][j].first*x_scale) + margin;
            x_2 = (data[i][j+1].first*x_scale) + margin;
            y_1 = (max_row - margin - (data[i][j].second*y_scale));
            y_2 = (max_row - margin - (data[i][j+1].second*y_scale));

            line.setP1(point(x_1,y_1));
            line.setP2(point(x_2, y_2));

            //if points within box
            if(goodPoints(line, margin, g))
                line.draw(g);

            //find max points of individual data sets
            if(data[i][j].first > maxX && data[i][j].first < (max_col-margin)){
                maxX_set = data[i][j].first;
            }
            if(data[i][j].second > maxY && data[i][j].second < (max_row-margin)){
                maxY_set = data[i][j].second;
            }

        }
        line.nextColor();

        //find max points of all the curves
        if(maxX_set > maxX)
            maxX = maxX_set;
        if(maxY_set > maxY)
            maxY = maxY_set;
    }

    //Plot axes
    plotAxis(margin, maxX, maxY, g);
}

/*
* description: plot x and y axes
* return:
* precondition: max values passed, plotter obj exists
* postcondition: axes drawn
*/
void curve::plotAxis(int margin, int maxX, int maxY, SDL_Plotter &g) {
    line yAxis(point(margin,maxY), point(margin-1, margin));
    line xAxis(point(margin,maxY), point(maxX, maxY));

    //draw axes
    xAxis.draw(g);
    yAxis.draw(g);

    g.update();

    plotTickMarks(margin, maxX, maxY, g);
}

/*
* description: plot ticks on axes
* return:
* precondition: max values passed, plotter obj exists
* postcondition: ticks drawn
*/
void curve::plotTickMarks(int margin, int maxX, int maxY, SDL_Plotter &g) {
    int half = 10, curr = margin;

    //draw X axis marks
    while(curr < maxY){
        line xTick(point(margin-half, curr), point(margin+half, curr));
        xTick.draw(g);
        curr += margin;
    }

    //draw Y axis marks
    curr = (2*margin);
    while(curr < maxX){
        line yTick(point(curr, maxY+half), point(curr-1, maxY-half));
        yTick.draw(g);
        curr += margin;
    }

    g.update();
}

/*
* description: checks if points are in "box" or quadrant to decide whether to draw
* return: bool: if the points are good or not
* precondition: max values passed, plotter obj exists
* postcondition:
*/
bool curve::goodPoints(line a, int margin, SDL_Plotter &g) {
    int x_1, y_1, x_2, y_2;
    bool good = true;

    x_1 = a.getP1().getX();
    y_1 = a.getP1().getY();
    x_2 = a.getP2().getX();
    y_2 = a.getP2().getY();

    //test point 1
    if(x_1 < margin || x_1 >  (max_col-margin) || y_1 < margin || y_1 > (max_row-margin)){
        good = false;
    }

    //test point 2
    if(x_2 < margin || x_2 >  (max_col-margin) || y_2 < margin || y_2 > (max_row-margin)){
        good = false;
    }

    return good;
}


#endif //PROJECT0_CURVE_H
