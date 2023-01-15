#include <gtest/gtest.h>

#include "version.h"

TEST(HelloTest, BasicAssertions) {
  EXPECT_NE(PROJECT_VERSION_PATCH, 0);
}

