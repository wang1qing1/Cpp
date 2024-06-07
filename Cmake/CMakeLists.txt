cmake_minimum_required(VERSION 2.8)
project(test_Cmake)


#搜索文件 aux_source_directory(<dir> name)
#搜索指定目录下的源文件 存储到指定的变量下
#dir 自定义目录
#dir ${PROJCT_SOURCE_DIR} cmake命令下跟的路径
# aux_source_directory(${PROJECT_SOURCE_DIR} filecpp)

#搜索文件 file(GLOB/GLOB_RECURSE 变量名 要搜索的文件路径/文件类型)
#GLOB :将指定目录下搜索到的满足条件的所有文件名生成一个列表,并将其存储到变量中
#GLOB_RECURSE :递归搜索指定目录,将搜索到的满足条件的文件名生成一个列表,并将其存储到变量中
# file(GLOB filecpp ./*.cc ./*.cpp) CMAKE_CURRENT_SOURCE_DIR CMakeLists.txt的目录
file(GLOB filecpp ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

#头文件路径指定
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

#源文件变量
# set(filecpp add.cpp sub.cpp main.cc)
add_executable(app ${filecpp})

#指定c++标准
#执行cmake [CMakelists.txt路径] -DCMAKE_CXX_STANDARD=11
set(DCMAKE_CXX_STANDARD 11)

#指定可执行程序输出路径
set(exe_path /home/wq/24_06_06/out)
set(EXECUTABLE_OUTPUT_PATH ${exe_path})


