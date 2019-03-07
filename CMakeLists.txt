########################################
# Configuration
########################################
cmake_minimum_required(VERSION 3.0)
project(proi-project-2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -Wextra -Weffc++ -pedantic")

########################################
# Project files
########################################
set(HEADER_FILES
    include/bitmatrix.hpp
)

set(SOURCE_FILES
    src/bitmatrix.cpp
)

include_directories(include)

add_executable(main src/main.cpp ${SOURCE_FILES})

########################################
# Testing
########################################
enable_testing()

add_library(doctest INTERFACE)
target_include_directories(doctest INTERFACE thirdparty/doctest/include)

add_library(test_main OBJECT test/test_main.cpp ${SOURCE_FILES})
target_link_libraries(test_main doctest)

macro(add_unit_test testname)
    add_executable(${testname} test/${testname}.cpp $<TARGET_OBJECTS:test_main>)
    target_link_libraries(${testname} doctest)
    add_test(NAME ${testname} COMMAND ${testname})
endmacro(add_unit_test)

add_unit_test(test_1)
