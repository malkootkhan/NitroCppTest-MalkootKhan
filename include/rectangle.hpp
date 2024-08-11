#ifndef __RECTANGLE__HPP
#define __RECTANGLE_HPP
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "json.hpp"

/*enum for expected error handling: friendly name*/
enum class ErrorCode {
    INVALID_ARGS = 1,
    FILE_OPEN_FAILED,
    SUCCESS
};

/*This hold a point in space*/
class Point {
private:
    int32_t x_cord;
    int32_t y_cord;
public:
    void setPoint(int32_t x, int32_t y)
    {
	x_cord = x;
	y_cord = y;
    }
 int32_t getXcord() const { return x_cord; }
 int32_t getYcord() const { return y_cord; }

};

/**rectangle class*/
class Rectangle {
private:
    uint32_t width;
    uint32_t height;
    Point uLeft_point;		/*p(Xmax, Ymin)*/
    Point uRight_point;		/*p(Xmin, Ymin)*/
    Point lLeft_point;		/*p(Xmax,Ymax)*/
    Point lRight_point;		/*p(Xmin, Ymax)*/

public:
    uint32_t getHeight() const { return height; }
    uint32_t getWidth() const { return width; }
    void setWidth(uint32_t W) { width = W;  }
    void setHeight(uint32_t H) { height = H; }
    Point getULeft_point() const { return uLeft_point; }
    Point getURight_point() const { return uRight_point; }
    Point getLLeft_point() const { return lLeft_point; }
    Point getLRight_point() const { return lRight_point; }

    void setRecData(int32_t X, int32_t Y, uint32_t W, uint32_t H) 
    {
        this->uLeft_point.setPoint(X, Y);
	this->uRight_point.setPoint(X + W, Y);
	this->lLeft_point.setPoint(X, Y - H);
	this->lRight_point.setPoint(X + W, Y - H);
        this->width = W;
        this->height = H;
    }

    friend bool operator<(const Rectangle& obj1, const Rectangle& obj2);
    friend bool operator&(const Rectangle& obj1, const Rectangle& obj2);
    friend Rectangle getShadedRec(const Rectangle& rec1, const Rectangle& rec2);
};

/*Holds the object of shaded rectangles and its relevant other rectangle numbers*/
struct IntersectionPairs
{
	int32_t first_rec;
	int32_t sec_rec;
	Rectangle newrec;
};


#endif
