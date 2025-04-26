cmake_minimum_required(VERSION 3.5)

enable_testing()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type")

# Set the project name
project(Benchmarks)

include(FetchContent)

FetchContent_Declare(
  nontype_functional
  GIT_REPOSITORY https://github.com/zhihaoy/nontype_functional
  GIT_TAG        bdb098751ccdba3e03b429064473c70e228a885e # v1.0.2
)
set(BENCHMARK_ENABLE_TESTING off)
# FetchContent_Declare(googletest
#         GIT_REPOSITORY https://github.com/google/googletest.git
#         GIT_TAG v1.10.x)

# FetchContent_Declare(googlebenchmark
#         GIT_REPOSITORY https://github.com/google/benchmark.git
#         GIT_TAG main) # need main for benchmark::benchmark

FetchContent_Declare(googlebenchmark
                     GIT_REPOSITORY https://github.com/google/benchmark
                     GIT_TAG main)
FetchContent_MakeAvailable(googlebenchmark)

FetchContent_MakeAvailable(
        nontype_functional)

# Add the executable
add_executable(Benchmarks main.cpp BasicCCallback.cpp StdFunctionRef.cpp)

# find_package(nontype_functional CONFIG REQUIRED)
target_link_libraries(Benchmarks PRIVATE std23::nontype_functional benchmark::benchmark)

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "output")