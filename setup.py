from setuptools import Extension
from cmake_setuptools import CMakeExtension, setup  # Patched setup function

setup(
  name = 'ExtensionPlayground',
  version = '0.0.1',
  description = 'Package demoing python extension methods',
  packages = ['playground'],
  package_dir = {'': 'src'},
  ext_modules = [
    Extension('playground.basic_ext', ['src/playground/basic_ext.c']),
    CMakeExtension('playground.cmake_ext')  # TODO importing this is broken -- seg fault
  ]
)
