#include "specialGen.hh"

#include <algorithm>

std::vector<Item> SpecialGenerator1::generate() {
  std::vector<Item> items;
  std::vector<double> item_type1{0.33333, 0.16666};
  std::vector<double> item_type2{0.16666, 0.13333};
  for (int i = 0; i < numItems_; i++) {
    if (i < numItems_ / 2) {
      items.emplace_back(item_type1);
    } else {
      items.emplace_back(item_type2);
    }
  }
  return items;
}

std::vector<Item> SpecialGenerator2::generate() {
  std::vector<Item> items;
  std::vector<double> item_type1{0.33333, 0.16666};
  std::vector<double> item_type2{0.16666, 0.13333};
  for (int i = 0; i < numItems_; i++) {
    if (i < numItems_ / 2) {
      items.emplace_back(item_type1);
    } else {
      items.emplace_back(item_type2);
    }
  }
  std::random_shuffle(items.begin(), items.end());
  return items;
}
