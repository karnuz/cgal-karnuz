#include "gtest/gtest.h"
#include <set>

#include "point.h"
#include "convexhull.h"
#include "utils.h"
// p_s = point set

int findMinYXIndex(vector<Point> p_vec);

// compare as per polar angle with reespect to private field p0. If p1 < p2 then it returns -1 else 1
int ConvexHull::polarCompare(const Point &p1, const Point &p2) {
  int o = get_orientation(p0, p1, p2);
  if(o == 0) {
    double d1 = distSq(p0, p1);
    double d2 = distSq(p0, p2);
    return (d2 > d1)? -1:1;
  }
  return o == 1 ? -1:1;
}



// sorts point
void ConvexHull::sortPolar(vector<Point> &p_vec) {
  int min = findMinYXIndex(p_vec);
  Point temp = p_vec[min];
  p_vec[min] = p_vec[0];
  p_vec[0] = temp;
  p0 = p_vec[0];
  sort(p_vec.begin()+1, p_vec.end(), [this](Point x, Point y) { return this->polarCompare(x,y);} );
}


vector<Point> ConvexHull::grahamScan(set<Point> &p_s) {
  assert(p_s.size() >= 3);    
}


// returns the index of point which is least in Y. If more than two points are least in Y, returns the one lesser in X.
int findMinYXIndex(vector<Point> p_vec) {
  assert(p_vec.size() > 0);
  int r = 0;
  int i;
  for (i=1; i < p_vec.size(); i++) {
    bool c1 = p_vec[i].y < p_vec[r].y;
    if(c1) {
	r = i;
    } else {
      bool c2 = p_vec[i].y == p_vec[r].y;
      if(c2) {
	bool c3 = p_vec[i].x < p_vec[r].x;
	if(c3) {
	  r = i;
	}
      }
    }
  }
  return r;
}


//namespace {
//  TEST(FactorialTest, Negative) {
    // This test is named "Negative", and belongs to the "FactorialTest"
    // test case.
//    EXPECT_EQ(-1, -1);
//  }
//}

