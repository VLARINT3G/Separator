/**
 * @file Database.h
 * @brief Определяет класс для работы с базой данных SQLite.
 */

#pragma once
#include <string>
#include <sqlite3.h>

class Database {
 public:
  explicit Database(const std::string &databasePath);
  ~Database();

  bool AddTable(const std::string &tableDefinition);
  void LogError(const std::string &message) const;

 private:
  sqlite3 *database;
};
