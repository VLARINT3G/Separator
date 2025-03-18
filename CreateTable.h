#pragma once

#include <string>
#include <vector>
#include <Separator.h>

/**
 * @brief Определение типа для названия таблицы.
 */
using TableName = std::string;

/**
 * @brief Определение типа для списка столбцов таблицы.
 */
using ColumnList = std::vector<std::string>;

/**
 * @class CreateTable
 * @brief Класс для создания SQL-запроса создания таблицы.
 */
class CreateTable {
public:
    /**
     * @brief Конструктор класса CreateTable.
     * @param tableName Название таблицы.
     */
    explicit CreateTable(const TableName &tableName);

    /**
     * @brief Добавляет в структуру таблицы новую колонку типа TEXT.
     * @details Метод не выполняет SQL-запрос, а лишь сохраняет имя колонки,
     * чтобы затем использовать его в SQL-операции CREATE TABLE.
     * @param columnName Имя добавляемой колонки.
     */
    void AddStringColumn(const std::string &columnName);

    /**
     * @brief Генерирует SQL-запрос для создания таблицы.
     * @return Строка с SQL-запросом.
     */
    std::string GetCreateQuery() const;

private:
    TableName tableName_;  ///< Название таблицы.
    ColumnList columns_;  ///< Список столбцов таблицы.
};
