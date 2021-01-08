cmake_minimum_required(VERSION 2.6)
project(cpp_example)

add_executable(cpp_example main.cpp)

add_executable(factorial_example factorial_example.cpp Factorial.cpp)

install(TARGETS cpp_example RUNTIME DESTINATION bin)