cmake_minimum_required(VERSION 3.0)
project(boost_ext)

find_package(PythonInterp ${PY_VERSION} REQUIRED)
find_package(PythonLibs ${PY_VERSION} REQUIRED)
find_package(Boost 1.63 REQUIRED COMPONENTS system python37)

message("==== ${PYTHON_INSTALL_PATH} | ${PYTHON_SITE_DIR}")

include_directories(${PYTHON_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS})

PYTHON_ADD_MODULE(boost_ext src/boost_ext.cpp)
target_link_libraries(boost_ext ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})
