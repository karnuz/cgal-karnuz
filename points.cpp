#include <iostream>
#include "points.h"

using namespace std;

// returns 0 if points are collinear, 1 if counter-clockwise, -1 if clockwise
int get_orientation(Point p1, Point p2, Point p3) {
  float val;
  val = (p3.y - p2.y)*(p2.x - p1.x) - (p2.y - p1.y)*(p3.x - p2.x);
  if (val > 0) {
    return 1; // counter clockwise
  } else if (val < 0) {
    return -1; // clockwise
  } else {
    return 0; // collinear
  }
  
}
