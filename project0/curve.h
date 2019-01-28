//
// Created by gasser on 1/28/2019.
//

#ifndef PROJECT0_CURVE_H
#define PROJECT0_CURVE_H

#include <vector>
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

const int MAX_ROW = 500;
const int MAX_COL = 1000;
const int MARGIN = 50;

curve::curve() {
    sameScale = true;
}

curve::~curve() {
    sameScale = false;
}

void curve::display(Data_t data, ostream &out) {

}

void curve::draw(Data_t data, SDL_Plotter &g) {
    int maxX = 0, maxY = 0, x_1, y_1, x_2, y_2;
    point p1, p2;
    double scale;

    int len = data.size();


    //each iteration is a line/curve
    for(int i = 0; i < len; i++){
        int numPts = data[i].size();
        int maxX_set = 0, maxY_set = 0;


        for(int j = 0; j < numPts; j++){
            //use scale variable to scale or divide the data
            if(sameScale)
                scale = 1;
            else {
                //exp
                if(i == 0){
                    scale = 20;
                }
                //linear
                if (i == 1) {
                    scale = MAX_COL/MAX_ROW;
                }
                //quadratic
                if (i == 2) {
                    scale = MAX_COL/sqrt(MAX_ROW);
                }
                //cubic
                if (i == 3) {
                    scale = MAX_COL/cbrt(MAX_ROW);
                }
                //log
                if(i == 4){
                    scale = MAX_COL/log(MAX_ROW);
                }
            }

            //set the scaled point values
            x_1 = (data[i][j].first*scale) + MARGIN;
            x_2 = (data[i][j+1].first*scale) + MARGIN;
            y_1 = (MAX_ROW - MARGIN - data[i][j].second);
            y_2 = (MAX_ROW - MARGIN - data[i][j+1].second);

            line line(point(x_1, y_1), point(x_2, y_2)); //auto color is black

            //if points within box
            if(goodPoints(line, MARGIN, g))
                line.draw(g);

            line.nextColor();

            //find max points of individual data sets
            if(data[i][j].first > maxX && data[i][j].first < (MAX_COL-MARGIN)){
                maxX_set = data[i][j].first;
            }
            if(data[i][j].second > maxY && data[i][j].second < (MAX_ROW-MARGIN)){
                maxY_set = data[i][j].second;
            }

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
    plotAxis(MARGIN, maxX, maxY, g);
}

void curve::plotAxis(int margin, int maxX, int maxY, SDL_Plotter &g) {
    line yAxis(point(margin,maxY), point(margin-1, margin));
    line xAxis(point(margin,maxY), point(maxX, maxY));

    //draw axes
    xAxis.draw(g);
    yAxis.draw(g);

    g.update();

    plotTickMarks(MARGIN, maxX, maxY, g);
}

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

bool curve::goodPoints(line a, int margin, SDL_Plotter &g) {
    int x_1, y_1, x_2, y_2;
    bool good = true;

    x_1 = a.getP1().getX();
    y_1 = a.getP1().getY();
    x_2 = a.getP2().getX();
    y_2 = a.getP2().getY();

    //test point 1
    if(x_1 < margin || x_1 >  (MAX_COL-margin) || y_1 < margin || y_1 > (MAX_ROW-margin)){
        good = false;
    }

    //test point 2
    if(x_2 < margin || x_2 >  (MAX_COL-margin) || y_2 < margin || y_2 > (MAX_ROW-margin)){
        good = false;
    }

    return good;
}


#endif //PROJECT0_CURVE_H
