#include <iostream>

#include "specialGen.hh"

int main() {
  SpecialGenerator1 gen1(8);
  SpecialGenerator2 gen2(8);

  std::cout << "Generating 8 items of special cases..." << std::endl;
  std::cout << "Generator 1: " << gen1.to_string() << std::endl;
  std::cout << "Generator 2: " << gen2.to_string() << std::endl;
}