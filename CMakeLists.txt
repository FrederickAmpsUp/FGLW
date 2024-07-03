cmake_minimum_required(VERSION 3.10)
project(FGLW)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Include directory
include_directories(inc)

add_definitions(-DBX_CONFIG_DEBUG)

link_directories(lib/)

# Gather all source files from src/ recursively
file(GLOB_RECURSE SRC_FILES src/*.c src/*.cpp)

if(EMSCRIPTEN)
    set(CMAKE_EXECUTABLE_SUFFIX ".html")
    add_definitions(-DBX_CONFIG_DEBUG)
else()
endif()

# Create a static library from the gathered source files
add_library(flgwDeps STATIC ${SRC_FILES})

if(EMSCRIPTEN)
    target_link_options(flgwDeps PRIVATE "-s USE_GLFW=3" "-s FULL_ES2=1")
else()
    find_package(glfw3 3.3 REQUIRED)
    target_link_libraries(flgwDeps glfw GL GLU)
endif()

# Gather all source files from test/ (non-recursive)
file(GLOB TEST_FILES test/*.c test/*.cpp)

# Create executables for each source file in test/
foreach(TEST_FILE ${TEST_FILES})
    # Get the filename without extension
    get_filename_component(TEST_NAME ${TEST_FILE} NAME_WE)
    # Create the executable
    add_executable(${TEST_NAME} ${TEST_FILE})
    # Link the executable with the flgwDeps library
    target_link_libraries(${TEST_NAME} flgwDeps)
endforeach()

# Gather all source files from run/ (non-recursive)
file(GLOB RUN_FILES run/*.c run/*.cpp)

# Create executables for each source file in run/
foreach(RUN_FILE ${RUN_FILES})
    # Get the filename without extension
    get_filename_component(RUN_NAME ${RUN_FILE} NAME_WE)
    # Create the executable
    add_executable(${RUN_NAME} ${RUN_FILE})
    # Link the executable with the flgwDeps library
    target_link_libraries(${RUN_NAME} flgwDeps)
endforeach()

# Install the run executables
install(TARGETS ${RUN_NAME} DESTINATION /usr/bin)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})