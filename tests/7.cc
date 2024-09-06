#include "gtest/gtest.h"
#include "7.integerReversal.cpp"

TEST(integerReversal_test, t1)
{
    Solution sol;
    ASSERT_EQ(321,sol.reverse(123));
    ASSERT_EQ(-321,sol.reverse(-123));
    // 反转后超过整数范围的测试
    ASSERT_EQ(0,sol.reverse(1147483648));
    ASSERT_EQ(0,sol.reverse(-1147483648));
}

