// Copyright 2018 Dongha Kang

#ifndef HW01_POINT2_H_
#define HW01_POINT2_H_

#include <iostream>
#include <cmath>
class Point2 {
 private:
      // private holds the float number x and y
      float x, y;

 public:
    // default constructors
    Point2();
    // where m and n are input variable
    Point2(float m, float n);

    // returning the x position
    float PositionX();

    // returning the y position
    float PositionY();

    // float DistanceBetween (float Position1);
    float DistanceBetween(Point2 p);
};

#endif   // HW01_POINT2_H_
