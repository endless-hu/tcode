#pragma once

#include "bin.hh"
#include "item.hh"

/**
 * @brief Abstract Allocator class
 *
 * This class contains the definition of the Allocator class.
 */
class AbstractAllocator {
 public:
  /**
   * @brief Constructor for Allocator class
   */
  AbstractAllocator() = default;

  /**
   * @brief Virtual function to allocate items to bins
   *
   * @return Vector of bins with items allocated to them
   */
  virtual int allocate(std::vector<Item>& items) = 0;

 protected:
  std::vector<Bin> bins_;  ///< Vector of bins to be allocated to
};