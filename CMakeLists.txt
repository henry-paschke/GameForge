cmake_minimum_required(VERSION 3.14)
set(PROJECT GameForge)
set(GF_VERSION 1.0.0)

project(${PROJECT} VERSION ${GF_VERSION} LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(BUILD_SHARED_LIBS "Build ${PROJECT} as a shared library" OFF)
option(USE_CHIPMUNK2D "Set whether chipmunk2D support is included" OFF)
option(USE_SFML "Set whether SFML support is included" OFF)

if (USE_CHIPMUNK2D)
    find_path(CHIPMUNK_INCLUDE_DIRS "chipmunk/chipmunk.h")
    find_library(CHIPMUNK_LIBRARIES NAMES chipmunk)

    if(CHIPMUNK_INCLUDE_DIRS AND CHIPMUNK_LIBRARIES)
        message(STATUS "Chipmunk2D found.")
    else()
        message(FATAL_ERROR "Chipmunk2D not found.")
    endif()
endif()

if (USE_SFML)
    find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)
endif()


set(
    SOURCES 
    src/Utilities.cpp
    src/Transform2.cpp
    src/Angle.cpp
)

if(BUILD_SHARED_LIBS)
    add_library(${PROJECT} SHARED ${SOURCES})
else()
    add_library(${PROJECT} STATIC ${SOURCES})
endif()

target_include_directories(${PROJECT} PUBLIC include/public)
target_include_directories(${PROJECT} PRIVATE include/private)

if(USE_CHIPMUNK2D)
    target_compile_definitions(${PROJECT} PUBLIC GF_USING_CHIPMUNK2D)
    target_include_directories(${PROJECT} PRIVATE ${CHIPMUNK_INCLUDE_DIRS})
    target_link_libraries(${PROJECT} PRIVATE ${CHIPMUNK_LIBRARIES})
endif()

if (USE_SFML)
    target_compile_definitions(${PROJECT} PUBLIC GF_USING_SFML)
    target_link_libraries(${PROJECT} PRIVATE sfml-system sfml-network sfml-graphics sfml-window)
endif()