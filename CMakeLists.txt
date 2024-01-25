cmake_minimum_required(VERSION 3.4...3.18)
project(cmake_example)

find_package(Python COMPONENTS Interpreter Development.Module REQUIRED)

get_cmake_property(_variableNames VARIABLES)
list (SORT _variableNames)
foreach (_variableName ${_variableNames})
    message(STATUS "${_variableName}=${${_variableName}}")
endforeach()

if(NOT Python_FOUND)
  message(WARNING "Unable to find any python libraries")
  return()
else()
  message(STATUS "Found python libraries: ${Python_LIBRARIES} @@@")
endif()

add_library (cmake_example SHARED main.cpp)

include_directories ("${Python_INCLUDE_DIRS}")

set_target_properties (cmake_example PROPERTIES PREFIX "")
set_target_properties (cmake_example PROPERTIES OUTPUT_NAME "cmake_example")
set_target_properties (cmake_example PROPERTIES SUFFIX ".so")
set_target_properties (cmake_example PROPERTIES DEBUG_POSTFIX "")

