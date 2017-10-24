# Project initialization
cmake_minimum_required(VERSION 2.7.2 FATAL_ERROR)

project("cpp_sockets")

# Define warnings based on compiler
#if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
#    set(warnings "-Wall -Wextra -Werror")
#elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
#    set(warnings "/W4 /WX /EHsc")
#endif()

# Set warnings
if (NOT CONFIGURED_ONCE)
    set(CMAKE_CXX_FLAGS "${warnings}"
        CACHE STRING "Flags used by the compiler during all build types." FORCE)
endif()

# Add include directory
include_directories(include)

# Add subdirectories
add_subdirectory(src/project)

# Create a variable that is set to true and cached after the first configuration
set(CONFIGURED_ONCE TRUE CACHE INTERNAL
    "A flag showing that CMake has configured at least once.")
