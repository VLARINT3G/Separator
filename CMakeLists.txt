set(CMAKE_GENERATOR "Unix Makefiles")
cmake_minimum_required(VERSION 3.22)
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
        Database.h
        CreateTable.h
        CreateTable.cpp)


find_package(SQLite3 REQUIRED)
include_directories(${SQLite3_INCLUDE_DIRS})
target_link_libraries(Separator PRIVATE sqlite3)
