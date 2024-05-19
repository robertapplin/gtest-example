cmake_minimum_required(VERSION 3.29)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(BoostExample)

find_package(Python REQUIRED COMPONENTS Development)
if(NOT Python_FOUND)
  message(FATAL_ERROR "Python not found")
endif()

find_package(Boost REQUIRED COMPONENTS python)
if(NOT Boost_FOUND)
  message(FATAL_ERROR "Boost not found")
endif()

# Create a python library from the export files
add_library(my_module SHARED main.cpp)
target_include_directories(my_module PRIVATE ${Boost_INCLUDE_DIRS} ${Python_INCLUDE_DIRS})
target_link_libraries(my_module PRIVATE ${Boost_LIBRARIES} ${Python_LIBRARIES})
set_target_properties(my_module PROPERTIES PREFIX "" SUFFIX ".pyd")
