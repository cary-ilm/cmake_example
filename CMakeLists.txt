cmake_minimum_required(VERSION 3.4...3.18)
project(cmake_example)

find_package(Python COMPONENTS Development REQUIRED)
if(NOT TARGET Python::Python)
  message(WARNING "Unable to find any python libraries")
  return()
else()
  message(STATUS "Found python libraries: ${Python_LIBRARIES}")
endif()

add_library (cmake_example SHARED main.cpp)

include_directories ("${Python_INCLUDE_DIRS}")

set_target_properties (cmake_example PROPERTIES PREFIX "")
set_target_properties (cmake_example PROPERTIES OUTPUT_NAME "cmake_example")
set_target_properties (cmake_example PROPERTIES SUFFIX ".so")
set_target_properties (cmake_example PROPERTIES DEBUG_POSTFIX "")

#add_subdirectory(pybind11)
#pybind11_add_module(cmake_example src/main.cpp)

# EXAMPLE_VERSION_INFO is defined by setup.py and passed into the C++ code as a
# define (VERSION_INFO) here.
#target_compile_definitions(cmake_example
#                           PRIVATE VERSION_INFO=${EXAMPLE_VERSION_INFO})
