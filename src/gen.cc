#include <fstream>

#include "generators.hh"
/**
 * @brief      Generate test cases.
 * @details    This file is used to generate test cases for the benchmark.
 * The test cases are:
 *   1. RandomSplitGenerator with dimension 2, 3, and 20. We will
 *      generate 5 test cases for each dimension, with optimal number of
 *      bins starting from 1000, and increase by 500 for each test case.
 *   2. RandomGenerator with dimension 2, 3, and 20. We will generate
 *     5 test cases for each dimension, with number of items
 *     starting from 1000, and increase by 2000 for each test case.
 */

#define DIM2 2
#define DIM3 3
#define DIM_HIGH 20

#define NUMITEMS 1000
#define NUMITEMDELTA 2000
#define NUMBINS 1000
#define NUMBINSDELTA 500
#define NUMPOINTS 5

void generate(AbstractGenerator* generator) {
  std::fstream ofile(generator->name() + ".txt", std::ios::app);
  // Write the test cases
  // Write the header: <dimension> <num_items> (RandomSplitGen only)<num_bins>
  ofile << generator->get_dimension() << " " << generator->get_num_items();
  if (RandomSplitGenerator* ran_split_gen =
          dynamic_cast<RandomSplitGenerator*>(generator)) {
    ofile << " " << ran_split_gen->get_num_bins();
  }
  ofile << "\n";

  // Write the items
  for (auto& item : generator->get_items()) {
    for (auto& sz : item.get_sizes()) {
      ofile << sz << " ";
    }
    ofile << "\n";
  }

  ofile.close();
}

int main() {
  std::vector<AbstractGenerator*> split_genrators_dim2;
  std::vector<AbstractGenerator*> split_genrators_dim3;
  std::vector<AbstractGenerator*> split_genrators_dim_high;

  std::vector<AbstractGenerator*> ran_genrators_dim2;
  std::vector<AbstractGenerator*> ran_genrators_dim3;
  std::vector<AbstractGenerator*> ran_genrators_dim_high;

  for (int i = 0; i < NUMPOINTS; i++) {
    split_genrators_dim2.push_back(
        new RandomSplitGenerator(NUMBINS + i * NUMBINSDELTA, DIM2));
    split_genrators_dim3.push_back(
        new RandomSplitGenerator(NUMBINS + i * NUMBINSDELTA, DIM3));
    split_genrators_dim_high.push_back(
        new RandomSplitGenerator(NUMBINS + i * NUMBINSDELTA, DIM_HIGH));

    ran_genrators_dim2.push_back(
        new RandomGenerator(NUMITEMS + i * NUMITEMDELTA, DIM2));
    ran_genrators_dim3.push_back(
        new RandomGenerator(NUMITEMS + i * NUMITEMDELTA, DIM3));
    ran_genrators_dim_high.push_back(
        new RandomGenerator(NUMITEMS + i * NUMITEMDELTA, DIM_HIGH));
  }

  for (auto generator : split_genrators_dim2) {
    generate(generator);
  }
  for (auto generator : split_genrators_dim3) {
    generate(generator);
  }
  for (auto generator : split_genrators_dim_high) {
    generate(generator);
  }

  for (auto generator : ran_genrators_dim2) {
    generate(generator);
  }
  for (auto generator : ran_genrators_dim3) {
    generate(generator);
  }
  for (auto generator : ran_genrators_dim_high) {
    generate(generator);
  }

  // Clean up
  for (auto generator : split_genrators_dim2) {
    delete generator;
  }
  for (auto generator : split_genrators_dim3) {
    delete generator;
  }
  for (auto generator : split_genrators_dim_high) {
    delete generator;
  }

  for (auto generator : ran_genrators_dim2) {
    delete generator;
  }
  for (auto generator : ran_genrators_dim3) {
    delete generator;
  }
  for (auto generator : ran_genrators_dim_high) {
    delete generator;
  }

  return 0;
}
