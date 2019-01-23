/*
* Author: Grant Gasser
* Assignment Title: project0
* File Description: Color class
* Due Date: 1/28/2019
 */

#ifndef PROJECT0_COLOR_RGB_H
#define PROJECT0_COLOR_RGB_H

class color_rgb {
public:
    color_rgb();
    color_rgb(int r, int g, int b);
    virtual ~color_rgb();
    int getR();
    int getG();
    int getB();

    void setR(int r);
    void setG(int g);
    void setB(int b);

    void operator=(const color_rgb& c);

private:
    int r,g,b;
};

/*
* description: constructor
* return:
* precondition:
* postcondition: sets the rgb values for instantiated obj
*/
color_rgb::color_rgb() {
    r = 255;
    g = 255;
    b = 255;
}

/*
* description: constructor
* return:
* precondition:
* postcondition: sets the rgb values for instantiated obj
*/
color_rgb::color_rgb(int r, int g, int b) {
    this->r = r;
    this->g = g;
    this->b = b;
}

/*
* description: destructor
* return:
* precondition:
* postcondition: sets the rgb values to 0
*/
color_rgb::~color_rgb(){
    r = 0;
    g = 0;
    b = 0;
}

/*
* description: sets r value
* return:
* precondition: color_rgb obj exists
* postcondition: r has a  value
*/
void color_rgb::setR(int r) {
    this->r = r;
}

/*
* description: sets g value
* return:
* precondition: color_rgb obj exists
* postcondition: g has a  value
*/
void color_rgb::setG(int g) {
    this->g = g;
}

/*
* description: sets b value
* return:
* precondition: color_rgb obj exists
* postcondition: b has a  value
*/
void color_rgb::setB(int b) {
    this->b = b;
}

/*
* description: gets b value
* return:
* precondition: color_rgb obj exists
* postcondition: b has a  value
*/
int color_rgb::getB() {
    return b;
}

/*
* description: gets g value
* return:
* precondition: color_rgb obj exists
* postcondition: g has a  value
*/
int color_rgb::getG() {
    return g;
}

/*
* description: gets r value
* return:
* precondition: color_rgb obj exists
* postcondition: r has a  value
*/
int color_rgb::getR() {
    return r;
}

/*
* description: Overloaded assignment operator
* return:
* precondition: color_rgb obj exists
* postcondition: member values copied over
*/
void color_rgb::operator=(const color_rgb& c){
    r = c.r;
    g = c.g;
    b = c.b;
}

#endif //PROJECT0_COLOR_RGB_H
