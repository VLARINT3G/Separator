/**
 * @file CreateTable.cpp
 * @brief Реализация методов для создания таблиц в базе данных.
 */

#include <CreateTable.h>

CreateTable::CreateTable(const std::string& tableName) : tableName(tableName) {}

void CreateTable::AddTextColumn(const std::string& columnName) {
    columns.emplace_back(columnName + " TEXT");
}

std::string CreateTable::GetCreateQuery() const {
    std::string query = "CREATE TABLE IF NOT EXISTS " + tableName + " (";
    for (size_t i = 0; i < columns.size(); ++i) {
        query += columns[i];
        if (i != columns.size() - 1) {
            query += ", ";
        }
    }
    query += ");";
    return query;
}
