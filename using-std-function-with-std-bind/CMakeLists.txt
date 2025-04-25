cmake_minimum_required(VERSION 3.5)

# Set the project name
project(UsingStdFunctionWithStdBind)

# Add the executable
add_executable(UsingStdFunctionWithStdBind main.cpp)

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "output")