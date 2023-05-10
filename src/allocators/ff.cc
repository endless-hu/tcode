#include "ff.hh"

int FirstFitAllocator::allocate(std::vector<Item>& items
                                __attribute__((unused))) {
  for (auto& item : items) {
    bool allocated = false;
    for (auto& bin : bins_) {
      if (bin.fits(item)) {
        bin.add_item(item);
        allocated = true;
        break;
      }
    }
    if (!allocated) {
      bins_.emplace_back(item.dim());
      bins_.back().add_item(item);
    }
  }
  return bins_.size();
}
