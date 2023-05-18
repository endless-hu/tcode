/**
 * @file item.hh
 * @brief Header for Item class
 *
 * This file contains the definition of the Item class.
 */

#pragma once

#include <string>
#include <vector>

class Item {
 private:
  std::vector<double> sizes_;  ///< Sizes of the item in each dimension
  double product_;
  double sum_;

 public:
  /**
   * @brief Constructor for Item class
   *
   * @param dim Dimension of the item
   * @param sizes Vector of sizes of the item in each dimension
   */
  explicit Item(std::vector<double> sizes)
      : sizes_(sizes), product_(1), sum_(0) {
    for (auto& size : sizes_) {
      product_ *= size;
    }
  }

  /**
   * @brief Getter for the dimension of the item
   *
   * @return Dimension of the item
   */
  int dim() const { return sizes_.size(); }

  /**
   * @brief Getter for the size of the item
   *
   * @return vector reference to the size of the item
   */
  const std::vector<double>& get_sizes() const { return sizes_; }

  /**
   * @brief Getter for the size of the item in a particular dimension
   *
   * @param i Dimension of the item
   * @return Size of the item in the dimension i
   */
  double get_size(int i) const { return sizes_.at(i); }

  std::string format_to_string() const {
    std::string s = "";
    for (auto& size : sizes_) {
      s += std::to_string(size) + " ";
    }
    return s;
  }

  std::string to_string() const {
    std::string s = "[";
    for (auto& size : sizes_) {
      s += std::to_string(size) + " ";
    }
    s += "]";
    return s;
  }

  double product() const { return product_; }

  double sum(const std::vector<double>& a) {
    if (!sum_) {  // if sum_ not calculated yet
      for (int i = 0; i < dim(); i++) {
        sum_ += a[i] * sizes_[i];
      }
    }
    return sum_;
  }

  bool operator==(const Item& other) const {
    if (dim() != other.dim()) {
      return false;
    }
    // Since we use double, we should allow some error
    double EPS = 1e-4;
    for (int i = 0; i < dim(); i++) {
      if (std::abs(sizes_[i] - other.sizes_[i]) > EPS) {
        return false;
      }
    }
    return true;
  }
};
