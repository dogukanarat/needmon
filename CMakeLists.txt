cmake_minimum_required(VERSION 3.10)

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true src/*.cpp)
file(GLOB_RECURSE HEADERS LIST_DIRECTORIES true inc/*.h)

enable_testing()

add_subdirectory(library)
add_subdirectory(test)

add_library(needmon ${SOURCES})
set_target_properties(needmon PROPERTIES PUBLIC_HEADER "${HEADERS}")
target_include_directories(needmon PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc)

target_link_libraries(needmon PUBLIC osal)

install(TARGETS needmon PUBLIC_HEADER DESTINATION include/needmon/)
