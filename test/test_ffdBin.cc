#include <iostream>

#include "ffdBin.hh"
#include "simpleGen.hh"
#include "specialGen.hh"

int main() {
  FFDBinCentricDotProductAllocator dot_prod_alloc;
  FFDBinCentricNormAllocator norm2alloc;

  SimpleGenerator1 gen1;

  std::cout << "... Test DotProduct Allocator\n";
  dot_prod_alloc.test_and_report(gen1.get_items());
  std::cout << dot_prod_alloc.to_string() << "... Test norm2 Allocator\n";
  norm2alloc.test_and_report(gen1.get_items());
}