/*
 * @lc app=leetcode.cn id=542 lang=cpp
 *
 * [542] 01 矩阵
 */

// @lc code=start
#include <vector>
#include <queue>
#include <stack>
#include <array>
#include <deque>
using std::vector;
using std::queue;

class Solution {
public:
    const std::vector<std::pair<int,int>> direction = {{-1,0},{0,-1},{1,0},{0,1}};

    vector<vector<int>> dfs(vector<vector<int>>& mat, size_t row, size_t col)
    {
        struct LayerIndex{
            size_t row{0};
            size_t col{0};
            int layer{0};
        };

        const auto _dfs = [&](LayerIndex initindex){
            std::queue<LayerIndex> que;
            que.push(initindex);
            std::deque<std::deque<bool>> visited(row,std::deque<bool>(col, false));
            while (!que.empty())
            {
                auto [strow, stcol, layer] = que.front();
                que.pop();

                visited[strow][stcol] = true;
                const auto next_layer = layer + 1;
                for (auto& dir : direction)
                {
                    auto currow = strow + dir.first;
                    auto curcol = stcol + dir.second;
                    if (currow >=0 && currow < row && curcol >= 0 && curcol < col && !visited[currow][curcol])
                    {
                        if (mat[currow][curcol] != 0){
                            que.push({currow, curcol, next_layer});
                        }else{
                            return next_layer;
                        }
                    }
                }
            }
            return 0;
        };

        vector<vector<int>> result(row, vector<int>(col, 0));
        for (size_t i = 0; i < row; i++)
        {
            for (size_t j = 0; j < col; j++)
            {
                if (mat[i][j] != 0){
                    result[i][j] = _dfs(LayerIndex{i, j, 0});
                }
            }
        }
        return result;
    }


    vector<vector<int>> bfs(vector<vector<int>>& mat, size_t row, size_t col)
    {
        std::queue<std::pair<int, int>> que;
        vector<vector<int>> result(row, vector<int>(col, 0));
        std::deque<std::deque<bool>> visited(row,std::deque<bool>(col, false));
        for (size_t i = 0; i < row; i++)
        {
            for (size_t j = 0; j < col; j++)
            {
                if (mat[i][j] == 0){
                    que.emplace(i, j);
                    visited[i][j] = true;
                }
            }
        }

        while (!que.empty())
        {
            auto [strow, stcol] = que.front();
            que.pop();

            for (auto& dir : direction)
            {
                auto currow = strow + dir.first;
                auto curcol = stcol + dir.second; 
                if (currow >=0 && currow < row && curcol >= 0 && curcol < col && !visited[currow][curcol])
                {
                    if (mat[currow][curcol] != 0){
                        result[currow][curcol] = result[strow][stcol] + 1;
                        visited[currow][curcol] = true;
                        que.push({currow, curcol});
                    }
                }
            }
        }
        
        return result;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        const auto row = mat.size();
        const auto col = mat.at(0).size();
        return bfs(mat, row, col);
    }
};
// @lc code=end

