#pragma once

#include "abstractGen.hh"

/**
 * @brief Random Generator class
 *
 * This class contains the definition of the Random Generator class.
 */
class SimpleGenerator1 : public AbstractGenerator {
 public:
  SimpleGenerator1() = default;

  /**
   * @brief Virtual function to generate items
   *
   * @return Vector of items generated
   */
  std::vector<Item> generate() override;
};