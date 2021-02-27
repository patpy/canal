#CMakeLists.txt File for compiling project
cmake_minimum_required(VERSION 2.8.9)
project(Matrix_As_Math_Object)
include_directories(/home/patrick/COMP167/CANAL)
include_directories(/home/patrick/COMP167/CANAL/math) 
include_directories(/home/patrick/COMP167/CANAL/cpp_utilities)
include_directories(/home/patrick/COMP167/CANAL/eigen)
include_directories(/home/patrick/COMP167/CANAL/vec_ops)
include_directories(/home/patrick/COMP167/CANAL/data_struct/lists)
add_executable(mamo main_matrix.cpp)

