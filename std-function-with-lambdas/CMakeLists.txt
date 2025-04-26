cmake_minimum_required(VERSION 3.5)

# Set the project name
project(UsingStdFunctionWithLambdas)

# Add the executable
add_executable(UsingStdFunctionWithLambdas main.cpp)

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "output")