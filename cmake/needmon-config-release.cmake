#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "needmon::needmon" for configuration "Release"
set_property(TARGET needmon::needmon APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(needmon::needmon PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libneedmon.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS needmon::needmon )
list(APPEND _IMPORT_CHECK_FILES_FOR_needmon::needmon "${_IMPORT_PREFIX}/lib/libneedmon.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
