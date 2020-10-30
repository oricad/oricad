find_package(Git REQUIRED)
execute_process(
  COMMAND ${GIT_EXECUTABLE} rev-parse HEAD
  RESULT_VARIABLE result
  OUTPUT_VARIABLE ORICAD_GIT_HASH
  OUTPUT_STRIP_TRAILING_WHITESPACE
)
if(result)
  message(FATAL_ERROR "Failed to get git hash: ${result}")
endif()

configure_file(oricad_version.cpp.in oricad_version.cpp @ONLY)

include(GenerateExportHeader)
generate_export_header(Oricad_Config
  EXPORT_FILE_NAME "${CMAKE_CURRENT_BINARY_DIR}/exports/oricad_config_export.h"
)

add_library(Oricad_Config SHARED)
target_sources(Oricad_Config
  PUBLIC oricad_version.h
  PUBLIC "${CMAKE_CURRENT_BINARY_DIR}/oricad_version.cpp"
)
target_include_directories(Oricad_Config
  PUBLIC "${CMAKE_CURRENT_BINARY_DIR}/exports"
  PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}"
)
set_target_properties(Oricad_Config PROPERTIES
  VERSION ${ORICAD_VERSION}
  SOVERSION ${ORICAD_VERSION_MAJOR}
  CXX_VISIBILITY_PRESET hidden
  VISIBILITY_INLINES_HIDDEN YES
)

add_library(Oricad::Config ALIAS Oricad_Config)