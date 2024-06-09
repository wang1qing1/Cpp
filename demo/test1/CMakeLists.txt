
cmake_minimum_required(VERSION 2.8)
project(test_sort)

aux_source_directory(./ SRC)

include_directories(${headpath})

set(EXECUTABLE_OUTPUT_PATH ${exeoutpath})

link_directories(${libpath})

link_libraries(sort)

add_executable(test_sort ${SRC})

