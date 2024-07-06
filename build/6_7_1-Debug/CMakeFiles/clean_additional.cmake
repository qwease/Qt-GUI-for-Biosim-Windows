# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\biosim4Win_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\biosim4Win_autogen.dir\\ParseCache.txt"
  "biosim4Win_autogen"
  )
endif()
