/**
 * @file Database.cpp
 * @brief Реализация методов для работы с базой данных SQLite.
 */

#include <Database.h>
#include <CreateTable.h>
#include <iostream>
#include <sqlite3.h>

Database::Database(const std::string& databasePath) : db(nullptr) {
    if (sqlite3_open(databasePath.c_str(), &db) != SQLITE_OK) {
        std::cerr << "Failed to open database: " << sqlite3_errmsg(db) << std::endl;
        db = nullptr;
    }
}

Database::~Database() {
    if (db) {
        sqlite3_close(db);
    }
}

bool Database::AddTable(const CreateTable& table) {
    return Exec(table.GetCreateQuery());
}

bool Database::Exec(const std::string& query) {
    char* errMsg = nullptr;
    if (sqlite3_exec(db, query.c_str(), nullptr, nullptr, &errMsg) != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        return false;
    }
    return true;
}
