/**
 * @file Database.h
 * @brief Заголовочный файл для работы с базой данных SQLite.
 */

#pragma once

#include <sqlite3.h>
#include <filesystem>
#include <string>
#include <list>

class CreateTable {
public:
    explicit CreateTable(const std::string& tableName);
    void addStringColumn(const std::string& columnName);
    std::string getSqlStr() const;

private:
    std::list<std::string> columns_;
    std::string tableName_;
};

class Database {
public:
    explicit Database(const std::filesystem::path& databasePath);
    ~Database();

    bool addTable(const CreateTable& table) const;
    bool exec(const std::string& sqlQuery) const;

private:
    sqlite3* sql_;
};
