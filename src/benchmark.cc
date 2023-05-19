#include "allocators.hh"
#include "generators.hh"
#include "readerwriter.hh"

#define DIM2 2
#define DIM3 3
#define DIM_HIGH 20

#define NUMITEMS 1000
#define NUMITEMDELTA 2000
#define NUMBINS 1000
#define NUMBINSDELTA 500
#define NUMPOINTS 5

int main() {
  // Remove old files a.k.a "*.txt"
  if (system("rm *.txt")) {
    std::cerr << "Error removing old files\n";
  }
  // Prepare allocators
  std::vector<AbstractAllocator*> allocators;
  allocators.push_back(new FirstFitAllocator);
  allocators.push_back(new FFDItemCentricProductAllocator);
  allocators.push_back(new FFDItemCentricSumAllocator);
  allocators.push_back(new FFDBinCentricDotProductAllocator);
  allocators.push_back(new FFDBinCentricNormAllocator);

  // Prepare generators
  std::vector<AbstractGenerator*> generators_dim2;
  std::vector<AbstractGenerator*> generators_dim3;
  std::vector<AbstractGenerator*> generators_dim_high;

  std::vector<AbstractGenerator*> ran_gen_dim2;
  std::vector<AbstractGenerator*> ran_gen_dim3;
  std::vector<AbstractGenerator*> ran_gen_dim_high;

  std::vector<AbstractGenerator*> ran_gen_neg_rel_dim2;
  std::vector<AbstractGenerator*> ran_gen_neg_rel_dim3;
  std::vector<AbstractGenerator*> ran_gen_neg_rel_dim_high;

  for (int i = 0; i < NUMPOINTS; i++) {
    generators_dim2.push_back(
        new RandomSplitGenerator(NUMBINS + i * NUMBINSDELTA, DIM2));
    ReaderWriter::write(generators_dim2.back());
    generators_dim3.push_back(
        new RandomSplitGenerator(NUMBINS + i * NUMBINSDELTA, DIM3));
    ReaderWriter::write(generators_dim3.back());
    generators_dim_high.push_back(
        new RandomSplitGenerator(NUMBINS + i * NUMBINSDELTA, DIM_HIGH));
    ReaderWriter::write(generators_dim_high.back());

    ran_gen_dim2.push_back(
        new RandomGenerator(NUMITEMS + i * NUMITEMDELTA, DIM2));
    ReaderWriter::write(ran_gen_dim2.back());
    ran_gen_dim3.push_back(
        new RandomGenerator(NUMITEMS + i * NUMITEMDELTA, DIM3));
    ReaderWriter::write(ran_gen_dim3.back());
    ran_gen_dim_high.push_back(
        new RandomGenerator(NUMITEMS + i * NUMITEMDELTA, DIM_HIGH));
    ReaderWriter::write(ran_gen_dim_high.back());

    ran_gen_neg_rel_dim2.push_back(
        new RandomGeneratorNegRel(NUMITEMS + i * NUMITEMDELTA, DIM2));
    ReaderWriter::write(ran_gen_neg_rel_dim2.back());
    ran_gen_neg_rel_dim3.push_back(
        new RandomGeneratorNegRel(NUMITEMS + i * NUMITEMDELTA, DIM3));
    ReaderWriter::write(ran_gen_neg_rel_dim3.back());
    ran_gen_neg_rel_dim_high.push_back(
        new RandomGeneratorNegRel(NUMITEMS + i * NUMITEMDELTA, DIM_HIGH));
    ReaderWriter::write(ran_gen_neg_rel_dim_high.back());
  }

  std::vector<std::vector<AbstractGenerator*>> generators{
      generators_dim2,      generators_dim3,      generators_dim_high,
      ran_gen_dim2,         ran_gen_dim3,         ran_gen_dim_high,
      ran_gen_neg_rel_dim2, ran_gen_neg_rel_dim3, ran_gen_neg_rel_dim_high};
  std::cout << "Generators prepared\n";
  // Run allocators
  for (auto generator : generators) {
    for (auto gen : generator) {
      std::string file_name = gen->name() + ".txt";
      // Prepare header for each test case
      // Format: <num_items> [<num_bins> | if RandomSplitGenerator]
      std::fstream file(file_name, std::ios::app);
      file << gen->get_items().size();
      if (RandomSplitGenerator* rsg =
              dynamic_cast<RandomSplitGenerator*>(gen)) {
        file << " " << rsg->get_num_bins();
      }
      file << std::endl;
      file.close();

      for (auto allocator : allocators) {
        allocator->test_and_report(gen->get_items(), file_name);
        allocator->reset();
      }
    }
  }

  // Clean up
  for (auto allocator : allocators) {
    delete allocator;
  }
  for (auto generator : generators) {
    for (auto gen : generator) {
      delete gen;
    }
  }
}