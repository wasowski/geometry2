#include <gtest/gtest.h>

TEST(tf2_ros, dummytest){
  EXPECT_TRUE(true);
}

int main(int argc, char** argv){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
