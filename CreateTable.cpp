#include <CreateTable.h>
#include <Separator.h>  ///< Подключение класса Separator для корректной работы с разделителями.

/**
 * @brief Конструктор класса CreateTable.
 * @param tableName Название таблицы.
 */
CreateTable::CreateTable(const TableName &tableName) : tableName_(tableName) {}

/**
 * @brief Добавляет колонку типа TEXT в таблицу.
 * @details Метод не выполняет SQL-запрос, а лишь сохраняет имя колонки,
 * чтобы затем использовать его в SQL-операции CREATE TABLE.
 * @param columnName Имя добавляемой колонки.
 */
void CreateTable::AddStringColumn(const std::string &columnName) {
  columns_.emplace_back(columnName + " TEXT");
}

/**
 * @brief Генерирует SQL-запрос для создания таблицы.
 * @return Строка с SQL-запросом.
 */
std::string CreateTable::GetCreateQuery() const {
  std::string query = "CREATE TABLE IF NOT EXISTS " + tableName_ + " (";
  Separator separator(", ");  ///< Используем вспомогательный класс для вставки разделителя.

  for (const auto &column : columns_) {
    query += separator.Get();
    query += column;
  }

  query += ");";
  return query;
}
