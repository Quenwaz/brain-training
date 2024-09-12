/*
 * @lc app=leetcode.cn id=542 lang=cpp
 *
 * [542] 01 矩阵
 */

// @lc code=start
#include <vector>
#include <queue>
using std::vector;
using std::queue;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        queue<std::pair<int, int>> que;
        for (size_t i = 0; i < mat.size(); i++)
        {
            for (size_t j = 0; j < mat.at(i).size(); j++)
            {
                if (mat[i][j] != 0){
                    que.emplace(i,j);
                }
            }
        }
        

        vector<vector<int>> result;



        return result;
    }
};
// @lc code=end

