cmake_minimum_required(VERSION 3.6)
project(seedcup201611)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp calculator.cpp calculator.hpp grammarAnalyst.cpp grammarAnalyst.hpp iteratorManager.hpp iteratorManager.cpp memoryStack.hpp memoryStack.cpp token.hpp wordAnalyst.hpp wordAnalyst.cpp util.cpp util.hpp)
add_executable(seedcup201611 ${SOURCE_FILES})