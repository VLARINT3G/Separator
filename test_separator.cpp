#include <gtest/gtest.h>
#include "../Separator.h"

TEST(SeparatorTest, HandlesBasicSeparators) {
    Separator separator(", ");
    EXPECT_EQ(separator.Get(), "");
    EXPECT_EQ(separator.Get(), ", ");
    EXPECT_EQ(separator.Get(), ", ");
}

TEST(SeparatorTest, HandlesEmptySeparator) {
    Separator separator("");
    EXPECT_EQ(separator.Get(), "");
    EXPECT_EQ(separator.Get(), "");
}
