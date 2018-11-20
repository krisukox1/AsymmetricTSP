cmake_minimum_required(VERSION 2.8)

project(project1)

#INCLUDE_DIRECTORIES(include)

set(SOURCES
    include/Graph.hpp
    include/TSM.hpp
    include/Routes.hpp
    include/Subset.hpp
    include/Display.hpp
    src/Graph.cpp
    src/TSM.cpp
    src/Routes.cpp
    src/Display.cpp
    main.cpp)

add_executable(project ${SOURCES})
