/**
 * @file Database.h
 * @brief Заголовочный файл для работы с базой данных SQLite.
 */

#pragma once

#include <string>
#include <memory>
#include <vector>
#include <sqlite3.h>


class CreateTable;

/**
 * @brief Класс для работы с базой данных SQLite.
 */
class Database {
public:
    explicit Database(const std::string& databasePath);
    ~Database();

    bool AddTable(const CreateTable& table);
    bool Exec(const std::string& query);

private:
    sqlite3* db;  // Указатель на базу данных SQLite.
};

using DatabasePtr = std::shared_ptr<Database>;
