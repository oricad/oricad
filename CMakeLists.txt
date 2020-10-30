cmake_minimum_required(VERSION 3.18)

# Enable the cmake modules in /cmake
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(oricadVersionDetails)

project(ORICAD
  VERSION ${ORICAD_VER}
  DESCRIPTION "Computer-aided origami design tools"
  HOMEPAGE_URL "oricad.org"
  LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

add_subdirectory(src)