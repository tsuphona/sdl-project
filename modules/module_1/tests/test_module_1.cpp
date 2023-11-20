#include "../include/module_1.hpp"
#include <gtest/gtest.h>
#include <vector>

TEST(Module1Test, BinarySearch) {
  std::vector<int> vec = {1, 2, 3};
  EXPECT_EQ(binary_search(&vec, 3), true);
}

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}
