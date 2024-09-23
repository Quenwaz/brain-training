/*
 * @lc app=leetcode.cn id=460 lang=cpp
 *
 * [460] LFU 缓存
 */

// @lc code=start

#include <unordered_map>
#include <set>
#include <chrono>


struct CacheNodeCmp;
typedef struct CacheNode{
    CacheNode(int key, int value)
    : key(key), value(value), usecount(0)
#ifdef VER_1
     ,previous(nullptr), next(nullptr)
#else
    ,order(microseconds())
#endif
     
     {}

    int key;
    int value;

#ifdef VER_1
    CacheNode* previous;
    CacheNode* next;
#else
    uint64_t order;

    uint64_t microseconds(){
        return std::chrono::time_point_cast<std::chrono::microseconds>(std::chrono::system_clock::now()).time_since_epoch().count();
    }
#endif 

    void increase_usecount(){
        ++usecount;
#ifndef VER_1
        order = microseconds();
#endif
    }

private:
    int usecount;
    friend struct CacheNodeCmp;

}*CacheNodePtr;


struct CacheNodeCmp{
    bool operator()(const CacheNodePtr& lhs, const CacheNodePtr& rhs) const{
        if (lhs->usecount == rhs->usecount)
            return lhs->order < rhs->order;
        else return lhs->usecount < rhs->usecount;
    }
};



class LFUCache {
public:
    LFUCache(int capacity)
        : cache_capacity_(capacity)
        , cache_link_tail_(nullptr)
    {
    }

#ifdef VER_1
    void move_head(CacheNode* current_node)
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
            itr->second->increase_usecount();
            move_head(itr->second);
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
            itr->second->increase_usecount();
        }else{
            if (cache_map_table_.size() >= cache_capacity_){
                // 缓存满了
                pop_tail();
            }

            node = new CacheNode(key, value);
            node->increase_usecount();
            cache_map_table_.emplace(key, node);
            
            node->previous = cache_link_tail_;
            if (cache_link_tail_ != nullptr){
                cache_link_tail_->next = node;
            }
            cache_link_tail_ = node;
        }
        move_head(node);
    }
#else
    
    int get(int key) {
        auto itr = cache_map_table_.find(key);
        if (itr != cache_map_table_.end())
        {
            auto cnode = itr->second;
            sorted_cached_.erase(cnode);
            cnode->increase_usecount();
            sorted_cached_.insert(cnode);
            return cnode->value;
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {

        auto itr = cache_map_table_.find(key);
        if (itr != cache_map_table_.end())
        {
            auto cnode = itr->second;
            sorted_cached_.erase(cnode);
            cnode->value =value;
            cnode->increase_usecount();
            sorted_cached_.insert(cnode);

        }else{
            if (cache_map_table_.size() >= cache_capacity_){
                // 缓存满了
                const auto itersorted = sorted_cached_.begin();
                CacheNodePtr cnode  = *itersorted;
                cache_map_table_.erase(cnode->key);
                sorted_cached_.erase(cnode);
                delete cnode;
            }

            CacheNodePtr node = new CacheNode(key, value);
            node->increase_usecount();
            cache_map_table_.emplace(key, node);
            sorted_cached_.insert(node);
        }
    }

#endif //

private:
    size_t cache_capacity_;
    std::set<CacheNodePtr,CacheNodeCmp> sorted_cached_;
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

