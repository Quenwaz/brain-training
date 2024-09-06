/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start

#include <string>

class Solution {
public:

    bool isPalindrome(int x) {
        if (x < 0 ||(x != 0 &&  x % 10 == 0)){
            return false;
        }

        if (x / 10 == 0){
            return true;
        }

        int sum_of_remainders = 0; // 余数求和
        for(;x > sum_of_remainders;)
        {
            sum_of_remainders = sum_of_remainders * 10 + x % 10;
            x = x / 10;
        }

        return sum_of_remainders == x || sum_of_remainders/10 == x;
    }

    bool isPalindromeV2(int x) {
        // signed integer overflow: 998765432 * 10
        if (x < 0){
            return false;
        }

        if (x / 10 == 0){
            return true;
        }
        

        int quotient = x;
        int sum_of_remainders = 0; // 余数求和
        for(;quotient!=0;)
        {
            sum_of_remainders = sum_of_remainders * 10 + quotient % 10;
            quotient = quotient / 10;
        }

        return sum_of_remainders == x;
    }

    bool isPalindromeV1(int x) {
        const auto input = std::to_string(x);
        if (input.size() == 1) return true;

        size_t iterate = input.size() / 2;
        iterate = iterate == 0? 1: iterate;

        for (size_t i = 0, j = input.size() -1; i < iterate; ++i, j--)
        {
            if (input[i] != input[j]){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

