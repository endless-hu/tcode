#pragma once

#include "abstractGen.hh"

/**
 * @brief Generators for some simple cases. To verify the correctness of the
 * algorithms.
 */
class SimpleGenerator1 : public AbstractGenerator {
 public:
  SimpleGenerator1();

  std::string name() override { return "Simple Generator 1"; }
};

class SimpleGenerator2 : public AbstractGenerator {
 public:
  SimpleGenerator2();

  std::string name() override { return "Simple Generator 2"; }
};

class SimpleGenerator3 : public AbstractGenerator {
 public:
  SimpleGenerator3();

  std::string name() override { return "Simple Generator 3"; }
};