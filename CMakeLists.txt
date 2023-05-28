cmake_minimum_required(VERSION 3.15)

project(BinPackingFFD)

set(CMAKE_CXX_STANDARD 17)

# Set the build type to Debug or Release
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

# Set the compiler flags, use AddressSanitizer for Debug builds
if(CMAKE_BUILD_TYPE MATCHES Debug)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb -Wall -Wextra -Wpedantic -fsanitize=address")
  add_definitions(-DLOGGER)
else()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
endif()

# Add all .cc files under src/
file(GLOB SOURCES "src/allocators/*.cc" "src/generators/*.cc")
add_executable(${CMAKE_PROJECT_NAME} ${SOURCES} "src/benchmark.cc")
add_executable(${CMAKE_PROJECT_NAME}_single ${SOURCES} "src/main.cc")
add_executable(${CMAKE_PROJECT_NAME}_case_generator ${SOURCES} "src/gen.cc")
include_directories("src/include")
include_directories("src/include/allocators")
include_directories("src/include/generators")
include_directories("eigen-3.4.0")

# enable ctest
enable_testing()
# Set the output directory for executables in the 'test/' directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test)
# Add the src/ directory to the list of directories to search for include files
include_directories(${PROJECT_SOURCE_DIR}/src)
file(GLOB_RECURSE TEST_SOURCES "test/*.cc")
file(GLOB_RECURSE ALLOC_SRC "src/allocators/*.cc")
file(GLOB GEN_SRC "src/generators/*.cc")
file(GLOB HDR_SRC "src/include/*.hh")
foreach(TEST_SOURCE ${TEST_SOURCES})
  get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)
  add_executable(${TEST_NAME} ${TEST_SOURCE})
  target_sources(${TEST_NAME} PRIVATE
      ${ALLOC_SRC}
      ${GEN_SRC}
      ${HDR_SRC}
  )
  add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endforeach()

# ------------------------------
#   Custom targets
#  `make purge` to remove all generated `*.txt`, `*.png` files
# ------------------------------
add_custom_target(
  purge
  COMMAND rm -rf *.txt *.png
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR})

# ------------------------------
#   Custom targets
#  `make run` to run the following two commands:
#      $ ./BinPackingFFD
#      $ pushd ../
#      $ python3 plot.py
#      $ popd
# ------------------------------
add_custom_target(
  run
  COMMAND ${CMAKE_PROJECT_NAME}
  COMMAND pushd ../
  COMMAND python3 plot.py
  COMMAND popd
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
