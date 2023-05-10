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
   * @param numItems Number of items to generate
   */
  RandomSplitGenerator(int numItems, int dim);

  std::string name() override { return "Random Split Generator"; }
};