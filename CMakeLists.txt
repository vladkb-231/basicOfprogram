cmake_minimum_required(VERSION 3.27)
project(course C)

set(CMAKE_C_STANDARD 11)

add_executable(course main.c
        libs/algoritms/array/array.h
        libs/algoritms/array/array.c
        libs/data_structures/algoritm/algoritms.h
        libs/data_structures/algoritm/algoritms.c
)
add_library(exam
        libs/exam/exam.c
        libs/exam/exam.h
)
add_subdirectory(libs)
target_link_libraries(course data_structures)
target_link_libraries(course algoritms)
target_link_libraries(course exam)


