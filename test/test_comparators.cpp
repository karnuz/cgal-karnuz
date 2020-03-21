#include <iostream>
#include <cassert>
#include "point.h"
#include "comparators.h"

using namespace std;



bool test_comparePolar(){

  Point p1 = {2.0, 3.0};
  Point p2 = {4.0, -5.0};
  Point p0 = {0.0, 0.0};

  Comparators c;
  c.setComparePolarBase(p0);
  int r = c.comparePolar(p1,p2);
  
  assert(r = -1);
  return true;
}


int main() {
  test_comparePolar();
  return 0;
}
