project(Exercise04)

find_package(SystemCLanguage REQUIRED)

add_executable(simple_fifo main.cpp Producer.cpp Consumer.cpp)

set_property(TARGET simple_fifo PROPERTY CXX_STANDARD 17)
target_compile_options(simple_fifo PRIVATE -Wall -Wextra -Wpedantic -Werror)
target_link_libraries(simple_fifo SystemC::systemc)
