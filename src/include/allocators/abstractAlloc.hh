#pragma once

#include <chrono>
#include <iostream>
#include <string>

#include "bin.hh"
#include "item.hh"

/**
 * @brief Abstract Allocator class
 *
 * This class contains the definition of the Allocator class.
 */
class AbstractAllocator {
 public:
  AbstractAllocator() = default;

  // Run allocation algorithm and return the number of bins used
  virtual int allocate(const std::vector<Item>& items) = 0;

  // Run allocation algorithm and report relavent information in
  // a human readable format
  void test_and_report(std::vector<Item>& items) {
    auto start = std::chrono::high_resolution_clock::now();
    int numBins = allocate(items);
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << name() << " took "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end -
                                                                       start)
                     .count()
              << " milliseconds to allocate " << items.size() << " items to "
              << numBins << " bins.\n";
  }

  // Reset the allocator
  void reset() { bins_.clear(); }

  // Get the name of the allocator
  virtual std::string name() = 0;

  // Give out the bins
  std::vector<Bin> bins() { return bins_; }

  // Calculate the `a` vector for the items
  // a_i = 1/n * \sum_{j=1}^{n} items[j].dim[i]
  std::vector<double> calculate_a(const std::vector<Item>& items) {
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

  // Show the bins as a string
  std::string to_string() {
    std::string s = "";
    for (auto& bin : bins_) {
      s += bin.to_string() + "\n";
    }
    s += "=== Total bins: " + std::to_string(bins_.size()) + "\n";
    return s;
  }

  virtual ~AbstractAllocator() = default;

 protected:
  std::vector<Bin> bins_;  ///< Vector of bins to be allocated to
};