from distutils.core import setup, Extension
#from cmake_setuptools import CMakeExtension, cmake_build_ext

setup(
  name = 'ExtensionPlayground',
  version = '0.0.1',
  description = 'Package demoing python extension methods',
  packages = ['playground'],
  ext_modules = [
    Extension('ext1', ['ext1.c'])
    #CMakeExtension('playground.ext1')
  ],
  #cmdclass={
  #  'build_ext': cmake_build_ext,
  #}
)
