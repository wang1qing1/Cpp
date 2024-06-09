cmake_minimum_required(VERSION 2.8)
project(testcmake)

# 头文件路径
set(headpath ${CMAKE_CURRENT_SOURCE_DIR}/include)

#动静态库生成路径
set(libpath ${CMAKE_CURRENT_SOURCE_DIR}/lib)

#可执行程序输出路径
set(exeoutpath ${CMAKE_CURRENT_SOURCE_DIR}/out)

add_subdirectory(mutil)
add_subdirectory(sort)
add_subdirectory(test1)
add_subdirectory(test2)

