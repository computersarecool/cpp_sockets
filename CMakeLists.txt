# Project initialization
cmake_minimum_required(VERSION 2.7.2 FATAL_ERROR)

project("cpp_sockets")

# GNU compiler settings
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    # Wall: Enable all warnings about constructors
    # Wextra: Enable some extra warnings
    # Werror: Treat all warnings as errors
    set(warnings "-Wall -Wextra -Werror")

  # Visual C++ (Microsoft) settings
  elseif (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    # W4: Show the most warnings
    # WX: Treat all warnings as errors
    # EHsc: Only emit code for exception filters when detected that the code in the try {} block might throw a C++ exception
    set(warnings "/W4 /WX /EHsc")
    set(CMAKE_CONFIGURATION_TYPES Debug Release)
endif()

# Set warnings
if (NOT CONFIGURED_ONCE)
    set(CMAKE_CXX_FLAGS "${warnings}" CACHE STRING "Flags used by the compiler during all build types." FORCE)
endif()

# Add include directory
include_directories(include)

# Add subdirectories
add_subdirectory(src/project)

# Create a variable that is set to true and cached after the first configuration
set(CONFIGURED_ONCE TRUE CACHE INTERNAL "A flag showing that CMake has configured at least once.")
