#include "allocators.hh"
#include "generators.hh"

#define DIM2 2
#define DIM3 3
#define DIM_HIGH 20

#define NUMITEMS 100
#define NUMITEMSBIG 1000
#define NUMBINS 40
#define NUMBINSBIG 1000

int main() {
  // Prepare allocators
  std::vector<AbstractAllocator*> allocators;
  allocators.push_back(new FirstFitAllocator);
  allocators.push_back(new FFDItemCentricProductAllocator);
  allocators.push_back(new FFDItemCentricSumAllocator);
  allocators.push_back(new FFDBinCentricDotProductAllocator);
  allocators.push_back(new FFDBinCentricNormAllocator);

  // Prepare generators
  std::vector<AbstractGenerator*> generators;
  generators.push_back(new RandomGenerator(NUMITEMS, DIM2));
  generators.push_back(new RandomGenerator(NUMITEMS, DIM3));
  generators.push_back(new RandomGenerator(NUMITEMSBIG, DIM2));
  generators.push_back(new RandomGenerator(NUMITEMSBIG, DIM_HIGH));

  generators.push_back(new RandomSplitGenerator(NUMBINS, DIM2));
  generators.push_back(new RandomSplitGenerator(NUMBINS, DIM_HIGH));
  generators.push_back(new RandomSplitGenerator(NUMBINSBIG, DIM2));
  generators.push_back(new RandomSplitGenerator(NUMBINSBIG, DIM_HIGH));

  // Run allocators
  for (auto allocator : allocators) {
    for (auto generator : generators) {
      allocator->test_and_report(generator->get_items());
      if (RandomSplitGenerator* split_gen =
              dynamic_cast<RandomSplitGenerator*>(generator);
          split_gen != nullptr) {
        std::cout << "..." << std::endl;
      }
      allocator->reset();
    }
  }

  // Clean up
  for (auto& allocator : allocators) {
    delete allocator;
  }
  for (auto& generator : generators) {
    delete generator;
  }
}