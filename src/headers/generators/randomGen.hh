#pragma once

#include "abstractGen.hh"

/**
 * @brief Random Generator class
 *
 * This class contains the definition of the Random Generator class.
 */
class RandomGenerator : public AbstractGenerator {
 public:
  /**
   * @brief Constructor for Random Generator class
   *
   * @param numItems Number of items to generate
   * @param binCapacity Capacity of bins to be generated
   */
  RandomGenerator(int numItems);

  /**
   * @brief Virtual function to generate items
   *
   * @return Vector of items generated
   */
  std::vector<Item> generate() override;

 private:
  int numItems_;  ///< Number of items to generate
};