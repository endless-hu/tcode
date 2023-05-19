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
   * @param dim Dimension of the items to generate
   */
  RandomGenerator(int numItems, int dim);

  std::string name() override {
    return "RandomGenerator-" + std::to_string(items_.at(0).dim());
  }
};

/**
 * This class will generate items with negative relations
 * on each dimension.
 */
class RandomGeneratorNegRel : public AbstractGenerator {
 public:
  /**
   * @brief Constructor for Random Generator class
   *
   * @param numItems Number of items to generate
   * @param dim Dimension of the items to generate
   */
  RandomGeneratorNegRel(int numItems, int dim);

  std::string name() override {
    return "RandomGeneratorNegRel-" + std::to_string(items_.at(0).dim());
  }
};