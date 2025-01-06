cmake_minimum_required(VERSION 3.00...3.50)
project(FileAccess
        VERSION 1.0.0
        DESCRIPTION ""
        HOMEPAGE_URL ""
        LANGUAGES C
)

set(FA_SOURCES ${CMAKE_CURRENT_LIST_DIR}/FileAccess.h
        ${CMAKE_CURRENT_LIST_DIR}/FileAccess.c)

set(FA_TARGET "fileaccess")
add_library("${FA_TARGET}" INTERFACE)
target_sources("${FA_TARGET}" INTERFACE "${FA_SOURCES}")

add_executable(test main.c)
target_link_libraries(test PRIVATE fileaccess)