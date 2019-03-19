########################################
# Configuration
########################################
cmake_minimum_required(VERSION 3.0)
project(bit-matrix)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -Wextra -Weffc++ -pedantic")

########################################
# Project files
########################################
set(HEADER_FILES
    include/bitmatrix.hpp
)

set(SOURCE_FILES
)

include_directories(include)

add_executable(main src/main.cpp) 

########################################
# Testing
########################################
enable_testing()

add_library(test_main OBJECT test/test_main.cpp)
target_include_directories(test_main PUBLIC thirdparty/doctest/include)

macro(add_unit_test testname)
    add_executable(${testname} test/${testname}.cpp $<TARGET_OBJECTS:test_main>)
    target_include_directories(${testname} PUBLIC thirdparty/doctest/include)
    add_test(NAME ${testname} COMMAND ${testname})
endmacro(add_unit_test)

add_unit_test(test_1)
add_unit_test(test_2)
add_unit_test(test_3)
add_unit_test(test_4)
add_unit_test(test_5)
add_unit_test(test_6)
add_unit_test(test_7)
add_unit_test(test_8)
add_unit_test(test_9)
add_unit_test(test_10)
