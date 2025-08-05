cmake_minimum_required(VERSION 3.16)
project(SilKit LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(MSVC)
    add_compile_options(/W4 /permissive-)
else()
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/../bin")

file(GLOB SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_library(silkit_core ${SOURCES})
target_include_directories(silkit_core PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

add_executable(silkit "${CMAKE_CURRENT_SOURCE_DIR}/src/silkit.cpp")
target_link_libraries(silkit PRIVATE silkit_core)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

install(TARGETS silkit DESTINATION bin)

enable_testing()
