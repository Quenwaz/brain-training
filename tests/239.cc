#include "gtest/gtest.h"
#include "239.slidingWindowMaximum.cpp"

TEST(slidingWindowMaximum_test, t1)
{
    Solution s;
    std::vector<int> input{1,3,-1,-3,5,3,6,7};
    auto excp1 = std::vector<int>{3,3,5,5,6,7};
    ASSERT_EQ(s.maxSlidingWindow(input,3),excp1);
}

TEST(slidingWindowMaximum_test, t2)
{
    Solution s;
    std::vector<int> input{-7,-8,7,5,7,1,6,0};
    auto excp1 = std::vector<int>{7,7,7,7,7};
    ASSERT_EQ(s.maxSlidingWindow(input,4),excp1);
}


