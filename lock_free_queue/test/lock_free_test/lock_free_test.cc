#include "LockFreeQueue.h"
#include <gtest/gtest.h>
#include <thread>

TEST(LockFreeQueueTest, PushAndPop) {
  LockFreeQueue<int> queue;
  const int element_num = 1000;

  for (int i = 1; i <= element_num; ++i) {
    queue.push(i);
  }
  
  for (int i = 1; i <= element_num; ++i) {
    std::shared_ptr<int> value = queue.pop();
    ASSERT_TRUE(value != nullptr);
    EXPECT_EQ(*value, i);
  }
}

TEST(LockFreeQueueTest, PopFromEmptyQueue) {
  LockFreeQueue<int> queue;

  std::shared_ptr<int> value = queue.pop();
  EXPECT_TRUE(value == nullptr);
}
TEST(LockFreeQueueTest, Alternative) {
  LockFreeQueue<int> queue;

  queue.push(1);
  queue.push(2);
  queue.push(3);

  std::shared_ptr<int> value1 = queue.pop();
  ASSERT_TRUE(value1 != nullptr);
  EXPECT_EQ(*value1, 1);

  std::shared_ptr<int> value2 = queue.pop();
  ASSERT_TRUE(value2 != nullptr);
  EXPECT_EQ(*value2, 2);

  std::shared_ptr<int> value3 = queue.pop();
  ASSERT_TRUE(value3 != nullptr);
  EXPECT_EQ(*value3, 3);

  std::shared_ptr<int> value4 = queue.pop();
  ASSERT_TRUE(value4 == nullptr);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}