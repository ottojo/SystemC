project(Exercise04)

set(CMAKE_FIND_DEBUG_MODE true)
set(CMAKE_VERBOSE_MAKEFILE true)

find_package(SystemCLanguage REQUIRED)

message(WARNING "${SystemCLanguage_FOUND}")
message(WARNING "${SystemCLanguage_INCLUDE_DIRS}")
message(WARNING "${SystemCLanguage_INCLUDES}")
message(WARNING "${SystemCLanguage_LIBRARIES}")
message(WARNING "${SystemCLanguage_LIBS}")
message(WARNING "${SystemCLanguage_DEFINITIONS}")


add_executable(simple_fifo main.cpp Producer.cpp Consumer.cpp)

set_property(TARGET simple_fifo PROPERTY CXX_STANDARD 17)
target_compile_options(simple_fifo PRIVATE -Wall -Wextra -Wpedantic -Werror)
target_link_libraries(simple_fifo SystemC::systemc)
