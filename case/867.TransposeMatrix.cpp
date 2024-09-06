/*
 * @lc app=leetcode.cn id=867 lang=cpp
 *
 * [867] 转置矩阵
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        if (matrix.empty()){
            return {};
        }

        if (matrix.size() == 1 && matrix.front().size() == 1){
            return matrix;
        }

        vector<vector<int>> matrixT;
        matrixT.resize(matrix.front().size());
        const size_t colSize = matrix.size();
        for (size_t i = 0; i < matrixT.size(); ++i)
        {
            matrixT[i].resize(colSize);
            for (size_t j = 0; j < colSize; ++j)
            {
                matrixT[i][j] = matrix[j][i];
            }
        }

        return matrixT;
    }
};
// @lc code=end

