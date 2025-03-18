#include <CreateTable.h>  // Подключаем заголовочный файл

CreateTable::CreateTable(const TableName &tableName)
        : tableName_(tableName) {}

void CreateTable::AddStringColumn(const std::string &columnName) {
    columns_.push_back(columnName);  // Добавляем колонку в список
}

std::string CreateTable::GetCreateQuery() const {
    std::string query = "CREATE TABLE " + tableName_ + " (";
    if (!columns_.empty()) {  // Проверяем, есть ли столбцы
        for (const auto& column : columns_) {
            query += column + " TEXT, ";  // Добавляем колонку
        }
        query.pop_back(); // Убираем лишнюю запятую
        query.pop_back();
    }
    query += ");";  // Закрываем скобку корректно
    return query;
}
