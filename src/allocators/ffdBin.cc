#include "ffdBin.hh"

int FFDBinCentricDotProductAllocator::allocate(const std::vector<Item>& items
                                               __attribute__((unused))) {
  // we are going to remove item from items, so copy them
  std::vector<Item> items_copy(items);

  while (!items_copy.empty()) {
    Bin bin(items.at(0).dim());
    while (!pack_largest_item(items_copy, bin))
      ;
    bins_.push_back(bin);
  }
  return bins_.size();
}

bool FFDBinCentricDotProductAllocator::pack_largest_item(
    std::vector<Item>& items, Bin& bin) {}

int FFDBinCentricNormAllocator::allocate(const std::vector<Item>& items
                                         __attribute__((unused))) {
  return 0;
}
