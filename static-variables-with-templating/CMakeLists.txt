cmake_minimum_required(VERSION 3.5)

# Set the project name
project(StaticVariablesWithTemplating)

# Add the executable
add_executable(StaticVariablesWithTemplating main.cpp)

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "output")