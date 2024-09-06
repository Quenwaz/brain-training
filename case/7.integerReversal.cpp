/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
#include <limits>

class Solution {
public:
    int reverse(int x) {
        int rx = 0;
        for (;x!= 0;)
        {
            if ( rx < std::numeric_limits<int>::min()/10 || rx > std::numeric_limits<int>::max()/10)
            {
                return 0;
            }
            rx = rx * 10 + x % 10;

            x /= 10;
        }
        return rx;
    }

    int reverseV1(int x) {
        long long rx = 0;
        for (;x!= 0;)
        {
            rx = rx * 10 + x % 10;
            if ( rx < std::numeric_limits<int>::min() || rx > std::numeric_limits<int>::max())
            {
                return 0;
            }
            x /= 10;
        }
        return rx;
    }
};
// @lc code=end

