#pragma once

#include "abstractAlloc.hh"

/**
 * @brief First Fit-Item Centric Allocator class
 *
 * This class contains the definition of the First Fit-Item Centric Allocator
 * class.
 */

/**
 * This class adopts Product to sort the items.
 */
class FFDItemCentricProductAllocator : public AbstractAllocator {
 public:
  FFDItemCentricProductAllocator() = default;

  /**
   * @brief Virtual function to allocate items to bins
   *
   * @return Number of bins with items allocated to them
   */
  int allocate(const std::vector<Item>& items) override;

  std::string name() override { return "FFD Item Centric Product"; }
};

/**
 * This class adopts the Sum to sort the items.
 */
class FFDItemCentricSumAllocator : public AbstractAllocator {
 public:
  FFDItemCentricSumAllocator() = default;

  /**
   * @brief Virtual function to allocate items to bins
   *
   * @return Vector of bins with items allocated to them
   */
  int allocate(const std::vector<Item>& items) override;

  std::string name() override { return "FFD Item Centric Sum"; }
};
