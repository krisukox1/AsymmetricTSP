cmake_minimum_required(VERSION 2.8)

project(project1)

#INCLUDE_DIRECTORIES(include)

set(SOURCES
    include/Graph.hpp

    src/Graph.cpp

    main.cpp)

add_executable(project ${SOURCES})
