#pragma once
#include <string>
#include <sqlite3.h>

/**
 * @file Database.h
 * @brief Определяет класс для работы с базой данных SQLite.
 */

class Database {
public:
    explicit Database(const std::string &dbName);
    ~Database();

    bool AddTable(const std::string &query);
    bool ExecuteQuery(const std::string &query);
    void LogError(const std::string &message);

private:
    sqlite3 *db_;
    std::string dbName_;
};
