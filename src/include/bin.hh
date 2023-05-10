#pragma once

#include <stdexcept>
#include <string>
#include <vector>

#include "item.hh"

class Bin {
 private:
  std::vector<double> sizes_;  ///< Sizes of the bin in each dimension
  std::vector<Item*> items_;   ///< Items in the bin
 public:
  Bin(int dim) : sizes_(dim, 1), items_() {}

  bool fits(Item& item) const {
    for (int i = 0; i < item.dim(); ++i) {
      if (item.get_size(i) > sizes_[i]) {
        return false;
      }
    }
    return true;
  }
  bool fits(const Item& item) const {
    for (int i = 0; i < item.dim(); ++i) {
      if (item.get_size(i) > sizes_[i]) {
        return false;
      }
    }
    return true;
  }

  void add_item(Item& item) {
    // This line is for debugging purposes, comment it out for performance
    if (!fits(item)) {
      throw std::runtime_error("Item does not fit in bin");
    }

    for (int i = 0; i < item.dim(); ++i) {
      sizes_[i] -= item.get_size(i);
    }
    items_.push_back(&item);
  }

  double dot_product_with(const Item& item, const std::vector<double>& a) {
    double dot_product = 0;
    for (int i = 0; i < item.dim(); ++i) {
      dot_product += item.get_size(i) * sizes_.at(i) * a.at(i);
    }
    return dot_product;
  }

  double norm2(const Item& item, const std::vector<double>& a) {
    double norm2 = 0;
    for (int i = 0; i < item.dim(); i++) {
      norm2 += a.at(i) * (item.get_size(i) - sizes_.at(i)) *
               (item.get_size(i) - sizes_.at(i));
    }
    return norm2;
  }

  std::string to_string() const {
    std::string s = "{\n";
    for (auto& item : items_) {
      s += item->to_string() + "\n";
    }
    s += "}\n Remaining capacity: [";
    for (auto& size : sizes_) {
      s += std::to_string(size) + " ";
    }
    s += "]\n-------\n";
    return s;
  }
};