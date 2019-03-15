from setuptools import Extension
from src.cmake_ext.cmake_setuptools import CMakeExtension, setup  # Patched setup function

setup(
  name = 'ext_playground',
  version = '0.0.1',
  description = 'Package demoing python extension methods',
  packages = ['playground'],
  package_dir = {'': 'src'},
  ext_modules = [
    Extension('playground.basic_ext', ['src/basic_ext.c']),
    CMakeExtension('playground.cmake_ext', 'src/cmake_ext'),  # TODO importing this is broken -- seg fault
    CMakeExtension('playground.boost_ext', 'src/boost_ext')
  ]
)

import os, os.path
cwd = os.getcwd()
os.chdir('src/skbuild_ext')
#import src.skbuild_ext.setup as skbuild_ext
os.chdir(cwd)
