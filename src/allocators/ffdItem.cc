#include "ffdItem.hh"

#include <algorithm>

#include "ff.hh"

int FFDItemCentricProductAllocator::allocate(const std::vector<Item>& items
                                             __attribute__((unused))) {
  // we are going to sort the items, so copy them
  std::vector<Item> items_copy(items);
  // sort the items by their product
  std::sort(
      items_copy.begin(), items_copy.end(),
      [](const Item& a, const Item& b) { return a.product() > b.product(); });
  // now we can use the First Fit
  FirstFitAllocator ffa;
  int num = ffa.allocate(items_copy);
  bins_ = ffa.bins();
  return num;
}

int FFDItemCentricSumAllocator::allocate(const std::vector<Item>& items
                                         __attribute__((unused))) {
  // we are going to sort the items, so copy them
  std::vector<Item> items_copy(items);
  std::vector<double> vec_a = calculate_a(items_copy);
  // sort the items by their sum
  std::sort(items_copy.begin(), items_copy.end(),
            [&vec_a](Item& a, Item& b) { return a.sum(vec_a) > b.sum(vec_a); });
  // now we can use the First Fit
  FirstFitAllocator ffa;
  int num = ffa.allocate(items_copy);
  bins_ = ffa.bins();
  return num;
}

/**
 * @brief Calculate the a vector for the items
 *
 * a_i = 1/n * \sum_{j=1}^{n} items[j].dim[i]
 */
std::vector<double> FFDItemCentricSumAllocator::calculate_a(
    const std::vector<Item>& items) {
  std::vector<double> a(items[0].dim(), 0);
  for (auto& item : items) {
    for (int i = 0; i < item.dim(); i++) {
      a[i] += item.get_size(i);
    }
  }
  for (auto& a_i : a) {
    a_i /= items.size();
  }
  return a;
}