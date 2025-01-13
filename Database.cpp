#include <Database.h>
#include <stdexcept>
#include <iostream>

/**
 * @file Database.cpp
 * @brief Реализация методов класса Database для работы с SQLite.
 */

// Конструктор
Database::Database(const std::string& databasePath) : database(nullptr) {
    if (sqlite3_open(databasePath.c_str(), &database) != SQLITE_OK) {
        throw std::runtime_error("Не удалось открыть базу данных: " + std::string(sqlite3_errmsg(database)));
    }
}

// Деструктор
Database::~Database() {
    if (database) {
        sqlite3_close(database);
    }
}

// Добавление таблицы
bool Database::AddTable(const std::string& tableDefinition) {
    char* errorMessage = nullptr;
    if (sqlite3_exec(database, tableDefinition.c_str(), nullptr, nullptr, &errorMessage) != SQLITE_OK) {
        LogError("Ошибка создания таблицы: " + std::string(errorMessage));
        sqlite3_free(errorMessage);
        return false;
    }
    return true;
}

// Логирование ошибок
void Database::LogError(const std::string& message) const {
    std::cerr << "[Database Error] " << message << std::endl;
}
