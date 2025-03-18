#include <gtest/gtest.h>
#include "../CreateTable.h"

TEST(CreateTableTest, AddsColumnsCorrectly) {
    CreateTable table("my_table");

    table.AddStringColumn("name");
    table.AddStringColumn("age");

    EXPECT_EQ(table.GetCreateQuery(), "CREATE TABLE my_table (name TEXT, age TEXT);");
}

TEST(CreateTableTest, HandlesEmptyColumns) {
    CreateTable table("empty_table");

    EXPECT_EQ(table.GetCreateQuery(), "CREATE TABLE empty_table ();");
}
