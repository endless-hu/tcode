#pragma once

#include "abstractAlloc.hh"

/**
 * @brief First Fit-Bin Centric Allocator class
 * The file contains the definition of the First Fit-Bin Centric Allocator
 * classes.
 */

/**
 * This class adopts Dot Product to decide which item is the "largest"
 */
class FirstFitBinCentricDotProductAllocator : public AbstractAllocator {
 public:
  FirstFitBinCentricDotProductAllocator() = default;

  /**
   * @brief Virtual function to allocate items to bins
   *
   * @return Vector of bins with items allocated to them
   */
  int allocate(std::vector<Item>& items) override;
};

/**
 * This class adopts the Norm to decide which item is the "largest"
 */
class FirstFitBinCentricNormAllocator : public AbstractAllocator {
 public:
  FirstFitBinCentricNormAllocator() = default;

  /**
   * @brief Virtual function to allocate items to bins
   *
   * @return Vector of bins with items allocated to them
   */
  int allocate(std::vector<Item>& items) override;
};
