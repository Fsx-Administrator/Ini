cmake_minimum_required(VERSION 3.16)

set(INI_LIBRARY ini)
project(${INI_LIBRARY} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core)

set(INCLUDE_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/include)
file(GLOB HEADERS ${INCLUDE_ROOT}/*.h ${INCLUDE_ROOT}/*.hpp)
file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_library(${INI_LIBRARY} STATIC ${HEADERS} ${SOURCES})
target_include_directories(${INI_LIBRARY} PUBLIC ${INCLUDE_ROOT})
target_link_libraries(${INI_LIBRARY} Qt6::Core)
