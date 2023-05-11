#include "specialGen.hh"

#include <algorithm>

SpecialGenerator1::SpecialGenerator1(int numItems) {
  std::vector<double> item_type1{0.33333, 0.16666};
  std::vector<double> item_type2{0.16666, 0.33333};
  for (int i = 0; i < numItems; i++) {
    if (i < numItems / 2) {
      items_.emplace_back(item_type1);
    } else {
      items_.emplace_back(item_type2);
    }
  }
}

SpecialGenerator2::SpecialGenerator2(int numItems) {
  std::vector<double> item_type1{0.33333, 0.16666};
  std::vector<double> item_type2{0.16666, 0.13333};
  for (int i = 0; i < numItems; i++) {
    if (i < numItems / 2) {
      items_.emplace_back(item_type1);
    } else {
      items_.emplace_back(item_type2);
    }
  }
  std::random_shuffle(items_.begin(), items_.end());
}
