#pragma once

#include "abstractGen.hh"

/**
 * @brief Special Case generator
 *
 * This class generates items for the special case described in the theorom 3.12
 * in the paper. Half of the items are (1/6, 1/3) and the other half are (1/3,
 * 1/6).
 */

/**
 * This class generates half (1/6, 1/3) and half (1/3, 1/6)
 */
class SpecialGenerator1 : public AbstractGenerator {
 public:
  /**
   * @brief Constructor for Special Generator class
   *
   * @param numItems Number of items to generate
   */
  SpecialGenerator1(int numItems);

  std::string name() override { return "SpecialGen-2"; }
};

/**
 * This class generates half (1/6, 1/3) and half (1/3, 1/6) in random order
 */
class SpecialGenerator2 : public AbstractGenerator {
 public:
  /**
   * @brief Constructor for Special Generator class
   *
   * @param numItems Number of items to generate
   */
  SpecialGenerator2(int numItems);

  std::string name() override { return "SpecialGen-2"; }
};
