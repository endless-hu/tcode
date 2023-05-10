#pragma once

#include <chrono>
#include <iostream>
#include <string>

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
   * @brief Function to evaluate the allocator
   *
   * @param items Vector of items to be allocated
   */
  void test_and_report(std::vector<Item>& items) {
    auto start = std::chrono::high_resolution_clock::now();
    int numBins = allocate(items);
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << name() << " took "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end -
                                                                       start)
                     .count()
              << " milliseconds to allocate " << items.size() << " items to "
              << numBins << " bins.\n";
  }

  /**
   * @brief Virtual function to allocate items to bins
   *
   * @return Vector of bins with items allocated to them
   */
  virtual int allocate(std::vector<Item>& items) = 0;

  virtual std::string name() = 0;

  virtual ~AbstractAllocator() = default;

 protected:
  std::vector<Bin> bins_;  ///< Vector of bins to be allocated to
};