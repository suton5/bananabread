cmake_minimum_required(VERSION 3.0)
project(cnn)

include(ExternalProject)

set(EXTERNAL_INSTALL_LOCATION ${CMAKE_BINARY_DIR}/external)
set(INSTALL_DEPENDENCIES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/external-build)

ExternalProject_Add( Eigen3
 	URL "http://bitbucket.org/eigen/eigen/get/3.3.7.tar.bz2"
	PREFIX "${PROJECT_BINARY_DIR}/deps/eigen3"
    CMAKE_ARGS "-DCMAKE_INSTALL_PREFIX=${PROJECT_BINARY_DIR}/deps"
    			"-DCMAKE_C_COMPILER=${CMAKE_C_COMPILER}"
    			"-DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}"
    UPDATE_DISCONNECTED 1
)

set(EIGEN3_INCLUDE_DIR deps/include/Eigen3)

include_directories(${EIGEN3_INCLUDE_DIR})

add_executable(main main.cpp)
add_dependencies(main Eigen3)
target_link_libraries(main)
