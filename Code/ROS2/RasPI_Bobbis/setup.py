import os
from glob import glob
from setuptools import find_packages, setup

package_name = 'RasPI_Bobbis'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'launch'),
         glob(os.path.join('launch', '*launch.[pxy][yma]*'))),
        (os.path.join('share', package_name), glob('urdf/*'))
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='spidy320',
    maintainer_email='spidy320@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
                'controller_v3 = RasPI_Bobbis.controller_v3:main',
                'xyz_pub = RasPI_Bobbis.xyz_pub:main',
                'uart_transmit = RasPI_Bobbis.uart_transmit:main',
        ],
    },
)
