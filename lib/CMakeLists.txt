cmake_minimum_required(VERSION 2.8)

project(Util)
set(Util_VERSION_MAJOR 0)
set(Util_VERSION_MINOR 1)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} $ENV{CXXFLAGS} -O0 -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} $ENV{CXXFLAGS} -O3")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src LIB_SRCS)
add_library(util SHARED ${LIB_SRCS})
