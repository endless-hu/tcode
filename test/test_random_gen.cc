#include <iostream>

#include "randomGen.hh"

int main() {
  RandomGenerator gen(10, 3);
  std::cout << gen.to_string() << std::endl;
}