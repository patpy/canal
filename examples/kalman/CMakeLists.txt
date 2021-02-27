#CMakeLists.txt File for compiling project
cmake_minimum_required(VERSION 2.8.9)
project(BayesianFilter)
include_directories(/home/patrick/COMP167/CANAL/math)
#include_directories(/home/patrick/COMP167/CANAL/dsp)
#include_directories(/home/patrick/COMP167/CANAL/dsp/misc_fun)
#include_directories(/home/patrick/COMP167/CANAL/dsp/iirFilter)
include_directories(/home/patrick/COMP167/CANAL/statistics)
include_directories(/home/patrick/COMP167/CANAL/data_struct/lists)
include_directories(/home/patrick/COMP167/cpp_utilities)
include_directories(/home/patrick/COMP167/CompSci/eigen)
include_directories(/home/patrick/COMP167/graphics/pyplotcpp)
include_directories(/usr/include/python2.7)

#Using shared library
#set( PROJECT_LINK_LIBS libCANAL.so pyhton2.7)
link_directories(/home/patrick/COMP167/CANAL/build)
link_directories(/usr/include/python2.7)

add_executable(kf rnd_kf_main.cpp)
#target_link_libraries(kf ${PROJECT_LINK_LIBS})
target_link_libraries(kf python2.7)
target_link_libraries(kf libCANAL.so)
