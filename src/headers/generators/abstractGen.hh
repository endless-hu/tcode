#pragma once

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
};