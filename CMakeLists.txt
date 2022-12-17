cmake_minimum_required(VERSION 3.2)

project(FRONT-INSERTION)
# specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_compile_options(-O3)

# some stuff to check other stuff
set(CMAKE_CXX_CLANG_TIDY)
set(CMAKE_CXX_INCLUDE_WHAT_YOU_USE)

add_executable(main main.cpp)

find_package(benchmark REQUIRED)
target_link_libraries(main benchmark::benchmark)
target_link_libraries(main benchmark::benchmark_main)