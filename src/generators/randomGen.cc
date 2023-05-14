#include "randomGen.hh"

#include <random>

RandomGenerator::RandomGenerator(int numItems, int dim) {
  // Seed with a real random value, if available
  std::random_device r;
  // Choose a random real number between 0 and 1
  std::default_random_engine e1(r());
  std::uniform_real_distribution<double> uniform_dist(0, 1);
  std::vector<double> item_raw;
  for (int i = 0; i < numItems; i++) {
    for (int j = 0; j < dim; j++) {
      item_raw.push_back(uniform_dist(e1));
    }
    items_.emplace_back(item_raw);
    item_raw.clear();
  }
}
