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
  RandomSplitGenerator(int numItems) : numItems_(numItems) {}

  /**
   * @brief Virtual function to generate items
   *
   * @return Vector of items generated
   */
  std::vector<Item> generate() override;

  std::string name() override { return "Random Split Generator"; }

 private:
  int numItems_;  ///< Number of items to generate
};