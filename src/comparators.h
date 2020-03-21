#include <iostream>
#include "point.h"

class Comparators {

public:

  Point ComparePolarBase;

  void setComparePolarBase(const Point &p) {ComparePolarBase = p;}
  bool comparePolar(Point &p1, Point &p2);

};
