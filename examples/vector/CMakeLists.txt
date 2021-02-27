#CMakeLists.txt File for compiling project
cmake_minimum_required(VERSION 2.8.9)
project(Vector_As_Math_Object)
include_directories(/home/patrick/COMP167/CANAL/math)
include_directories(/home/patrick/COMP167/cpp_utilities)

add_executable(vec main_math_vec.cpp)
target_link_libraries(vec libCANAL.so)


