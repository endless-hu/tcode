#include "ffdBin.hh"

#include <algorithm>

int FFDBinCentricAllocator::allocate(const std::vector<Item>& items
                                     __attribute__((unused))) {
  // we are going to remove item from items, so copy them
  std::vector<Item> items_copy(items);

  std::vector<double> vec_a = calculate_a(items);
  while (!items_copy.empty()) {
    Bin bin(items.at(0).dim());
    while (!pack_largest_item(items_copy, bin, vec_a))
      ;
    bins_.push_back(bin);
  }
  return bins_.size();
}

bool FFDBinCentricDotProductAllocator::pack_largest_item(
    std::vector<Item>& items, Bin& bin, const std::vector<double>& vec_a) {
  // == find the largest item that can fit in the bin
  // First we find the first item that fits the bin
  auto largest_item_it = items.begin();
  for (; largest_item_it != items.end(); largest_item_it++) {
    if (bin.fits(*largest_item_it)) break;
  }
  if (largest_item_it == items.end()) {  // No items can fit the bin
    return false;
  }
  // Find the largest item
  for (auto it = ++largest_item_it; it != items.end(); it++) {
    if (bin.fits(*it) && bin.dot_product_with(*it, vec_a) >
                             bin.dot_product_with(*largest_item_it, vec_a)) {
      largest_item_it = it;
    }
  }
  // pack the item
  bin.add_item(*largest_item_it);
  // remove the item from the list
  items.erase(largest_item_it);
  return true;
}

bool FFDBinCentricNormAllocator::pack_largest_item(
    std::vector<Item>& items, Bin& bin, const std::vector<double>& vec_a) {
  // == find the largest item that can fit in the bin
  // First we find the first item that fits the bin
  auto largest_item_it = items.begin();
  for (; largest_item_it != items.end(); largest_item_it++) {
    if (bin.fits(*largest_item_it)) break;
  }
  if (largest_item_it == items.end()) {  // No items can fit the bin
    return false;
  }
  // Find the largest item
  for (auto it = ++largest_item_it; it != items.end(); it++) {
    if (bin.fits(*it) &&
        bin.norm2(*it, vec_a) > bin.norm2(*largest_item_it, vec_a)) {
      largest_item_it = it;
    }
  }
  // pack the item
  bin.add_item(*largest_item_it);
  // remove the item from the list
  items.erase(largest_item_it);
  return true;
}