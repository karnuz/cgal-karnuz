#include <iostream>
#include "points.h"

using namespace std;

int main() {
  Point p1 = {0, 0}, p2 = {4, 4}, p3 = {1, 2}; 
  int o = get_orientation(p1, p2, p3); 
  if (o==0)         cout << "Linear\n"; 
  else if (o == 1)  cout << "Clockwise\n"; 
  else              cout << "CounterClockwise\n"; 
  return 0;
}
