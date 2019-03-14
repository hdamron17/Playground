# From https://stackoverflow.com/a/48015772

import os
import pathlib

from setuptools import Extension
from setuptools.command.build_ext import build_ext as build_ext_orig

class CMakeExtension(Extension):
    def __init__(self, name):
        # don't invoke the original build_ext for this special extension
        super().__init__(name, [])

class cmake_build_ext(build_ext_orig):
    def run(self):
        for ext in self.extensions:
            self.build_cmake(ext)
        super().run()

    def build_cmake(self, ext):
        if not isinstance(ext, CMakeExtension):
          return
        cwd = pathlib.Path().absolute()

        build_temp = pathlib.Path(self.build_temp)
        build_temp.mkdir(parents=True, exist_ok=True)
        extpath = pathlib.Path(self.get_ext_fullpath(ext.name))
        extpath.parent.mkdir(parents=True, exist_ok=True)

        # Change shared library naming convention
        lib_prefix, lib_suffix = extpath.name.split(ext.name.rsplit('.', 1)[-1], 1)

        config = 'Debug' if self.debug else 'Release'
        cmake_args = [
            '-DCMAKE_SHARED_LIBRARY_PREFIX=' + lib_prefix,
            '-DCMAKE_SHARED_LIBRARY_SUFFIX=' + lib_suffix,
            '-DPYTHON_LIBRARY_PREFIX=' + lib_prefix,
            '-DPYTHON_LIBRARY_SUFFIX=' + lib_suffix,
            '-DCMAKE_LIBRARY_OUTPUT_DIRECTORY=' + str(extpath.parent.absolute()),
            '-DCMAKE_BUILD_TYPE=' + config
        ]

        build_args = [
            '--config', config,
            '--', '-j4'
        ]

        os.chdir(str(build_temp))
        self.spawn(['cmake', str(cwd)] + cmake_args)
        if not self.dry_run:
            self.spawn(['cmake', '--build', '.'] + build_args)
        os.chdir(str(cwd))

        if not extpath.exists(): extpath.mkdir()  # creates dummy if not created
