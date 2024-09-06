    /*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start

#include <vector>
#include <queue>
#include <set>
#include <algorithm>

class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        std::multiset<int> window_set;
        std::vector<int> result;
        if (k == 0) return result;
        for (size_t i =0; i < nums.size();)
        {
            if(window_set.size() != k){
                window_set.insert(nums[i]);
                ++i;
            }

            if (window_set.size() == k)
            {
                result.push_back(*window_set.rbegin());
                window_set.erase(window_set.find(nums[i-k]));
            }
        }

        return result;
    }
};
// @lc code=end

