#ifndef _CONVEXHULL_H_
#define _CONVEXHULL_H_

#include <vector>
#include <set>

using namespace std;

#include "point.h"


class ConvexHull {
 private:
  vector<Point> p_vec;
  Point p0;

  
 public:
  vector<Point> grahamScan(set<Point> &p_set);

  void sortPolar(vector<Point> &p_vec);

  
 private:
  int polarCompare(const Point &p1, const Point &p2);
};


#endif
