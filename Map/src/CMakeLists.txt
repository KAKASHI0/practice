cmake_minimum_required(VERSION 2.6)

project(MapPractise)


#set(EXECUTABLE_OUTPUT_PATH $ {PROJECT_SOURCE_DIR}/bin)       #//设置可执行文件的生成路径

#include_directories($ {PROJECT_SOURCE_DIR}/src_a ${PROJECT_SOURCE_DIR}/src_so)   //包含库头文件

aux_source_directory(. SRC_LIST )   #// 将当前目录中的源文件名称赋值给变量 DIR_SRCS
#add_executable(main $ {SRC_LIST})   //表示 DIR_SRCS中的源文件需要编译成名为 main的可执行文件

#target_link_libraries (main Testa Testso)   //将库文件链接到生成的目标可执行文件

message(status "This is Binary dir" ${PROJECT_BINARY_DIR})
message(status "This is SOURCES dir" ${PROJECT_SOURCE_DIR})

#set (SRC_LIST main.cpp)

add_executable(MapPractise ${SRC_LIST})