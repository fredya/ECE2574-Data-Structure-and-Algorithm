cmake_minimum_required(VERSION 3.5)
project(HW1 CXX)

# Require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# create unit tests 
# (You are also welcome to create your own hw1_main project, but that is not required for this assignment)
# In the following, do NOT list ArrayBag.cpp 
# (To support templates, ArrayBag.cpp is #included by ArrayBag.h)
add_executable(hw1_test catch.hpp ArrayBag.h BagInterface.h hw1_test.cpp)

# unit tests 
enable_testing(unittest hw1_test)

