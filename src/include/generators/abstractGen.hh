#pragma once

#include <string>
#include <vector>

#include "bin.hh"
#include "debugger.hh"
#include "item.hh"

/**
 * Abstract Generator class
 */
class AbstractGenerator {
 public:
  /**
   * Constructor for Generator class
   * For its concrete subclasses, they should override this constructor
   * and generate items in the constructor.
   */
  AbstractGenerator() = default;

  virtual std::string name() = 0;

  std::vector<Item>& get_items() { return items_; }

  int get_dimension() { return items_.at(0).dim(); }

  int get_num_items() { return items_.size(); }

  // To output for machine processing
  std::string format_to_string() {
    std::string s = "" + std::to_string(items_[0].dim()) + " " +
                    std::to_string(items_.size()) + "\n";
    for (auto& item : items_) {
      s += item.format_to_string() + "\n";
    }
    return s;
  }

  // For test purpose
  std::string to_string() {
    std::string s = "{\n";
    for (auto& item : items_) {
      s += item.to_string() + "\n";
    }
    s += "}\n";
    return s;
  }

  virtual ~AbstractGenerator() = default;

 protected:
  std::vector<Item> items_;
};