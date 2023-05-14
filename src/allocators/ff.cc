#include "ff.hh"

#include "debugger.hh"

int FirstFitAllocator::allocate(const std::vector<Item>& items) {
  for (auto item : items) {
    bool allocated = false;
    for (uint64_t i = 0; i < bins_.size(); ++i) {
      if (bins_[i].fits(item)) {
        bins_[i].add_item(item);
        LOG_INFO("Item %s fits in bin %ld: %s", item.to_string().c_str(), i,
                 bins_[i].to_string().c_str());
        allocated = true;
        break;
      }
    }
    if (!allocated) {
      LOG_INFO("Item %s does not fit in any bin, creating new bin",
               item.to_string().c_str());
      bins_.emplace_back(item.dim());
      bins_.back().add_item(item);
    }
  }
  return bins_.size();
}
