/*
 * @lc app=leetcode.cn id=460 lang=cpp
 *
 * [460] LFU 缓存
 */

// @lc code=start

#include <unordered_map>

typedef struct CacheNode{
    CacheNode(int key, int value)
    : key(key), value(value), usecount(0), previous(nullptr), next(nullptr){}

    int key;
    int value;
    int usecount;
    CacheNode* previous;
    CacheNode* next;
}*CacheNodePtr;

class LFUCache {
public:
    LFUCache(int capacity)
        : cache_capacity_(capacity)
        , cache_link_tail_(nullptr)
    {
    }

    void move_forward(CacheNode* current_node)
    {
        auto pos = current_node, prev = pos->previous;
        for(;prev != nullptr && prev->usecount <= pos->usecount; )
        {
            if (pos == cache_link_tail_)
                cache_link_tail_ = prev;

            prev->next = pos->next;
            pos->previous = prev->previous;
            prev->previous = pos;
            pos->next = prev;

            if (pos->previous == nullptr){
                break;
            }

            pos = pos->previous;
            prev = pos->previous;
        }
    }
    
    int get(int key) {
        auto itr = cache_map_table_.find(key);
        if (itr != cache_map_table_.end())
        {
            itr->second->usecount += 1;
            move_forward(itr->second);
            return itr->second->value;
        }else{
            return -1;
        }
    }

    void pop_tail(){
        auto itr = cache_map_table_.find(cache_link_tail_->key);
        if (itr == cache_map_table_.end())
        {
            return;
        }
        cache_link_tail_ = cache_link_tail_->previous;
        if (cache_link_tail_ != nullptr)
            cache_link_tail_->next = nullptr;
        delete itr->second;
        cache_map_table_.erase(itr);
    }
    
    void put(int key, int value) {
        CacheNodePtr node  = nullptr;
        auto itr = cache_map_table_.find(key);
        if (itr != cache_map_table_.end())
        {
            node = itr->second;
            itr->second->value = value;
            itr->second->usecount += 1;
        }else{
            if (cache_map_table_.size() >= cache_capacity_){
                // 缓存满了
                pop_tail();
            }

            node = new CacheNode(key, value);
            cache_map_table_.emplace(key, node);
            node->previous = cache_link_tail_;
            if (cache_link_tail_ != nullptr){
                cache_link_tail_->next = node;
            }
            cache_link_tail_ = node;
        }
        move_forward(node);
    }

private:
    size_t cache_capacity_;
    std::unordered_map<int, CacheNodePtr> cache_map_table_;
    CacheNodePtr cache_link_tail_;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

