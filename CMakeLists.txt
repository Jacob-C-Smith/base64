# Need CMake 3.20
cmake_minimum_required (VERSION 3.20)

# The name of the repository
project ("base64")

# Set the correct paths
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)
set(CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/extern/)

# Set compiler warnings
if(MSVC)
    # TODO
else()

    # For clang
    #set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lrt -std=gnu99 -Wall -Wextra -Wpedantic -Weverything -Wno-declaration-after-statement -Ofast")

    # For GCC
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=gnu99 -Wall -Wextra -Wpedantic -Wno-declaration-after-statement -O3")
    add_compile_definitions(__USE_POSIX199309)
endif()

# Comment out for Debug mode
set(IS_DEBUG_BUILD CMAKE_BUILD_TYPE STREQUAL "Debug")

# Set debug mode
if (${IS_DEBUG_BUILD})
    add_compile_definitions(NDEBUG)
endif()

# Find the sync module
if ( NOT "${HAS_SYNC}")

    # Log
    message("[json] Adding sync project")

    # Add the sync directory
    add_subdirectory(${CMAKE_SOURCE_DIR}/extern/sync ${CMAKE_SOURCE_DIR}/build/sync)

    # Let any parent project know that this project has sync
    set(HAS_SYNC true PARENT_SCOPE)
endif()

# Find the log module
if ( NOT "${HAS_LOG}")

    # Log
    message("[json] Adding log project")

    # Add the log directory
    add_subdirectory(${CMAKE_SOURCE_DIR}/extern/log ${CMAKE_SOURCE_DIR}/build/log)

    # Let any parent project know that this project has log
    set(HAS_LOG true PARENT_SCOPE)
endif()

# Add the base64 project
if ( NOT "${HAS_BASE64}")

    # Log
    message("[base64] Adding base64 project")

    # Let any parent project know that it has the base64 project
    set(HAS_BASE64 CACHE true PARENT_SCOPE)
endif()

# Add source to the executable
add_executable(base64_example "main.c")
add_dependencies(base64_example log sync base64)
target_include_directories(base64_example PUBLIC include include/base64/)
target_link_libraries(base64_example sync log base64)

## Add source to the tester
add_executable (base64_test "base64_test.c")
add_dependencies(base64_test sync log base64)
target_include_directories(base64_test PUBLIC include include/base64 )
target_link_libraries(base64_test sync log base64)

# Add source to the library
add_library(base64 SHARED "base64.c")
add_dependencies(base64 log sync base64)
target_include_directories(base64 PUBLIC include include/base64/)
target_link_libraries(base64 sync log)