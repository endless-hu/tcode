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

  // Get the number of bins
  int get_num_bins() { return num_bins_; }

  std::string name() override {
    return "RandomSplitGenerator-" + std::to_string(items_.begin()->dim());
  }

 private:
  int num_bins_;  // Number of optimal bins
  // Randomly split 1 into `num` segments
  std::vector<double> generate_segments(int num);
};