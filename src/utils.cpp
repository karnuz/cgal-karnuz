#include "utils.h"
#include <vector>

float min(float a, float b) {
  return (a>b)?b:a;
}

float max(float a, float b) {
  return (a>b)?a:b;
}

template <typename T>
void swap(int i, int j, vector<T> &v) {
  T temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}
