#include <fstream>

#include "generators.hh"
#include "readerwriter.hh"
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

int main() {
  for (int i = 0; i < NUMPOINTS; i++) {
    RandomSplitGenerator split_gen_2(NUMBINS + i * NUMBINSDELTA, DIM2);
    ReaderWriter::write(&split_gen_2);
    RandomSplitGenerator split_gen_3(NUMBINS + i * NUMBINSDELTA, DIM3);
    ReaderWriter::write(&split_gen_3);
    RandomSplitGenerator split_gen_high(NUMBINS + i * NUMBINSDELTA, DIM_HIGH);
    ReaderWriter::write(&split_gen_high);

    RandomGenerator gen_2(NUMITEMS + i * NUMITEMDELTA, DIM2);
    ReaderWriter::write(&gen_2);
    RandomGenerator gen_3(NUMITEMS + i * NUMITEMDELTA, DIM3);
    ReaderWriter::write(&gen_3);
    RandomGenerator gen_high(NUMITEMS + i * NUMITEMDELTA, DIM_HIGH);
    ReaderWriter::write(&gen_high);
  }

  return 0;
}
