/**
 * @file CreateTable.h
 * @brief Заголовочный файл для создания таблиц в базе данных.
 */

#pragma once

#include <string>
#include <vector>

/**
 * @brief Класс для создания таблиц в базе данных.
 */
class CreateTable {
public:
    explicit CreateTable(const std::string& tableName);

    void AddTextColumn(const std::string& columnName);
    std::string GetCreateQuery() const;

private:
    std::string tableName;
    std::vector<std::string> columns;
};
