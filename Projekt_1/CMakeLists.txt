cmake_minimum_required(VERSION 3.10)
project(data_structures)

add_library(data_structures_lib INTERFACE)
target_include_directories(data_structures_lib INTERFACE include/)

add_executable(test_data_structures
  src/test_data_structures.cpp)

target_link_libraries(test_data_structures data_structures_lib)

add_executable(data_structures
        src/main.cpp)

target_link_libraries(data_structures data_structures_lib)

add_executable(time_test
	src/time_test.cpp)

target_link_libraries(time_test data_structures_lib)
