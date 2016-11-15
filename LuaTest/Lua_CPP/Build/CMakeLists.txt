cmake_minimum_required(VERSION 2.6)

#####################################################################
# Options
#####################################################################
option(MSVC_USE_STATIC_RUNTIME "For MSVC, use static runtime libraries instead of the default dll runtime libraries." ON)
set(DEPENDENCIES_DEFAULT_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/../../lua5_3_3/include CACHE PATH "The default include dir for 3rd-party dependencies")
set(DEPENDENCIES_DEFAULT_LIB_DIR ${CMAKE_SOURCE_DIR}/../../lua5_3_3/lib CACHE PATH "The default lib dir for 3rd-party dependencies")

#####################################################################
# Project start
#####################################################################
get_filename_component(SOLUTION_NAME ${CMAKE_SOURCE_DIR} NAME)
project(${SOLUTION_NAME})

aux_source_directory(. SRC_LIST)

add_executable(${SOLUTION_NAME} ${SRC_LIST})
#target_link_libraries (${SOLUTION_NAME} lualib)  
 



