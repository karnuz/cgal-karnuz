#ifndef HEADER_FILE
#define HEADER_FILE

#include "points.h"

struct Line {
  Point p1;
  Point p2;
};

bool isPointOnSegment(Point p1, Point p2, Point q);
bool doesIntersect (Line l1, Line l2);

#endif
