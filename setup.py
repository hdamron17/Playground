from setuptools import setup, Extension
#from cmake_setuptools import CMakeExtension, cmake_build_ext

setup(
  name = 'ExtensionPlayground',
  version = '0.0.1',
  description = 'Package demoing python extension methods',
  packages = ['playground'],
  package_dir = {'': 'src'},
  ext_modules = [
    Extension('playground.ext1', ['src/playground/ext1.c'])
    #CMakeExtension('playground.ext1')
  ],
  #cmdclass = {
  #  'build_ext': cmake_build_ext,
  #}
)
