#include <iostream>

#include "randomSplit.hh"

int main() {
  RandomSplitGenerator gen1(5, 2);
  std::cout << gen1.to_string() << std::endl;
}
