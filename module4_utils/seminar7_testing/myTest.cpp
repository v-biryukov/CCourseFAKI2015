#include <iostream>
#include <linkedList.hpp>
#include <gtest/gtest.h>


TEST(LinkedListTest, Empty)
{
    LinkedList<int> a;
    EXPECT_EQ(a.isEmpty(), true);
    EXPECT_EQ(a.size(), 0);
}


TEST(LinkedListTest, PushFront)
{
    LinkedList<int> a;
    a.pushFront(10);

    EXPECT_EQ(a.size(), 1);
    ASSERT_EQ(*a.begin(), 10);
}


TEST(LinkedListTest, PushBack)
{
    LinkedList<int> a;
    a.pushBack(10);

    EXPECT_EQ(a.size(), 1);
    ASSERT_EQ(*a.begin(), 10);
}


TEST(LinkedListTest, PushBackPopFront)
{
    LinkedList<int> a;
    a.pushBack(10);
    int result = a.popFront();

    ASSERT_EQ(result, 10);
}

TEST(LinkedListTest, PushFrontPopFront)
{
    LinkedList<int> a;
    a.pushFront(10);
    int result = a.popFront();

    ASSERT_EQ(result, 11);
}

TEST(LinkedListTest, Push5and5andPop)
{
    LinkedList<int> a;

    for (int i = 0; i < 5; ++i)
        a.pushFront(10 + 10 * i);

    for (int i = 0; i < 5; ++i)
        a.pushBack(60 + 10 * i);

    ASSERT_EQ(a.size(), 10);

    for (int i = 0; i < 5; ++i)
    {
        int result = a.popFront();
        ASSERT_EQ(result, 50 - 10 * i);
    }

    for (int i = 0; i < 5; ++i)
    {
        int result = a.popFront();
        ASSERT_EQ(result, 60 + 10 * i);
    }

    ASSERT_EQ(a.size(), 0);
}


//int main()
//{
//    testing::InitGoogleTest();
//    auto result = RUN_ALL_TESTS();
//    std::cout << "RUN_ALL_TESTS returned: " << result << std::endl;
//}