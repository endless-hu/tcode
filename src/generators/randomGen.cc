#include "randomGen.hh"

#include <iostream>
#include <random>

#include "Eigen/Dense"

RandomGenerator::RandomGenerator(int numItems, int dim) {
  // Seed with a real random value, if available
  std::random_device r;
  // Choose a random real number between 0 and 1
  std::default_random_engine e1(r());
  std::uniform_real_distribution<double> uniform_dist(0, 1);
  std::vector<double> item_raw;
  for (int i = 0; i < numItems; i++) {
    for (int j = 0; j < dim; j++) {
      item_raw.push_back(uniform_dist(e1));
    }
    items_.emplace_back(item_raw);
    item_raw.clear();
  }
}

RandomGeneratorNegRel::RandomGeneratorNegRel(int numItems, int dim) {
  const double rho = -0.7;
  // Seed with a real random value, if available
  std::random_device r;
  std::default_random_engine e1(r());
  std::uniform_real_distribution<double> normal_dists(0, 1);

  double max_coeff = 0;
  double min_coeff = 100;
  std::vector<Eigen::VectorXd> items_in_eigen_vector;
  for (int i = 0; i < numItems; i++) {
    // Generate `dim` uncorrelated numbers
    Eigen::VectorXd x(dim);
    for (int j = 0; j < dim; j++) {
      x(j) = normal_dists(e1);
    }
    // Create the correlation matrix
    Eigen::MatrixXd cov(dim, dim);
    for (int j = 0; j < dim; j++) {
      for (int k = 0; k < dim; k++) {
        if (j == k) {
          cov(j, k) = 1;
        } else {
          cov(j, k) = rho;
        }
      }
    }
    // Apply the correlation matrix to the uncorrelated numbers
    Eigen::MatrixXd L = cov.llt().matrixL();
    Eigen::VectorXd y = L * x;

    // Find the max and min coefficients
    max_coeff = std::max(max_coeff, y.maxCoeff());
    min_coeff = std::min(min_coeff, y.minCoeff());

    items_in_eigen_vector.push_back(y);
  }

  // Normalize the coefficients
  for (auto &item : items_in_eigen_vector) {
    item = (item.array() - min_coeff) / (max_coeff - min_coeff);
    std::vector<double> item_raw;
    for (int i = 0; i < dim; i++) {
      item_raw.push_back(item(i));
    }
    // Random shuffle is necessary, because the above normalization
    // process will always make the first dimension the largest.
    std::random_shuffle(item_raw.begin(), item_raw.end());
    items_.emplace_back(item_raw);
  }
}
