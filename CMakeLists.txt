cmake_minimum_required(VERSION 3.16)

project(sqpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_library(stack SHARED ${CMAKE_SOURCE_DIR}/src/stack.cpp)

target_include_directories(stack PRIVATE ${CMAKE_SOURCE_DIR}/include)

add_executable(main main.cpp)

target_link_libraries(main PRIVATE stack)

target_include_directories(main PRIVATE ${CMAKE_SOURCE_DIR}/include)
