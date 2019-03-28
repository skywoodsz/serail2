cmake_minimum_required(VERSION 2.6)
set( CMAKE_BUILD_TYPE "Release" )
set( CMAKE_CXX_FLAGS "-std=c++11 -O3" )
project(serial2)

set(BOOST_ROOT /usr/local/include/boost)
find_package(Boost COMPONENTS system thread regex serialization REQUIRED)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    
    MESSAGE( STATUS "Boost_INCLUDE_DIRS = ${Boost_INCLUDE_DIRS}.")
    MESSAGE( STATUS "Boost_LIBRARIES = ${Boost_LIBRARIES}.")
    MESSAGE( STATUS "Boost_LIB_VERSION = ${Boost_LIB_VERSION}.")
    
    add_executable(serial2 
		main.cpp
		pc2mcu.cpp)
    
    target_link_libraries (serial2 ${Boost_LIBRARIES})
endif()




