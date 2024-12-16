/**
 * @file Database.cpp
 * @brief Реализация методов для работы с базой данных SQLite.
 */

#include <Database.h>
#include <iostream>

Database::Database(const std::filesystem::path& databasePath) {
    if (sqlite3_open(databasePath.string().c_str(), &sql_)) {
        std::cerr << "Failed to open database: " << sqlite3_errmsg(sql_) << std::endl;
        sql_ = nullptr;
    }
}

Database::~Database() {
    if (sql_) {
        sqlite3_close(sql_);
    }
}

bool Database::addTable(const CreateTable& table) const {
    return exec(table.getSqlStr());
}

bool Database::exec(const std::string& sqlQuery) const {
    char* errorMessage = nullptr;
    if (sqlite3_exec(sql_, sqlQuery.c_str(), nullptr, nullptr, &errorMessage) != SQLITE_OK) {
        std::cerr << "SQL error: " << errorMessage << std::endl;
        sqlite3_free(errorMessage);
        return false;
    }
    return true;
}

CreateTable::CreateTable(const std::string& tableName) : tableName_(tableName) {}

void CreateTable::addStringColumn(const std::string& columnName) {
    columns_.push_back(columnName + " TEXT");
}

std::string CreateTable::getSqlStr() const {
    std::string sql = "CREATE TABLE IF NOT EXISTS " + tableName_ + " (id INTEGER PRIMARY KEY";
    for (const auto& column : columns_) {
        sql += ", " + column;
    }
    sql += ");";
    return sql;
}
