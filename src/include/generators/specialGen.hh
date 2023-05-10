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
  SpecialGenerator1(int numItems) : numItems_(numItems) {}

  /**
   * @brief Virtual function to generate items
   *
   * @return Vector of items generated
   */
  std::vector<Item> generate() override;

  std::string name() override { return "Special Generator 1"; }

 private:
  int numItems_;  ///< Number of items to generate
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
  SpecialGenerator2(int numItems) : numItems_(numItems) {}

  /**
   * @brief Virtual function to generate items
   *
   * @return Vector of items generated
   */
  std::vector<Item> generate() override;

  std::string name() override { return "Special Generator 1"; }

  // For test purpose
  std::string to_string() {
    std::string s = "{\n";
    std::vector<Item> items = generate();
    for (auto& item : items) {
      s += item.to_string() + "\n";
    }
    s += "}\n";
    return s;
  }

 private:
  int numItems_;  ///< Number of items to generate
};
