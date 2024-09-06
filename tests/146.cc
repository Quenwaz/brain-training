#include "gtest/gtest.h"
#include "146.lru.cpp"

TEST(lrucache_test, t1)
{
    LRUCache* lRUCache = new LRUCache(2);
    lRUCache->put(1,1);
    lRUCache->put(2,2);
    ASSERT_TRUE(lRUCache->get(1),1);
    lRUCache->put(3,3);
    ASSERT_TRUE(lRUCache->get(2),2);
    lRUCache->put(4,4);
    ASSERT_TRUE(lRUCache->get(1),-1);
    lRUCache->get(3);
    lRUCache->get(4);
    delete lRUCache;
}


TEST(lrucache_test, t2)
{
    LRUCache* lRUCache = new LRUCache(3);
    lRUCache->put(1,1);
    lRUCache->put(2,2);
    lRUCache->put(3,3);
    lRUCache->put(4,4);
    ASSERT_TRUE(lRUCache->get(4),4);
    ASSERT_TRUE(lRUCache->get(3),3);
    ASSERT_TRUE(lRUCache->get(2),2);
    ASSERT_TRUE(lRUCache->get(1),-1);
    lRUCache->put(5,5);
    ASSERT_TRUE(lRUCache->get(1),-1);
    ASSERT_TRUE(lRUCache->get(2),2);
    ASSERT_TRUE(lRUCache->get(3),3);
    ASSERT_TRUE(lRUCache->get(4),-1);
    ASSERT_TRUE(lRUCache->get(5),5);
    delete lRUCache;
}

TEST(lrucache_test, t3)
{
    LRUCache* lRUCache = new LRUCache(10);
    lRUCache->put(10,13);
    lRUCache->put(3,17);
    lRUCache->put(6,11);
    lRUCache->put(10,5);
    lRUCache->put(9,10);
    ASSERT_TRUE(lRUCache->get(13),-1);
    lRUCache->put(2,19);
    ASSERT_TRUE(lRUCache->get(2),19);
    ASSERT_TRUE(lRUCache->get(3),17);
    lRUCache->put(5,25);
    ASSERT_TRUE(lRUCache->get(8),-1);
    lRUCache->put(9,22);
    lRUCache->put(5,5);
    lRUCache->put(1,30);
    delete lRUCache;
}