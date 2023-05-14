#include <iostream>

#include "simpleGen.hh"

int main() {
  SimpleGenerator1 gen1;
  SimpleGenerator2 gen2;

  std::cout << "... Test simple generator 1:\n";
  std::cout << gen1.to_string() << std::endl;
  std::cout << "... Test simple generator 2:\n";
  std::cout << gen2.to_string() << std::endl;
}