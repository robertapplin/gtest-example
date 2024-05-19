#include "gtest/gtest.h"

class MyTest : public testing::Test {
protected:
  void SetUp() override {
    m_unusedVar = "Hello";
  }

  std::string m_unusedVar;
};

TEST_F(MyTest,
       test_example_which_should_fail) {
  ASSERT_TRUE(false);
}
