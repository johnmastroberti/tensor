#include <iostream>
#include <algorithm>
#include <numeric>
#include "tensor.hpp"

int main() {
  Tensor<int, 3> x;

  Tensor<int, 3> y({1,2,3});

  std::iota(y.begin(), y.end(), 0);

  std::cout << y << std::endl;

  return 0;
}
