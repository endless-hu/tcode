/**
 * @file item.hh
 * @brief Header for Item class
 *
 * This file contains the definition of the Item class.
 */

#pragma once

#include <vector>

class Item {
 private:
  std::vector<double> sizes_;  ///< Sizes of the item in each dimension
 public:
  /**
   * @brief Constructor for Item class
   *
   * @param dim Dimension of the item
   * @param sizes Vector of sizes of the item in each dimension
   */
  Item(std::vector<double> sizes) : sizes_(sizes) {}

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
  const std::vector<double>& sizes() const { return sizes_; }
};
