/*
 * @lc app=leetcode.cn id=542 lang=cpp
 *
 * [542] 01 矩阵
 */

// @lc code=start

#include <vector>

using namespace std;
class Solution {
public:

    int search(size_t row, size_t col, const vector<vector<int>>& mat)
    {
        int t=0,b=0,l=0,r =0;
        for(int stopc = 0;stopc<4;){
            stopc = 0;
            if ((row - t)> 0)
                t+=1;
            else stopc +=1;

            int cr= row-t, cc = col;
            if (cr>=0 && mat[cr][cc] == 0){
                return t;
            }

            if ((row + b) < (mat.size()-1))
                b +=1;
            else stopc +=1;

            cr = row + b; 
            if (cr < mat.size() && mat[cr][cc] == 0){
                return b;
            }

            if ((col -l) > 0)
                l +=1;
            else stopc +=1;

            cr = row; cc = col-l;
            if (cc >= 0 && mat[cr][cc] == 0){
                return l;
            }

            if ((col + r) < (mat[row].size()-1))
                r +=1;
            else stopc +=1;

            cr = row; cc = col+r;
            if (cc < mat[cr].size() && mat[cr][cc] == 0){
                return r;
            }

            cr = row-t; cc = col-l;
            if (mat[cr][cc] == 0){
                return t + l;
            }

            cr = row-t; cc = col+r;
            if (mat[cr][cc] == 0){
                return t + r;
            }

            cr = row+b; cc = col-l;
            if (mat[cr][cc] == 0){
                return b + l;
            }

            cr = row+b; cc = col+r;
            if (mat[cr][cc] == 0){
                return b + r;
            }
        }

        return -1;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> result;
        result.resize(mat.size());
        for (size_t r = 0; r < mat.size(); ++r)
        {
            const size_t len_of_col = mat.at(r).size();
            result[r].resize(len_of_col);
            for(size_t c = 0; c < mat.at(r).size(); ++c)
            {
                auto& val = mat.at(r).at(c);
                if (val == 0){
                    result[r][c] = 0;
                    continue;
                }

                result[r][c] = search(r,c, mat);
            }
        }
        return result;
    }
};
// @lc code=end

