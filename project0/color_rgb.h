//
// Created by gasser on 1/15/2019.
//

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

#endif //PROJECT0_COLOR_RGB_H
