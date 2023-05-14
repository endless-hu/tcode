#include "simpleGen.hh"

// Case 1, 9 items:
// Optimal solution:
// {(0.1,0.3) (0.4,0.1) (0.1,0.2) (0.3,0) (0.1,0.4)}  {3x(0.3333, 0.1) (0,0.7)}
// p:   0.03     0.04      0.02      0        0.04         0.03333      0
// a_i: (0.1111, 0.1111)
SimpleGenerator1::SimpleGenerator1() {
  items_.emplace_back(std::vector<double>{0.4, 0.1});
  items_.emplace_back(std::vector<double>{0.3333, 0.1});
  items_.emplace_back(std::vector<double>{0, 0.7});
  items_.emplace_back(std::vector<double>{0.1, 0.3});
  items_.emplace_back(std::vector<double>{0.3333, 0.1});
  items_.emplace_back(std::vector<double>{0.1, 0.2});
  items_.emplace_back(std::vector<double>{0.1, 0.4});
  items_.emplace_back(std::vector<double>{0.3333, 0.1});
  items_.emplace_back(std::vector<double>{0.3, 0});
}

// Case 2, 5 items:
// Optimal solution:
// {(0.1, 0.7, 0.7), (0.5, 0.2, 0.1), (0.4, 0.1, 0.3)}  {(0.8, 0.6, 0.4), (0.2,
// 0.4, 0.6)}
// P:   0.049             0.01             0.012               0.192      0.048
// a_i: (0.2, 0.2, 0.2)
SimpleGenerator2::SimpleGenerator2() {
  items_.emplace_back(std::vector<double>{0.5, 0.2, 0.1});
  items_.emplace_back(std::vector<double>{0.1, 0.7, 0.7});
  items_.emplace_back(std::vector<double>{0.8, 0.6, 0.4});
  items_.emplace_back(std::vector<double>{0.4, 0.1, 0.3});
  items_.emplace_back(std::vector<double>{0.2, 0.4, 0.6});
}
