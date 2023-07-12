#include "LinkedList.h"
#include <gtest/gtest.h>

TEST (LinkedListTest, GetEmptyAndAppend) {
  LinkedList<int> list;
  
  EXPECT_TRUE(list.GetEmpty());
  list.Append(15);
  EXPECT_FALSE(list.GetEmpty());
}

TEST (LinkedListTest, Clear) {
  LinkedList<int> list;

  list.Append(15);
  EXPECT_FALSE(list.GetEmpty());

  list.Clear();
  EXPECT_TRUE(list.GetEmpty());
}

TEST (LinkedListTest, PrependAndGetHead) {
  LinkedList<int> list;

  list.Append(15);
  EXPECT_EQ(list.GetHead(), 15);

  list.Prepend(20);
  EXPECT_EQ(list.GetHead(), 20);
}

TEST (LinkedListTest, DeleteAndGetTail) {
  LinkedList<int> list;

  list.Append(15);
  list.Append(20);
  
  EXPECT_EQ(list.GetTail(), 20);
  
  list.Delete();
  EXPECT_EQ(list.GetTail(), 15);

  list.Delete();
  EXPECT_EQ(list.GetSize(), 0);
}

TEST (LinkedListTest, InsertAndGetSize) {
  LinkedList<int> list;
 
  list.Append(10);
  EXPECT_EQ(list.GetSize(), 1);
  list.Prepend(30);
  EXPECT_EQ(list.GetSize(), 2);
  list.Insert(list.GetPosition(30), 20);
  EXPECT_EQ(list.GetSize(), 3);

  
  EXPECT_EQ(list.GetTail(), 10);
  list.Delete();
  EXPECT_EQ(list.GetTail(), 20);
  list.Delete();
  EXPECT_EQ(list.GetTail(), 30);
  list.Delete();
  EXPECT_TRUE(list.GetEmpty());
}
TEST (LinkwsListTest, GetPosition) {
  LinkedList<int> list;

  list.Append(5);
  list.Append(10);
  list.Append(15);
  list.Append(25);
  list.Append(30);
  list.Append(35);
  EXPECT_EQ(list.GetSize(), 6);

  list.Insert(list.GetPosition(15), 20);
  EXPECT_EQ(list.GetSize(), 7);

  list.Delete();
  list.Delete();
  list.Delete();
  EXPECT_EQ(list.GetTail(), 20);
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
