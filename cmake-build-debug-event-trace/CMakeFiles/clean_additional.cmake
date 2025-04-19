# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/projectQt_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/projectQt_autogen.dir/ParseCache.txt"
  "projectQt_autogen"
  )
endif()
