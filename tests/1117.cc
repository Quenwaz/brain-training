/**
现在有两种线程，氧 oxygen 和氢 hydrogen，你的目标是组织这两种线程来产生水分子。

存在一个屏障（barrier）使得每个线程必须等候直到一个完整水分子能够被产生出来。

氢和氧线程会被分别给予 releaseHydrogen 和 releaseOxygen 方法来允许它们突破屏障。

这些线程应该三三成组突破屏障并能立即组合产生一个水分子。

你必须保证产生一个水分子所需线程的结合必须发生在下一个水分子产生之前。

换句话说:

- 如果一个氧线程到达屏障时没有氢线程到达，它必须等候直到两个氢线程到达。
- 如果一个氢线程到达屏障时没有其它线程到达，它必须等候直到一个氧线程和另一个氢线程到达。
书写满足这些限制条件的氢、氧线程同步代码。


> 最初的解法安装题目顺向思维， 针对hydrogen与oxygen线程分别处理， 满足条件则释放。 
> 另一种更好的解法就是， 一旦释放了两个hydrogen， 就释放一个oxygen。
> 结论:
>   理解题目的思路不一样， 解法就会不同
 */

#include "gtest/gtest.h"
#include "1117.h-2-0-generate.cc"

TEST(H2O_test, t1)
{
    H2O s;

    std::string water = "OOHHHH";
    std::vector <std::thread> ths;
    for (auto ch : water)
    {
        std::function<void(std::function<void()>)> thread_call;
        if (ch == 'H'){
            thread_call = std::bind(&H2O::hydrogen, &s, std::placeholders::_1);
        }else{
            thread_call = std::bind(&H2O::oxygen, &s, std::placeholders::_1);
        }   

        ths.emplace_back(std::thread(thread_call, [ch](){
            fprintf(stdout, std::string(1,ch).c_str());
        }));
    }

    for (auto &th: ths) th.join();
    
    ASSERT_EQ(0,0);
    // ASSERT_EQ(outputMatrix, sol.transpose(inputMatrix));
}

