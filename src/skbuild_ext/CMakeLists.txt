cmake_minimum_required(VERSION 3.11.0)
project(skbuild_playground)
find_package(PythonExtensions REQUIRED)

add_library(skbuild_ext MODULE src/skbuild_ext.c)
python_extension_module(skbuild_ext)
install(TARGETS skbuild_ext LIBRARY DESTINATION src)
