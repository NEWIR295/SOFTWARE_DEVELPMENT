# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/TESTing_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/TESTing_autogen.dir/ParseCache.txt"
  "TESTing_autogen"
  )
endif()
