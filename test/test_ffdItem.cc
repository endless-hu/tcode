#include <iostream>

#include "ffdItem.hh"
#include "simpleGen.hh"

int main() {
  FFDItemCentricProductAllocator allocator;
  FFDItemCentricSumAllocator sum_alloc;
  SimpleGenerator1 gen;

  std::cout << "... Test Product Allocator\n";
  allocator.test_and_report(gen.get_items());
  std::cout << allocator.to_string() << "... Test AvgSum Allocator\n";
  sum_alloc.test_and_report(gen.get_items());
  std::cout << sum_alloc.to_string();
}