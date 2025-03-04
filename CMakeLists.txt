cmake_minimum_required(VERSION 3.22)
project(Separator)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

# Создаём библиотеку Separator
add_library(Separator STATIC
        Input.cpp
        Work.cpp
        Out.cpp
        Database.cpp
        CreateTable.cpp  # <--- Обязательно добавляем реализацию
        Separator.cpp
)

find_package(SQLite3 REQUIRED)
include_directories(${SQLite3_INCLUDE_DIRS})

# Главный исполняемый файл
add_executable(main_exec main.cpp)
target_link_libraries(main_exec PRIVATE Separator sqlite3)

# Включаем тесты
option(ENABLE_TESTS "Enable unit tests" ON)
if (ENABLE_TESTS)
    add_subdirectory(tests)
endif()
