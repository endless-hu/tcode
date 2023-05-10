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
class FFDBinCentricDotProductAllocator : public AbstractAllocator {
 public:
  FFDBinCentricDotProductAllocator() = default;

  /**
   * @brief Virtual function to allocate items to bins
   *
   * @return Vector of bins with items allocated to them
   */
  int allocate(const std::vector<Item>& items) override;

  std::string name() override { return "FFD-Bin Centric Dot Product"; }

 private:
  // Return true if the item was packed, false no item was packed
  // (a.k.a we have to start a new bin)
  bool pack_largest_item(std::vector<Item>& items, Bin& bin);
};

/**
 * This class adopts the Norm to decide which item is the "largest"
 */
class FFDBinCentricNormAllocator : public AbstractAllocator {
 public:
  FFDBinCentricNormAllocator() = default;

  /**
   * @brief Virtual function to allocate items to bins
   *
   * @return Vector of bins with items allocated to them
   */
  int allocate(const std::vector<Item>& items) override;

  std::string name() override { return "FFD-Bin Centric Norm"; }
};
