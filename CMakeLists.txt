cmake_minimum_required(VERSION 3.10.1)
project(ExtensionPlayground)

find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})

add_library(ext1cmake MODULE src/playground/ext1.c)
target_link_libraries(ext1cmake ${PYTHON_LIBRARIES})
add_compile_definitions(CMAKE)
set_target_properties(ext1cmake PROPERTIES PREFIX "${PYTHON_LIBRARY_PREFIX}" SUFFIX "${PYTHON_LIBRARY_SUFFIX}")
