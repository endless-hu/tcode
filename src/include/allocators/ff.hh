#pragma once

#include "abstractAlloc.hh"

/**
 * @brief First Fit Allocator class
 *
 * This class contains the definition of the First Fit Allocator class.
 */
class FirstFitAllocator : public AbstractAllocator {
 public:
  FirstFitAllocator() = default;

  /**
   * @brief Virtual function to allocate items to bins
   *
   * @return Vector of bins with items allocated to them
   */
  int allocate(const std::vector<Item>& items) override;

  std::string name() override { return "First Fit"; }
};