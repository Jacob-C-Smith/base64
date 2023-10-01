# BASE64 CMake configuration file:
# This file is meant to be placed in a cmake subfolder of BASE64-devel-2.x.y-VC

cmake_minimum_required(VERSION 3.0)

include(FeatureSummary)
set_package_properties(BASE64 PROPERTIES
    URL "https://www.g10.app/status#parser_serializer"
    DESCRIPTION "base 64"
)

# Copied from `configure_package_config_file`
macro(set_and_check _var _file)
    set(${_var} "${_file}")
    if(NOT EXISTS "${_file}")
        message(FATAL_ERROR "File or directory ${_file} referenced by variable ${_var} does not exist !")
    endif()
endmacro()

# Copied from `configure_package_config_file`
macro(check_required_components _NAME)
    foreach(comp ${${_NAME}_FIND_COMPONENTS})
        if(NOT ${_NAME}_${comp}_FOUND)
            if(${_NAME}_FIND_REQUIRED_${comp})
                set(${_NAME}_FOUND FALSE)
            endif()
        endif()
    endforeach()
endmacro()

set(BASE64_FOUND TRUE)

# For compatibility with autotools BASE64-config.cmake, provide BASE64_* variables.

set_and_check(BASE64_PREFIX       "${CMAKE_CURRENT_LIST_DIR}/..")
set_and_check(BASE64_EXEC_PREFIX  "${CMAKE_CURRENT_LIST_DIR}/..")
set_and_check(BASE64_INCLUDE_DIR  "${BASE64_PREFIX}/include")
set(BASE64_INCLUDE_DIRS           "${BASE64_INCLUDE_DIR}")
set_and_check(BASE64_BINDIR       "${CMAKE_CURRENT_LIST_DIR}/../build/Debug/")
set_and_check(BASE64_LIBDIR       "${CMAKE_CURRENT_LIST_DIR}/../build/Debug/")

set(BASE64_LIBRARIES base64::base64)

# All targets are created, even when some might not be requested though COMPONENTS.
# This is done for compatibility with CMake generated BASE64-target.cmake files.

set(_BASE64_library     "${BASE64_LIBDIR}/base64.lib")
set(_BASE64_dll_library "${BASE64_BINDIR}/base64.dll")
if(EXISTS "${_BASE64_library}" AND EXISTS "${_BASE64_dll_library}")
    if(NOT TARGET base64::base64)
        add_library(base64::base64 SHARED IMPORTED)
        set_target_properties(base64::base64
            PROPERTIES
                INTERFACE_INCLUDE_DIRECTORIES "${BASE64_INCLUDE_DIRS}"
                IMPORTED_IMPLIB "${_BASE64_library}"
                IMPORTED_LOCATION "${_BASE64_dll_library}"
                COMPATIBLE_INTERFACE_BOOL "BASE64_SHARED"
                INTERFACE_BASE64_SHARED "ON"
        )
    endif()
    set(BASE64_BASE64_FOUND TRUE)
else()
    set(BASE64_BASE64_FOUND FALSE)
endif()
unset(_BASE64_library)
unset(_BASE64_dll_library)

check_required_components(BASE64)
