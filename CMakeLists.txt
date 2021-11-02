cmake_minimum_required(VERSION 3.17)
project(individual_task_1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage -Werror -Wpedantic")
set(CMAKE_C_FLAGS "-g -O0 -Wall -W -fprofile-arcs -ftest-coverage -Werror -Wpedantic")
set(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage")

add_library(common_files STATIC
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/telephone_info.c)
target_include_directories(common_files PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(main
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/main.c)
target_include_directories(main PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(main common_files)