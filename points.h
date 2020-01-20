#ifndef _POINTS_H_
#define _POINTS_H_

struct Point {
  float x, y;
};

int get_orientation(Point p1, Point p2, Point p3);

#endif
