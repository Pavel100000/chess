#----------------------------------------------------------------
# Generated CMake target import file for configuration "MyDebug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "freetype" for configuration "MyDebug"
set_property(TARGET freetype APPEND PROPERTY IMPORTED_CONFIGURATIONS MYDEBUG)
set_target_properties(freetype PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_MYDEBUG "C"
  IMPORTED_LOCATION_MYDEBUG "${_IMPORT_PREFIX}/lib/libfreetype.a"
  )

list(APPEND _cmake_import_check_targets freetype )
list(APPEND _cmake_import_check_files_for_freetype "${_IMPORT_PREFIX}/lib/libfreetype.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
