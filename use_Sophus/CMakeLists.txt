cmake_minimum_required(VERSION 3.20)
project(useSophus)

set(CMAKE_CXX_FLAGS "-std=c++11 -O3")

find_package(Sophus REQUIRED)

include_directories("/usr/local/include/Eigen")
include_directories(${Sophus_INCLUDE_DIRS})

add_executable(demo01 demo01.cpp)
add_executable(demo02 demo02.cc)

target_link_libraries(demo01 ${Sophus_LIBS} fmt)
target_link_libraries(demo02 ${Sophus_LIBS} fmt)

