#pragma once

#include <string>

#include "bin.hh"
#include "item.hh"

/**
 * Abstract Generator class
 */
class AbstractGenerator {
 public:
  /**
   * Constructor for Generator class
   */
  AbstractGenerator() = default;

  /**
   * Virtual function to generate items
   *
   * @return Vector of items generated
   */
  virtual std::vector<Item> generate() = 0;

  virtual std::string name() = 0;

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

  virtual ~AbstractGenerator() = default;
};