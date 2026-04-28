cmake_minimum_required(VERSION 3.16)
project(computer_science_implementations)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE sources
        "${CMAKE_SOURCE_DIR}/src/*.c"
        "${CMAKE_SOURCE_DIR}/src/*.cpp"
        )

add_definitions(-DSOME_DEFINITION)

add_executable(csi ${sources})

target_include_directories(csi PUBLIC "${CMAKE_SOURCE_DIR}/include")
