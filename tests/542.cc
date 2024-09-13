/**
问题：
给定一个由 0 和 1 组成的矩阵 mat ，请输出一个大小相同的矩阵，其中每一个格子是 mat 中对应位置元素到最近的 0 的距离。

两个相邻元素间的距离为 1 。


理解：
1. 找出所有是1的项距离0的曼哈顿距离， 如果当前项为0， 则距离为0无需查找


> 最初的解法是想通过深度优先搜索的思路找距离1最近的0
> 之后作弊了， 偷偷看了别人的解法， 很有启发。 是通过广度优先搜索的算法。 首先通过0找1， 被找到的1继续入队找下一个1。
> 结论:
>   逆向思维， 1找0 很难， 0找1很容易
 */

#include "gtest/gtest.h"
#include "542.01-matrix.cpp"

TEST(integerReversal_test, t1)
{
    Solution sol;

    std::vector<std::vector<int>> i1{
        {0,0,0},
        {0,1,0},
        {0,0,0}
    };
    ASSERT_EQ(i1,sol.updateMatrix(i1));

    std::vector<std::vector<int>> i2{{0,1,0,1,1},{1,1,0,0,1},{0,0,0,1,0},{1,0,1,1,1},{1,0,0,0,1}};
    std::vector<std::vector<int>> r2{{0,1,0,1,2},{1,1,0,0,1},{0,0,0,1,0},{1,0,1,1,1},{1,0,0,0,1}};
    ASSERT_EQ(r2,sol.updateMatrix(i2));


    std::vector<std::vector<int>> i3{
        {1,0,1,1,0,0,1,0,0,1},
        {0,1,1,0,1,0,1,0,1,1},
        {0,0,1,0,1,0,0,1,0,0},
        {1,0,1,0,1,1,1,1,1,1},
        {0,1,0,1,1,0,0,0,0,1},
        {0,0,1,0,1,1,1,0,1,0},
        {0,1,0,1,0,1,0,0,1,1},
        {1,0,0,0,1,1,1,1,0,1},
        {1,1,1,1,1,1,1,0,1,0},
        {1,1,1,1,0,1,0,0,1,1}
    };
    std::vector<std::vector<int>> r3{{1,0,1,1,0,0,1,0,0,1},{0,1,1,0,1,0,1,0,1,1},{0,0,1,0,1,0,0,1,0,0},{1,0,1,0,1,1,1,1,1,1},{0,1,0,1,1,0,0,0,0,1},{0,0,1,0,1,1,1,0,1,0},{0,1,0,1,0,1,0,0,1,1},{1,0,0,0,1,2,1,1,0,1},{2,1,1,1,1,2,1,0,1,0},{3,2,2,1,0,1,0,0,1,1}};
    std::vector<std::vector<int>> r4{{1,0,1,1,0,0,1,0,0,1},{0,1,1,0,1,0,1,0,1,1},{0,0,1,0,1,0,0,1,0,0},{1,0,1,0,1,1,1,1,1,1},{0,1,0,1,1,0,0,0,0,1},{0,0,1,0,1,1,1,0,1,0},{0,1,0,1,0,1,0,0,1,1},{1,0,0,0,1,2,1,1,0,1},{2,1,1,1,1,2,1,0,1,0},{4,3,2,1,0,1,0,0,1,1}};
    ASSERT_EQ(r3,sol.updateMatrix(i3));
}

