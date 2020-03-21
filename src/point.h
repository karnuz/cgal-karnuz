#ifndef _POINTS_H_
#define _POINTS_H_

struct Point {
  float x, y;

public:
  bool operator == (Point const &obj) const {
					     bool res;
					     res = (obj.x == x) && (obj.y == y); 
					     return res;
  }

};

int get_orientation(Point p1, Point p2, Point p3);

float distSq(const Point &p1, const Point &p2); 

#endif
