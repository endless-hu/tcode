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
class FirstFitItemCentricProductAllocator : public AbstractAllocator {
 public:
  FirstFitItemCentricProductAllocator() = default;

  /**
   * @brief Virtual function to allocate items to bins
   *
   * @return Vector of bins with items allocated to them
   */
  int allocate(std::vector<Item>& items) override;
};

/**
 * This class adopts the Sum to sort the items.
 */
class FirstFitItemCentricSumAllocator : public AbstractAllocator {
 public:
  FirstFitItemCentricSumAllocator() = default;

  /**
   * @brief Virtual function to allocate items to bins
   *
   * @return Vector of bins with items allocated to them
   */
  int allocate(std::vector<Item>& items) override;
};
