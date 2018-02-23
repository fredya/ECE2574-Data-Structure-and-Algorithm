cmake_minimum_required(VERSION 3.5)
project(HW2 CXX)

# Require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create unit tests 
# In the following, do NOT list Poly.cpp 
# (To support templates, Poly.cpp is #included by Poly.h)
add_executable(hw2_test PolyInterface.h Poly.h Node.h hw2_test.cpp catch.hpp)
# The following will not be graded. It is for your convenience 
#  to experiment with your own main() function in hw2_main.cpp
add_executable(hw2_main PolyInterface.h Poly.h Node.h hw2_main.cpp)

# unit tests 
enable_testing(unittest hw2_test)

