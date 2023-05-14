#pragma once

#include "abstractGen.hh"

/**
 * @brief Random Split Generator class
 *
 * This class generates items by randomly splitting unit bins.
 */
class RandomSplitGenerator : public AbstractGenerator {
 public:
  /**
   * @brief Constructor for Random Split Generator class
   *
   * @param numBins Number of optimal bins
   */
  RandomSplitGenerator(int numBins, int dim);

  std::string name() override { return "Random Split Generator"; }

 private:
  // Randomly split 1 into `num` segments
  std::vector<double> generate_segments(int num);
};