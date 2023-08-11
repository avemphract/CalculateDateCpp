cmake_minimum_required(VERSION 3.21)

project(CppHomework_4 VERSION 1.0)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

set(Headers
    DateFunctions.h
)

set(Sources
    CDate.cpp
    DateFunctions.cpp
)

add_library(CppHomework_4 STATIC ${Sources} ${Headers})
add_executable(CppHomework_4_main main.cpp)
target_link_libraries(CppHomework_4_main PUBLIC
    CppHomework_4
)
add_subdirectory(test)
