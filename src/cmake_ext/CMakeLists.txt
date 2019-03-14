cmake_minimum_required(VERSION 3.10.1)
project(ExtensionPlayground)

find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})

add_library(cmake_ext SHARED MODULE cmake_ext.c)
target_link_libraries(cmake_ext ${PYTHON_LIBRARIES})
set_target_properties(cmake_ext PROPERTIES PREFIX "")
