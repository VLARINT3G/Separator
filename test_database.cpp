#include <gtest/gtest.h>
#include "../Database.h"

TEST(DatabaseTest, AddsTableCorrectly) {
    Database db("test.db");

    // Очистка базы перед тестом
    db.ExecuteQuery("DROP TABLE IF EXISTS test_table;");

    bool result = db.AddTable("CREATE TABLE test_table (id INTEGER PRIMARY KEY, name TEXT);");
    EXPECT_TRUE(result);
}

TEST(DatabaseTest, LogsErrorCorrectly) {
    Database db("test.db");

    // Захватываем вывод
    std::ostringstream capturedOutput;
    std::streambuf* originalCerrBuffer = std::cerr.rdbuf();
    std::cerr.rdbuf(capturedOutput.rdbuf());  // Перенаправляем std::cerr

    // Логируем ошибку
    db.LogError("Test error message");

    // Восстанавливаем вывод
    std::cerr.rdbuf(originalCerrBuffer);

    // Проверяем, что сообщение присутствует в захваченном выводе
    EXPECT_NE(capturedOutput.str().find("Test error message"), std::string::npos);
}
