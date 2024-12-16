cmake_minimum_required(VERSION 3.17)
project(Separator)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(Separator
        main.cpp
        Input.cpp
        Input.h
        Work.cpp
        Work.h
        Out.cpp
        Out.h
        Database.cpp
        Database.h)

find_package(SQLite3 REQUIRED)
include_directories(${SQLite3_INCLUDE_DIRS})
target_link_libraries(Separator ${SQLite3_LIBRARIES})
