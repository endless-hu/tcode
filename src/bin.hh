#pragma once

#include <vector>

class Bin {
 private:
  std::vector<double> sizes_;  ///< Sizes of the bin in each dimension
 public:
  Bin(int dim) : sizes_(dim, 1) {}
};