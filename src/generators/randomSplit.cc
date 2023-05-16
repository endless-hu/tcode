#include "randomSplit.hh"

#include <algorithm>
#include <random>

RandomSplitGenerator::RandomSplitGenerator(int numBins, int dim) {
  num_bins_ = numBins;
  // Seed with a real random value, if available
  std::random_device r;
  // Choose a random real number between 0 and 1
  std::default_random_engine e1(r());
  std::uniform_real_distribution<double> uniform_dist(0, 1);
  // split a bin into 1~7 items
  std::uniform_int_distribution<int> gen_num_items(1, 7);

  // a column is an item, the whole array represents a bin
  std::vector<std::vector<double>> item_raw_array;
  for (int i = 0; i < numBins; i++) {
    // Split the bin into `gen_num_items(e1)` items
    int num_items = gen_num_items(e1);
    for (int j = 0; j < dim; j++) {
      item_raw_array.emplace_back(generate_segments(num_items));
    }

    std::vector<double> raw_item(dim);
    for (uint64_t i = 0; i < item_raw_array.at(0).size(); i++) {
      for (int d = 0; d < dim; d++) {
        raw_item.at(d) = item_raw_array.at(d).at(i);
      }
      items_.emplace_back(raw_item);
    }
    item_raw_array.clear();
  }
  std::random_shuffle(items_.begin(), items_.end());
}

std::vector<double> RandomSplitGenerator::generate_segments(int num) {
  std::vector<double> break_points(num + 1, 0);
  std::vector<double> segments;
  // Seed with a real random value, if available
  std::random_device r;
  // Choose `num-1` real number as break points between 0 and 1
  std::default_random_engine e1(r());
  std::uniform_real_distribution<double> uniform_dist(0, 1);
  for (int i = 1; i < num; i++) {
    break_points.at(i) = uniform_dist(e1);
  }
  break_points.at(num) = 1;
  std::sort(break_points.begin(), break_points.end());

  for (int i = 0; i < num; i++) {
    segments.push_back(break_points.at(i + 1) - break_points.at(i));
  }
  std::random_shuffle(segments.begin(), segments.end());
  return segments;
}
