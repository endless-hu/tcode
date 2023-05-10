#pragma once

#include "abstractGen.hh"

/**
 * @brief Special Case generator
 *
 * This class generates items for the special case described in the theorom 3.12
 * in the paper. Half of the items are (1/6, 1/3) and the other half are (1/3,
 * 1/6).
 */

class SpecialGenerator : public AbstractGenerator {
 public:
  /**
   * @brief Constructor for Special Generator class
   *
   * @param numItems Number of items to generate
   */
  SpecialGenerator(int numItems) : numItems_(numItems) {}

  /**
   * @brief Virtual function to generate items
   *
   * @return Vector of items generated
   */
  std::vector<Item> generate() override;

  std::string name() override { return "Special Generator"; }

 private:
  int numItems_;  ///< Number of items to generate
};