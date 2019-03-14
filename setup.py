from distutils.core import setup, Extension
from cmake_setuptools import CMakeExtension, cmake_build_ext

setup(
  name = 'ExtensionPlayground',
  version = '0.0.1',
  description = 'Package demoing python extension methods',
  ext_modules = [
    #Extension('ext1', sources = ['ext1.c']),
    CMakeExtension('ext1')
  ],
  cmdclass={
    'build_ext': cmake_build_ext,
  }
)
