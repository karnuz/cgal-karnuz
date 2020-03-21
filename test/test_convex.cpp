#include <iostream>
#include <cassert>
#include "lines.h"
#include "convexhull.h"

using namespace std;


void test_doesIntersect() {

  Point p1 = {0, 0}, p2 = {4, 4}, p3 = {5, 5}, p4 = {8, 8} ;
  Line l1 = {p1, p2}, l2 = {p3, p4};

  assert(doesIntersect(l1, l2) == false);

}


void test_sortPolar() {
  Point p1 = {2,1}, p2 = {3,1}, p3 = {4,2}, p4 = {4,3}, p5 = {2,3};
  ConvexHull c;
  vector<Point> p_vec{p3,p2,p4,p5,p1};
  c.sortPolar(p_vec);
  //assert(false);

  for(int i=0; i < 5; i++) {
    cout << p_vec[i].x << " " << p_vec[i].y << "\n";
  }
  vector<Point> p_vec_exp = {p1,p2,p3,p4,p5};

  assert(p_vec_exp == p_vec);
}


int main() {

  test_doesIntersect();
  test_sortPolar();
}
