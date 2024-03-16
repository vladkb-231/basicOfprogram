cmake_minimum_required(VERSION 3.27)
project(course C)

set(CMAKE_C_STANDARD 11)

add_executable(course main.c
        libs/algoritms/array/array.h
        libs/algoritms/array/array.c
        libs/algoritms/algoritms.h
        libs/algoritms/algoritms.c
)
add_subdirectory(libs)
target_link_libraries(course data_structures)
target_link_libraries(course algoritms)

