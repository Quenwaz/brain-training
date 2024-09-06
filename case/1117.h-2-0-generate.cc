/*
 * @lc app=leetcode.cn id=1117 lang=cpp
 *
 * [1117] H2O 生成
 */
#include <functional>
#include <queue>
#include <thread>
#include <condition_variable>
#include <mutex>
// #define SOLUTION_0
// @lc code=start
class H2O {
public:
    H2O() {
        hydrogen_ = 0;
#ifdef  SOLUTION_0
        oxygen_ = 0;
#endif
    }

    void hydrogen(std::function<void()> releaseHydrogen) {
#ifdef  SOLUTION_0
        {
            std::unique_lock<std::mutex> lock(mtx_);
            hydrogen_ +=1;
            cv_.wait(lock, [&](){
                return queue_.empty()? (oxygen_ >= 1 && hydrogen_ >= 1) : queue_.front() == 'H';
            });
            hydrogen_ -=1;
            if (queue_.empty()){
                queue_.push('H');
                queue_.push('O');
            }
            else if (queue_.front() == 'H')
                queue_.pop();

            // releaseHydrogen() outputs "H". Do not change or remove this line.
            releaseHydrogen();
        }
        cv_.notify_all();
#else
        {
            std::unique_lock<std::mutex> lock(mtx_);
            cv_.wait(lock, [&](){
                return hydrogen_ < 2;
            });
            hydrogen_ += 1;
            // releaseHydrogen() outputs "H". Do not change or remove this line.
            releaseHydrogen();
        }
        cv_.notify_all();
#endif
    }

    void oxygen(std::function<void()> releaseOxygen) {
#ifdef  SOLUTION_0
        {
            std::unique_lock<std::mutex> lock(mtx_);
            oxygen_ +=1;
            cv_.wait(lock, [&](){
                return queue_.empty()? hydrogen_ >= 2 : queue_.front() == 'O';
            });
            oxygen_ -=1;
           if (queue_.empty()){
                queue_.push('H');
                queue_.push('H');
            }
            else if (queue_.front() == 'O')
                queue_.pop();

            // releaseOxygen() outputs "O". Do not change or remove this line.
            releaseOxygen();
        }
        cv_.notify_all();
#else
        {
            std::unique_lock<std::mutex> lock(mtx_);
            cv_.wait(lock, [&](){
                return hydrogen_ == 2;
            });
            hydrogen_ = 0;
            // releaseOxygen() outputs "O". Do not change or remove this line.
            releaseOxygen();
        }
        cv_.notify_all();
#endif
    }

private:
    int hydrogen_;
#ifdef  SOLUTION_0
    int oxygen_;
    std::queue<char> queue_;
#endif
    std::mutex mtx_;
    std::condition_variable cv_;
};
// @lc code=end

