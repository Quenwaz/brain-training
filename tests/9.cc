#include "gtest/gtest.h"
#include "9.palindromeNumber.cpp"

TEST(palindromeNumber_test, t1)
{
    Solution sol;
    ASSERT_FALSE(sol.isPalindrome(-1));
    ASSERT_TRUE(sol.isPalindrome(0));
    ASSERT_TRUE(sol.isPalindrome(9));
    ASSERT_FALSE(sol.isPalindrome(10));
    ASSERT_FALSE(sol.isPalindrome(100));
    ASSERT_TRUE(sol.isPalindrome(11));
    ASSERT_TRUE(sol.isPalindrome(111));
    ASSERT_TRUE(sol.isPalindrome(121));
    ASSERT_TRUE(sol.isPalindrome(12321));
    ASSERT_TRUE(sol.isPalindrome(123454321));
    ASSERT_FALSE(sol.isPalindrome(-121));
    ASSERT_FALSE(sol.isPalindrome(1234567899));
}

