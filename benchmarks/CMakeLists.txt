cmake_minimum_required(VERSION 3.5)

enable_testing()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type")

# Set optimization level to -O0
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")

# Set the project name
project(Benchmarks)

include(FetchContent)

FetchContent_Declare(
  nontype_functional
  GIT_REPOSITORY https://github.com/zhihaoy/nontype_functional
  GIT_TAG        bdb098751ccdba3e03b429064473c70e228a885e # v1.0.2
)

set(BENCHMARK_ENABLE_TESTING off)

FetchContent_Declare(googlebenchmark
                     GIT_REPOSITORY https://github.com/google/benchmark
                     GIT_TAG main)

FetchContent_MakeAvailable(
    googlebenchmark
    nontype_functional)

# Define all benchmark source files
set(BENCHMARK_SOURCES_THAT_WORK_ON_ALL_COMPILERS
  main.cpp
  BasicCCallback.cpp
  CallbackInterfaceUsingInheritance.cpp
  CallingMemberThroughStandardCFunction.cpp
  StaticVariablesWithTemplating.cpp
  StdFunctionWithLambdas.cpp 
  StdFunctionWithBind.cpp
  TemplatingTheMemberFunctionAndInstance.cpp)


# Add the executable
add_executable(Benchmarks ${BENCHMARK_SOURCES_THAT_WORK_ON_ALL_COMPILERS} StdFunctionRef.cpp)
target_link_libraries(Benchmarks PRIVATE std23::nontype_functional benchmark::benchmark)
set_target_properties(Benchmarks PROPERTIES OUTPUT_NAME "output")

# Create non-optimized version of the executable
add_executable(Benchmarks_NoOpt ${BENCHMARK_SOURCES_THAT_WORK_ON_ALL_COMPILERS})
target_compile_options(Benchmarks_NoOpt PRIVATE "-O0")
target_link_libraries(Benchmarks_NoOpt PRIVATE std23::nontype_functional benchmark::benchmark)
set_target_properties(Benchmarks_NoOpt PROPERTIES OUTPUT_NAME "output_no_opt")


