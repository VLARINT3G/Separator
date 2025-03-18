cmake_minimum_required(VERSION 3.22)
project(SeparatorTests)

# Включаем тестирование
enable_testing()

# Подключаем директорию с исходниками
include_directories(..)

# Подключаем Google Test
include(FetchContent)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
)

FetchContent_MakeAvailable(googletest)

# Создаём исполняемый файл для тестов
add_executable(unit_tests
        test_separator.cpp
        test_create_table.cpp
        test_database.cpp
        ../CreateTable.cpp  # <-- Убедитесь, что этот файл добавлен
)

# Линкуем тесты с библиотеками: GoogleTest, библиотека Separator и SQLite
target_link_libraries(unit_tests
        PRIVATE
        gtest_main
        Separator
        sqlite3
        pthread
        gtest
)

# Добавляем тесты в CTest
add_test(NAME SeparatorTests COMMAND unit_tests)
