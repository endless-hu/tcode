#include <iostream>

#include "randomGen.hh"

int main() {
  RandomGenerator gen(10, 3);
  std::cout << gen.to_string() << std::endl;

  std::cout << "... Testing RandomGeneratorNegRel ..." << std::endl;
  RandomGeneratorNegRel gen_neg_rel(10, 2);
  std::cout << gen_neg_rel.to_string() << std::endl;
  return 0;
}