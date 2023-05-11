#include <iostream>

#include "ff.hh"
#include "specialGen.hh"

int main() {
  SpecialGenerator1 gen1(8);
  FirstFitAllocator ffa;
  ffa.test_and_report(gen1.get_items());
  std::cout << ffa.to_string() << std::endl;
}