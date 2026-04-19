cmake_minimum_required(VERSION 3.22)
project(Demo)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(utils)
add_subdirectory(include/googletest)
include_directories(include/googletest/googletest/include)

file(GLOB CHILD_DIRS RELATIVE ${CMAKE_SOURCE_DIR} "${CMAKE_SOURCE_DIR}/week*")

foreach(dir ${CHILD_DIRS})
    if(IS_DIRECTORY "${CMAKE_SOURCE_DIR}/${dir}")
        add_subdirectory(${dir})
    endif()
endforeach()
