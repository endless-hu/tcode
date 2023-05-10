#pragma once

#include "abstractAlloc.hh"

/**
 * @brief First Fit-Bin Centric Allocator class
 * The file contains the definition of the First Fit-Bin Centric Allocator
 * classes.
 */
class FFDBinCentricAllocator : public AbstractAllocator {
 public:
  FFDBinCentricAllocator() = default;

  /**
   * @brief Virtual function to allocate items to bins
   *
   * @return Vector of bins with items allocated to them
   */
  int allocate(const std::vector<Item>& items) override;

 protected:
  // Return true if the item was packed, false no item was packed
  // (a.k.a we have to start a new bin)
  virtual bool pack_largest_item(std::vector<Item>& items, Bin& bin,
                                 const std::vector<double>& vec_a) = 0;
};

/**
 * This class adopts Dot Product to decide which item is the "largest"
 */
class FFDBinCentricDotProductAllocator : public FFDBinCentricAllocator {
 public:
  FFDBinCentricDotProductAllocator() = default;

  std::string name() override { return "FFD-Bin Centric Dot Product"; }

  bool pack_largest_item(std::vector<Item>& items, Bin& bin,
                         const std::vector<double>& vec_a) override;
};

/**
 * This class adopts the Norm to decide which item is the "largest"
 */
class FFDBinCentricNormAllocator : public FFDBinCentricAllocator {
 public:
  FFDBinCentricNormAllocator() = default;

  std::string name() override { return "FFD-Bin Centric Norm"; }

  bool pack_largest_item(std::vector<Item>& items, Bin& bin,
                         const std::vector<double>& vec_a) override;
};
