/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
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

class LRUCache {
public:
    LRUCache(int capacity)
        : cache_capacity_(capacity)
        , cache_link_head_(nullptr)
        , cache_link_tail_(nullptr)
    {
    }
    
    ~LRUCache(){
        for(auto& item : cache_map_table_){
            delete item.second;
        }
    }

    int get(int key) {
        auto itr = cache_map_table_.find(key);
        if (itr != cache_map_table_.end())
        {
            move_to_head(itr->second);
            return itr->second->value;
        }else{
            return -1;
        }
    }
    
    
    void put(int key, int value) {
        auto itr = cache_map_table_.find(key);
        if (itr != cache_map_table_.end())
        {
            itr->second->value = value;
            move_to_head(itr->second);
        }else
        {
            if (cache_map_table_.size() >= cache_capacity_){
                // 缓存满了
                pop_link_tail_node();
            }

            CacheNodePtr node = new CacheNode(key, value);
            cache_map_table_.emplace(key, node);
            node->next = cache_link_head_;
            if (cache_link_head_ != nullptr)
                cache_link_head_->previous = node;
            cache_link_head_ = node;

            if (cache_link_tail_ == nullptr){
                cache_link_tail_ = cache_link_head_;
                cache_link_tail_->next = nullptr;
            }
        }
        
    }

private:
    void pop_link_tail_node(){
        if (cache_link_tail_ == nullptr){
            return;
        }

        auto itr = cache_map_table_.find(cache_link_tail_->key);
        if (itr == cache_map_table_.end())
        {
            return;
        }

        cache_link_tail_ = cache_link_tail_->previous;
        if (cache_link_tail_ != nullptr){
            cache_link_tail_->next = nullptr;
        }else{
            cache_link_head_ = nullptr;
        }

        delete itr->second;
        cache_map_table_.erase(itr);
    }

    void move_to_head(CacheNodePtr node){
        if (node == cache_link_head_){
            return;
        }

        if (node == cache_link_tail_)
        {
            cache_link_tail_->next = cache_link_head_;
            cache_link_head_->previous = cache_link_tail_;
            
            cache_link_head_ = cache_link_tail_;

            cache_link_tail_ = cache_link_tail_->previous;
            cache_link_tail_->next = nullptr;
            cache_link_head_->previous = nullptr;

        }else{
            node->previous->next = node->next;
            node->next->previous = node->previous;
            node->next = cache_link_head_;
            cache_link_head_->previous = node;
            node->previous = nullptr;
            cache_link_head_ = node;  
        }
    }

private:
    size_t cache_capacity_;
    std::unordered_map<int, CacheNodePtr> cache_map_table_;
    CacheNodePtr cache_link_head_;
    CacheNodePtr cache_link_tail_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

