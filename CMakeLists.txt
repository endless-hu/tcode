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

include_directories("src/include")
include_directories("src/include/allocators")
include_directories("src/include/generators")
# # Add the current source directory to the include directories
# include_directories(${CMAKE_CURRENT_SOURCE_DIR})
# # Add all subdirectories containing header files to the include directories
# file(GLOB_RECURSE HEADER_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/*.hh")
# foreach(DIR ${HEADER_DIRS})
#     get_filename_component(INCLUDE_DIR ${DIR} DIRECTORY)
#     include_directories(${INCLUDE_DIR})
# endforeach()
