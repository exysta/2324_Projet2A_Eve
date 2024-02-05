# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/exysta/2324_Projet2A_Eve/Code/ROS2/firmware/dev_ws/ament/ament_cmake/ament_cmake_vendor_package/test/exlib_bad"
  "/home/exysta/2324_Projet2A_Eve/Code/ROS2/firmware/dev_ws/build/ament_cmake_vendor_package/test/exlib_bad-prefix/src/exlib_bad-build"
  "/home/exysta/2324_Projet2A_Eve/Code/ROS2/firmware/dev_ws/build/ament_cmake_vendor_package/test/exlib_bad-prefix/install"
  "/home/exysta/2324_Projet2A_Eve/Code/ROS2/firmware/dev_ws/build/ament_cmake_vendor_package/test/exlib_bad-prefix/tmp"
  "/home/exysta/2324_Projet2A_Eve/Code/ROS2/firmware/dev_ws/build/ament_cmake_vendor_package/test/exlib_bad-prefix/src/exlib_bad-stamp"
  "/home/exysta/2324_Projet2A_Eve/Code/ROS2/firmware/dev_ws/build/ament_cmake_vendor_package/test/exlib_bad-prefix/src"
  "/home/exysta/2324_Projet2A_Eve/Code/ROS2/firmware/dev_ws/build/ament_cmake_vendor_package/test/exlib_bad-prefix/src/exlib_bad-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/exysta/2324_Projet2A_Eve/Code/ROS2/firmware/dev_ws/build/ament_cmake_vendor_package/test/exlib_bad-prefix/src/exlib_bad-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/exysta/2324_Projet2A_Eve/Code/ROS2/firmware/dev_ws/build/ament_cmake_vendor_package/test/exlib_bad-prefix/src/exlib_bad-stamp${cfgdir}") # cfgdir has leading slash
endif()
