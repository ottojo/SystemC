cmake_minimum_required(VERSION 3.18)
project(Exercise02)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS True)

find_package(fmt)
if (NOT FMT_FOUND)
    add_executable(exercise02_5 main.cpp)
    target_link_libraries(exercise02_5 fmt::fmt)
else ()
    message(WARNING "fmtlib not found, skipping exercise 2")
endif ()
