cmake_minimum_required(VERSION 3.10.1)
project(ExtensionPlayground)

find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})

add_library(ext1 SHARED playground/ext1.c)
target_link_libraries(ext1 ${PYTHON_LIBRARIES})
