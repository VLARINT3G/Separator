#include <Database.h>
#include <stdexcept>
#include <iostream>

/**
 * @file Database.cpp
 * @brief Реализация методов класса Database для работы с SQLite.
 */

#include "Database.h"
#include <iostream>

Database::Database(const std::string &dbName) : dbName_(dbName) {
    if (sqlite3_open(dbName_.c_str(), &db_) != SQLITE_OK) {
        std::cerr << "Error opening database: " << sqlite3_errmsg(db_) << std::endl;
    }
}

Database::~Database() {
    sqlite3_close(db_);
}

bool Database::AddTable(const std::string &query) {
    // Очистка таблицы перед созданием
    std::string modifiedQuery = "CREATE TABLE IF NOT EXISTS " + query.substr(13); // Убираем 'CREATE TABLE'

    return ExecuteQuery(modifiedQuery);
}

bool Database::ExecuteQuery(const std::string &query) {
    char *errMsg = nullptr;
    if (sqlite3_exec(db_, query.c_str(), 0, 0, &errMsg) != SQLITE_OK) {
        std::cerr << "Error creating table: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        return false;
    }
    return true;
}

void Database::LogError(const std::string &message) {
    std::cerr << "[Database Error] " << message << std::endl;
}
