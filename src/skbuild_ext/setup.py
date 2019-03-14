from skbuild import setup

setup(
    name='skbuild_playground',
    version='0.0.1',
    description="Sample skbuild extension",
    package_dir = {'playground': 'src'},
    packages = ['playground']
)
