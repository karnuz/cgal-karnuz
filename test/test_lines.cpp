#include <iostream>
#include "lines.h"

using namespace std;

int main() {
  Point p1 = {0, 0}, p2 = {4, 4}, p3 = {0, 4}, p4 = {4, 0} ;
  Line l1 = {p1, p2}, l2 = {p3, p4};

  bool b = doesIntersect(l1, l2);
  if (b==true)         cout << "Yes\n";
  else              cout << "No\n";
  return 0;


  
  
}
