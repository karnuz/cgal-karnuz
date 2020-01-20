#include "points.h"
#include "lines.h"
#include "utils.h"

using namespace std;

bool isPointOnSegment(Point p1, Point p2, Point q) {
  float minx, maxx, miny, maxy;
  minx = min(p1.x, p2.x);
  maxx = max(p1.x, p2.x);
  miny = min(p1.y, p2.y);
  maxy = max(p1.y, p2.y);

  if (q.x <= maxx && q.x >= minx && q.y <= maxy && q.y >= miny) {
    return true;
  } else {
    return false;
  }
}


bool doesintersect(Line l1, Line l2) {
  Point p1, p2, q1, q2;

  int o1, o2, o3, o4;

  // non collinear case
  o1 = get_orientation(p1, p2, q1);
  o2 = get_orientation(p1, p2, q2);
  o3 = get_orientation(q1, q2, p1);
  o3 = get_orientation(q1, q2, p2);

  if(o1 != o2 && o3 != o4) {
    return true;
  }

  //collinear case
  bool b1, b2;

  b1 = isPointOnSegment(q1, q2, p1);
  b2 = isPointOnSegment(q1, q2, p2);

  if (b1 || b2 ) {
    return true;
  }

  return false;
  
}
