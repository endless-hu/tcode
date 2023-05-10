#include <chrono>
#include <iostream>

#include "allocators.hh"
#include "generators.hh"

std::vector<Item> input_data(int d, int n) {
  std::vector<double> szs;
  szs.reserve(d);
  double sz;
  std::vector<Item> items;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < d; j++) {
      std::cin >> sz;
      szs.push_back(sz);
    }
    items.emplace_back(szs);
    szs.clear();
  }
  return items;
}

int main() {
  int n, d;
  std::cout << "Enter `#dimension #items`: ";
  std::cin >> d >> n;
  std::vector<Item> items = input_data(d, n);

  // Prepare allocators
  std::vector<AbstractAllocator*> allocators;
  allocators.push_back(new FirstFitAllocator);
  allocators.push_back(new FFDItemCentricProductAllocator);
  allocators.push_back(new FFDItemCentricSumAllocator);
  allocators.push_back(new FFDBinCentricDotProductAllocator);
  allocators.push_back(new FFDBinCentricNormAllocator);

  // Run allocators
  for (auto& allocator : allocators) {
    allocator->test_and_report(items);
  }

  // Clean up
  for (auto& allocator : allocators) {
    delete allocator;
  }

  return 0;
}