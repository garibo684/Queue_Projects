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

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
