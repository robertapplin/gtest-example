cmake_minimum_required(VERSION 3.29)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(GTestExample)

find_package(GTest 1.14 REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Create a test library
set(TEST_FILES MyTest.cpp)

add_executable(MyTests ${TEST_FILES})

target_link_libraries(MyTests PRIVATE ${GTEST_BOTH_LIBRARIES})
