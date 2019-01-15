#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include "SDL_Plotter.h"
#include "color_rgb.h"

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
    //color_rgb c;

    //cout << c.getR() << endl;
    return 0;
}