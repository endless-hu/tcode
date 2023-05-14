#include "ffdItem.hh"

#include <algorithm>

#include "ff.hh"

int FFDItemCentricProductAllocator::allocate(const std::vector<Item>& items) {
  // we are going to sort the items, so copy them
  std::vector<Item> items_copy(items);
  // sort the items by their product
  std::sort(
      items_copy.begin(), items_copy.end(),
      [](const Item& a, const Item& b) { return a.product() > b.product(); });
#ifdef LOGGER
  LOG_INFO("Sorted items: %s", vector_to_string(items_copy).c_str());
#endif
  // now we can use the First Fit
  FirstFitAllocator ffa;
  int num = ffa.allocate(items_copy);
  bins_ = ffa.bins();
  return num;
}

int FFDItemCentricSumAllocator::allocate(const std::vector<Item>& items) {
  // we are going to sort the items, so copy them
  std::vector<Item> items_copy(items);
  std::vector<double> vec_a = calculate_a(items_copy);
  // sort the items by their sum
  std::sort(items_copy.begin(), items_copy.end(),
            [&vec_a](Item& a, Item& b) { return a.sum(vec_a) > b.sum(vec_a); });
#ifdef LOGGER
  LOG_INFO("Sorted items: %s", vector_to_string(items_copy).c_str());
#endif
  // now we can use the First Fit
  FirstFitAllocator ffa;
  int num = ffa.allocate(items_copy);
  bins_ = ffa.bins();
  return num;
}
