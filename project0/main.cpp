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
#include "SDL_Plotter.h"
#include "color_rgb.h"
#include "point.h"
//#include "line.h"
//#include "curve.h"

/*
#include "point.h"
#include "line.h"
#include "color_rgb.h"
#include "curve.h"
*/

using namespace std;

const int ROW_MAX = 500;
const int COL_MAX = 1000;


int main(int argc, char** argv) {
    SDL_Plotter g(ROW_MAX,COL_MAX);

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

    return 0;
}