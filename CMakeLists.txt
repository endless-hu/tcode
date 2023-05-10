cmake_minimum_required(VERSION 3.15)

project(BinPackingFFD)

set(CMAKE_CXX_STANDARD 17)

# Set the build type to Debug or Release
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

# Set the compiler flags, use AddressSanitizer for Debug builds
if(CMAKE_BUILD_TYPE MATCHES Debug)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb -Wall -Wextra -Wpedantic -Werror -fsanitize=address")
else()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Werror")
endif()

# Add all .cc files under src/
file(GLOB_RECURSE SOURCES "src/*.cc")
add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})

# Include the headers under src/headers/**
include_directories("src/headers")
