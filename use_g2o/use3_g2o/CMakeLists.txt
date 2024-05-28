cmake_minimum_required(VERSION 3.20)
project(use3_g2o)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS "-std=c++11 -O3")

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

# g2o
find_package(g2o REQUIRED)
include_directories(${G2O_INCLUDE_DIRS})

# add_executable(demo demo.cpp)
# target_link_libraries(demo01 ${G2O_CORE_LIBRARY} ${G2O_STUFF_LIBRARY})
# target_link_libraries(demo g2o_core g2o_stuff)

add_executable(demo_modefied demo_modefied.cpp)
target_link_libraries(demo_modefied 
g2o_core 
g2o_stuff 
# g2o_solver_csparse
# g2o_solver_cholmod 
# g2o_solver_pcg
# g2o_solver_dense
)
