cmake_minimum_required(VERSION 3.5)

# Set the project name
project(UsingStdFunctionRef)

include(FetchContent)

FetchContent_Declare(
  nontype_functional
  GIT_REPOSITORY https://github.com/zhihaoy/nontype_functional
  GIT_TAG        bdb098751ccdba3e03b429064473c70e228a885e # v1.0.2
)

FetchContent_MakeAvailable(nontype_functional)

# Add the executable
add_executable(UsingStdFunctionRef main.cpp)

# find_package(nontype_functional CONFIG REQUIRED)
target_link_libraries(UsingStdFunctionRef PRIVATE std23::nontype_functional)

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "output")