#include <iostream>

#include "item.hh"

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
    items.emplace_back(d, szs);
    szs.clear();
  }
}

int main() {
  int n, d;
  std::cout << "Enter `#dimension #items`: ";
  std::cin >> d >> n;
  std::vector<Item> items = input_data(d, n);
}