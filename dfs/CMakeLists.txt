# CMakeList.txt : CMake project for server, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (dfs "dfs.cpp" "dfs.h" "structures.cpp" "structures.h" "sysutils.h" "sysutils.cpp" "defaults.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET dfs PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
