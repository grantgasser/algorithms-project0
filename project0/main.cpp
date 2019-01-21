/*
* Author: Grant Gasser
* Assignment Title: project0
* File Description: Driver
* Due Date: 1/28/2019
 */

 #include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include "SDL_Plotter.h"
#include "color_rgb.h"
#include "point.h"
#include "line.h"
#include "curve.h"

using namespace std;

const int ROW_MAX = 500;
const int COL_MAX = 1000;


int main(int argc, char** argv) {
    SDL_Plotter g(ROW_MAX,COL_MAX);

    /*
    //TEST COLOR
    color_rgb c(5, 0 ,0);
    color_rgb foo;

    foo = c;

    cout << foo.getR() << endl;

    //TEST POINT
    point p1(200,200);

    g.Sleep(1000);
    p1.draw(g);

    g.Sleep(2000);

    point p2;
    p2 = p1;

    p2.setX(300);
    p2.setY(300);

    p2.draw(g);

    g.Sleep(2000);

    point p3(p2);

    p3.setX(400);
    p3.setY(400);

    p3.draw(g);

    g.Sleep(2000);

    p3.display(cout);

    */

    //TEST LINE
    //g.Sleep(2000);
    //line s;

    //s.draw(g);
    g.Sleep(1000);

    //TEST CURVE
    curve crv;



    vector<DataSet_t> data;

    DataSet_t set1;
    set1.push_back(make_pair(0,0));
    set1.push_back(make_pair(1,10));
    set1.push_back(make_pair(2,20));
    set1.push_back(make_pair(3,40));
    set1.push_back(make_pair(4,80));
    set1.push_back(make_pair(5,160));
    set1.push_back(make_pair(6,320));
    //set1.push_back(make_pair(7,640));
    //set1.push_back(make_pair(8,1280));
    //set1.push_back(make_pair(9,2560));
    //set1.push_back(make_pair(10,5120));

    data.push_back(set1);

    //Print contents
    /*
    for(int i = 0; i < set1.size(); i++){
        cout << set1[i].second << endl;
    }*/

    DataSet_t set2;
    for(int i = 0; i < 10000; i++){
        set2.push_back(make_pair(i,i));
    }

    //data.push_back(set2);

    crv.draw(data,g);

    g.Sleep(2000);

    return 0;
}