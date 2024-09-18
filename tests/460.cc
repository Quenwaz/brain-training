#include "gtest/gtest.h"
#include "460.lfu.cpp"

TEST(lfucache_test, t1)
{
    LFUCache* lfu_cache = new LFUCache(2);
    lfu_cache->put(1,1);
    lfu_cache->put(2,2);
    ASSERT_EQ(lfu_cache->get(1),1);
    lfu_cache->put(3,3);
    ASSERT_EQ(lfu_cache->get(2),-1);
    ASSERT_EQ(lfu_cache->get(3),3);
    lfu_cache->put(4,4);
    ASSERT_EQ(lfu_cache->get(1),-1);
    ASSERT_EQ(lfu_cache->get(3),3);
    ASSERT_EQ(lfu_cache->get(4),4);
    delete lfu_cache;
}


TEST(lfucache_test, t2)
{
    LFUCache* lfu_cache = new LFUCache(3);
    lfu_cache->put(2,2);
    lfu_cache->put(1,1);
    ASSERT_EQ(lfu_cache->get(2),2);
    ASSERT_EQ(lfu_cache->get(1),1);
    ASSERT_EQ(lfu_cache->get(2),2);
    lfu_cache->put(3,3);
    lfu_cache->put(4,4);

    ASSERT_EQ(lfu_cache->get(3),-1);
    ASSERT_EQ(lfu_cache->get(2),2);
    ASSERT_EQ(lfu_cache->get(1),1);
    ASSERT_EQ(lfu_cache->get(4),4);
    delete lfu_cache;
}


TEST(lfucache_test, t3)
{
    LFUCache* lfu_cache = new LFUCache(2);
    lfu_cache->put(3,1);
    lfu_cache->put(2,1);
    lfu_cache->put(2,2);
    lfu_cache->put(4,4);
    ASSERT_EQ(lfu_cache->get(2),2);
    delete lfu_cache;
}



TEST(lfucache_test, t4)
{
    LFUCache* lfu_cache = new LFUCache(1);
    lfu_cache->put(2,1);
    ASSERT_EQ(lfu_cache->get(2),1);
    lfu_cache->put(3,2);
    ASSERT_EQ(lfu_cache->get(2),-1);
    ASSERT_EQ(lfu_cache->get(3),2);
    delete lfu_cache;
}


TEST(lfucache_test, t5)
{
    LFUCache* lfu_cache = new LFUCache(2);
    lfu_cache->put(2,1);
    lfu_cache->put(1,1);
    lfu_cache->put(2,3);
    lfu_cache->put(4,1);
    ASSERT_EQ(lfu_cache->get(1),-1);
    ASSERT_EQ(lfu_cache->get(2),3);
    delete lfu_cache;
}



