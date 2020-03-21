#include <iostream>
#include "point.h"
#include "comparators.h"


// returns -1 if p1 < p2 else +1
bool Comparators::comparePolar(Point &p1, Point &p2) {
  int o1 = get_orientation(ComparePolarBase,p1,p2);
  if (o1 == 0) {
    float d1 = distSq(ComparePolarBase,p1);
    float d2 = distSq(ComparePolarBase,p2);
    return d1<d2? -1:1;
  } else {
    // o1 > 0 implies counter clockwise
    return o1 > 0 ? -1:1;
  }
}
