############################################################
# lua library
############################################################
cmake_minimum_required(VERSION 2.6)

PROJECT(lualib)

#ADD_SUBDIRECTORY(src lib)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)


AUX_SOURCE_DIRECTORY(./src SRC_LIST)

ADD_LIBRARY(lualib STATIC ${SRC_LIST})

 


