#include "gtest/gtest.h"
#include "867.TransposeMatrix.cpp"

TEST(palindromeNumber_test, t1)
{
    Solution sol;
    std::vector<std::vector<int>> inputMatrix{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    std::vector<std::vector<int>> outputMatrix{
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9}
    };

    ASSERT_EQ(outputMatrix, sol.transpose(inputMatrix));
}

