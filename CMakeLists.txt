cmake_minimum_required(VERSION 3.29)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Zi")

project(BoostExample)

find_package(Python REQUIRED COMPONENTS Development)
if(Python_FOUND)
  include_directories(${Python_INCLUDE_DIRS})
else()
  message(FATAL_ERROR "Python not found")
endif()

find_package(Boost REQUIRED COMPONENTS python)
if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
else()
  message(FATAL_ERROR "Boost not found")
endif()

set(ALL_EXPORT_FILES
    main.cpp
)

# Create a python library from the export files
add_library(my_module SHARED ${ALL_EXPORT_FILES})
target_link_libraries(my_module PUBLIC ${Boost_LIBRARIES} ${Python_LIBRARIES})
set_target_properties(my_module PROPERTIES PREFIX "" SUFFIX ".pyd")
