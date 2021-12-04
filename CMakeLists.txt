cmake_minimum_required(VERSION 3.15)

project(
    needmon
    VERSION 0.1
    LANGUAGES CXX
    )

add_subdirectory(library)

list(APPEND CMAKE_PREFIX_PATH ${CMAKE_CURRENT_SOURCE_DIR}/library/osal/cmake)

find_package(osal REQUIRED CONFIG)

cmake_minimum_required(VERSION 3.15)

add_library(${PROJECT_NAME})

target_sources(
    ${PROJECT_NAME}
    PRIVATE
        src/buffer.cpp
        src/communication.cpp
        src/ethernet_client.cpp
        src/ethernet_server.cpp
        src/ethernet.cpp
        src/message.cpp
        src/payload.cpp
        src/queue.cpp
        src/template.cpp
        src/topic.cpp
    )

target_link_libraries(
    ${PROJECT_NAME}
    PUBLIC
        osal::osal
    )

include(GNUInstallDirs)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
           $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX "d")

install(
    TARGETS ${PROJECT_NAME}
    EXPORT ${PROJECT_NAME}-config
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(
    EXPORT ${PROJECT_NAME}-config
    NAMESPACE ${PROJECT_NAME}::
    DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/cmake
    )

install(
    DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/include/${PROJECT_NAME}/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}
    )
