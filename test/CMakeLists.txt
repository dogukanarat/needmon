file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true src/*.cpp)
file(GLOB_RECURSE HEADERS LIST_DIRECTORIES true inc/.h)

add_executable(needmon_unit_testing ${SOURCES})
target_include_directories(needmon_unit_testing PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc)
target_link_libraries(needmon_unit_testing PRIVATE gtest osal)
add_test(test_all needmon_unit_testing)
