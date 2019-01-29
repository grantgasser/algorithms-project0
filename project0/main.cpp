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
    point p(50,50);
    line s;
    curve crv;
    color_rgb c;
    char key;

    vector<DataSet_t> data;

    DataSet_t set1;
    set1.push_back(make_pair(0,0));
    set1.push_back(make_pair(1,10));
    set1.push_back(make_pair(2,20));
    set1.push_back(make_pair(3,40));
    set1.push_back(make_pair(4,80));
    set1.push_back(make_pair(5,160));
    set1.push_back(make_pair(6,320));
    set1.push_back(make_pair(7,640));
    set1.push_back(make_pair(8,1280));
    set1.push_back(make_pair(9,2560));
    set1.push_back(make_pair(10,5120));


    DataSet_t set2;
    for(int i = 0; i < 10000; i++){
        set2.push_back(make_pair(i,i));
    }

    DataSet_t set3;
    for(int i = 0; i < 10000; i++){
        set3.push_back(make_pair(i,(i*i)));
    }

    DataSet_t set4;
    for(int i = 0; i < 1000; i++){
        set4.push_back(make_pair(i,(static_cast<long double>(i)*i*i)));
    }

    DataSet_t set5;
    for(int i = 1; i < 10000000; i+=1000){
        set5.push_back(make_pair(i,log(i)));
    }

    data.push_back(set1);
    data.push_back(set2);
    data.push_back(set3);
    data.push_back(set4);
    data.push_back(set5);

    crv.setSameScale(true);
    crv.draw(data,g);

    while(!g.getQuit()){
        if(g.kbhit()){
            switch(g.getKey()){
                case 'S':
                    crv.setSameScale(!crv.getSameScale());
                    g.clear();
                    crv.draw(data,g);
                    break;
            }
        }
        g.update();
    }

    return 0;
}