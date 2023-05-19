#include "generators.hh"
#include "readerwriter.hh"

#define DIM 3
#define NUMITEMS 100
#define NUMBINS 100

int main() {
  RandomGenerator ran_gen_2(NUMITEMS, DIM);
  RandomSplitGenerator ran_split_gen_2(NUMBINS, DIM);

  std::cout << "... Testing Write RandomGenerator ...\n";
  ReaderWriter::write(&ran_gen_2);
  std::cout << "Read back RandomGenerator.txt\n";
  int dim = 0, num_bins = 0;
  auto items_read_back =
      ReaderWriter::read(ran_gen_2.name() + "-case.txt", &dim, &num_bins);
  if (dim != DIM) {
    std::cerr << "Error: Dimension read back = " << dim << " is not correct";
    std::abort();
  }
  if (num_bins != 0) {
    std::cerr << "Error: Number of bins read back = " << num_bins
              << " is not correct";
    std::abort();
  }
  if (items_read_back != ran_gen_2.get_items()) {
    std::cerr << "Error: Items read back is not correct, read_back[0]="
              << items_read_back.back().to_string()
              << ", size of read_back=" << items_read_back.size()
              << ", ran_gen_2.get_items()="
              << ran_gen_2.get_items().back().to_string()
              << ", size of ran_gen_2.get_items()="
              << ran_gen_2.get_items().size() << "\n";
    std::abort();
  }
  std::cout << "=== Passed RandomGenerator ReadWrite Test ===\n";

  std::cout << "... Testing Write RandomSplitGenerator ...\n";
  ReaderWriter::write(&ran_split_gen_2);
  std::cout << "Read back RandomSplitGenerator.txt\n";
  dim = 0, num_bins = 0;
  auto items_read_back_2 =
      ReaderWriter::read(ran_split_gen_2.name() + "-case.txt", &dim, &num_bins);
  if (dim != DIM) {
    std::cerr << "Error: Dimension read back = " << dim << " is not correct";
    std::abort();
  }
  if (num_bins != NUMBINS) {
    std::cerr << "Error: Number of bins read back = " << num_bins
              << " is not correct";
    std::abort();
  }
  if (items_read_back_2 != ran_split_gen_2.get_items()) {
    std::cerr << "Error: Items read back is not correct";
    std::abort();
  }
  std::cout << "=== Passed RandomSplitGenerator ReadWrite Test ===\n";

  return 0;
}
