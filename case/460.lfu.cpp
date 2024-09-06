/*
 * @lc app=leetcode.cn id=460 lang=cpp
 *
 * [460] LFU 缓存
 */

// @lc code=start

#include <unordered_map>

typedef struct CacheNode{
    CacheNode(int key, int value)
    : key(key), value(value), previous(nullptr), next(nullptr){}

    int key;
    int value;
    CacheNode* previous;
    CacheNode* next;
}*CacheNodePtr;

class LFUCache {
public:
    LFUCache(int capacity)
        : cache_capacity_(capacity)
        , cache_link_head_(nullptr)
        , cache_link_tail_(nullptr)
    {
    }
    
    int get(int key) {
        auto itr = cache_map_table_.find(key);
        if (itr != cache_map_table_.end())
        {
            if (itr->second == cache_link_tail_){
                cache_link_tail_->previous->next = nullptr;
                cache_link_tail_ = cache_link_tail_->previous;
            }

            if(itr->second != cache_link_head_){
                itr->second->next = cache_link_head_;
                cache_link_head_->previous = itr->second;
                cache_link_head_ = itr->second;  
                cache_link_head_->previous =nullptr;
            }

            return itr->second->value;
        }else{
            return -1;
        }

    }

    void pop_tail_node(){
        auto itr = cache_map_table_.find(cache_link_tail_->key);
        if (itr == cache_map_table_.end())
        {
            return;
        }
        cache_link_tail_->previous->next = nullptr;
        cache_link_tail_ = cache_link_tail_->previous;
        delete itr->second;
        cache_map_table_.erase(itr);
    }
    
    void put(int key, int value) {
        auto itr = cache_map_table_.find(key);
        if (itr != cache_map_table_.end())
        {
            itr->second->value = value;
        }else{
            if (cache_map_table_.size() >= cache_capacity_){
                // 缓存满了
                pop_tail_node();
            }

            CacheNodePtr node = new CacheNode(key, value);
            cache_map_table_.emplace(key, node);
            node->next = cache_link_head_;
            if (cache_link_head_ != nullptr)
                cache_link_head_->previous = node;
            cache_link_head_ = node;

            if (cache_link_tail_ == nullptr){
                cache_link_tail_ = cache_link_head_;
            }
        }
        
    }

private:
    size_t cache_capacity_;
    std::unordered_map<int, CacheNodePtr> cache_map_table_;
    CacheNodePtr cache_link_head_;
    CacheNodePtr cache_link_tail_;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

