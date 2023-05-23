#include <chrono>
#include <iostream>

#include "allocators.hh"
#include "generators.hh"
#include "readerwriter.hh"

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <input_file>\n";
    return 1;
  }
  std::vector<Item> items = ReaderWriter::read(std::string(argv[1]));

  // Prepare allocators
  std::vector<AbstractAllocator*> allocators;
  allocators.push_back(new FirstFitAllocator);
  allocators.push_back(new FFDItemCentricProductAllocator);
  allocators.push_back(new FFDItemCentricSumAllocator);
  allocators.push_back(new FFDBinCentricDotProductAllocator);
  allocators.push_back(new FFDBinCentricNormAllocator);

  // Run allocators
  for (auto& allocator : allocators) {
    allocator->test_and_report(items);
  }

  // Clean up
  for (auto& allocator : allocators) {
    delete allocator;
  }

  return 0;
}