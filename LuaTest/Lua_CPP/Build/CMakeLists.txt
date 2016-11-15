cmake_minimum_required(VERSION 2.6)

#####################################################################
# Options
#####################################################################
option(MSVC_USE_STATIC_RUNTIME "For MSVC, use static runtime libraries instead of the default dll runtime libraries." ON)
set(DEPENDENCIES_DEFAULT_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/../../lua5_3_3/include )
set(DEPENDENCIES_DEFAULT_LIB_DIR ${CMAKE_SOURCE_DIR}/../../lua5_3_3/lib )

project(LuaCpp)

include_directories(${CMAKE_SOURCE_DIR}/../../lua5_3_3/include)
link_directories(${CMAKE_SOURCE_DIR}/../../lua5_3_3/lib )

aux_source_directory(${CMAKE_SOURCE_DIR}/../src  SRC_LIST)
set(TEST_DIR ${CMAKE_SOURCE_DIR}/../src)
message(STATIC "SRC_LIST:: ${SRC_LIST}")
message(STATIC "TEST_DIR:: ${TEST_DIR}")
message(STATIC "DEPENDENCIES_DEFAULT_INCLUDE_DIR:: ${DEPENDENCIES_DEFAULT_INCLUDE_DIR}")
add_executable(LuaCpp ${SRC_LIST})
target_link_libraries (LuaCpp lualib)  
 



