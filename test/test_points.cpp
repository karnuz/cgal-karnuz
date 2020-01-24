#include <iostream>
#include <cassert>
#include "points.h"

using namespace std;

int main() {
  Point p1 = {0, 0}, p2 = {4, 4}, p3 = {2, 2}; 
  // 0 == Linear
  // -1 == Clockwise
  // 1 == Counter-clockwise
  assert(get_orientation(p1, p2, p3) == 0);
  return 0;
}
