
// Copyright 2018 Dongha Kang

#include <iostream>
#include <cmath>
#include "HW/HW01/point2.h"

//default constructors
Point2::Point2() {
  x = 0.0;
  y = 0.0;
}

Point2::Point2(float m, float n) {
x = m;
y = n;
}

// returning the x position
float Point2::PositionX() {
  return x;
}

// returning the y position
float Point2::PositionY() {
  return y;
}

// float DistanceBetween (float Position1);
float Point2::DistanceBetween(Point2 p) {
  float x2 = p.PositionX();
  float y2 = p.PositionY();
// return x2;
  return sqrt(pow((x2 - x), 2.0) + pow((y2 - y), 2.0));
}
