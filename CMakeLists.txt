cmake_minimum_required(VERSION 3.10)

project(needmon)

add_subdirectory(
    src
)

include_directories(
    src
)
target_include_directories(
    needmon
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src
)