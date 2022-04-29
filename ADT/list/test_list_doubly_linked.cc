#include "list_doubly_linked.h"
#include <gtest/gtest.h>


TEST(ListDoublyLinked, GetOnEmptyList) {
    ListDoublyLinked<int> l;
    ASSERT_EQ(l.Size(), 0);
    EXPECT_THROW(l.Get(0), out_of_range);
}

TEST(ListDoublyLinked, InsertElementsAtHead) {
    ListDoublyLinked<int> l;
    ASSERT_EQ(l.Size(), 0);
    for (int i = 10; i < 50; i += 10) {
        l.Insert(i, 0);
    }
    EXPECT_EQ(l.Size(), 4);
    for (int i = 10; i < 50; i += 10) {
        int index = (50 - i) / 10 - 1;
        ASSERT_EQ(l.Get(index), i);
    }
}


TEST(ListDoublyLinked, InsertElementsAtTail) {
    ListDoublyLinked<int> l;
    ASSERT_EQ(l.Size(), 0);
    for (int i = 10; i < 50; i += 10) {
        l.Insert(i, i / 10 - 1);
    }
    EXPECT_EQ(l.Size(), 4);
    for (int i = 10; i < 50; i += 10) {
        ASSERT_EQ(l.Get(i / 10 - 1), i);
    }
}
/*
TEST(ListDoublyLinked, RemoveAtTail) {
    ListDoublyLinked<int> l;
    ASSERT_EQ(l.Size(), 0);
    for (int i = 10; i < 50; i += 10) {
        l.Insert(i, i / 10 - 1);
    }
    EXPECT_EQ(l.Size(), 4);
    
    l.Remove(3);
    EXPECT_EQ(l.Size(), 3);    
    for (int i = 10; i < 40; i += 10) {
        ASSERT_EQ(l.Get(i / 10 - 1), i);
    }
}*/

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}