#define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING

#include "../Queue/TQueue.h"
#include "gtest.h"
TEST(TLQueue, can_create_queue_with_positive_size)
{
    
    ASSERT_NO_THROW(TLQueue<int> q);
}
TEST(TLQueue, new_queue_is_empty)
{
   
    TLQueue<int> q;
    EXPECT_EQ(1, q.empty());
}
TEST(TLQueue, can_copy)
{
   
    TLQueue<int> q;
    q.Push(1);
    q.Push(2);
    q.Push(3);
    ASSERT_NO_THROW(TLQueue<int> q1(q));
    
}
TEST(TLQueue, copied_queue_is_equal_to_source_one)
{
    
    TLQueue<int> q;
    q.Push(1);
    q.Push(2);
    q.Push(3);
    ASSERT_NO_THROW(TLQueue<int> q1(q));
    TLQueue<int> q1(q);
    EXPECT_EQ(1, q == q1);
}
TEST(TLQueue, right_true_equal_queues)
{
    
    TLQueue<int> q;
    q.Push(1);
    q.Push(2);
    q.Push(3);
    TLQueue<int> q1;
    q1.Push(1);
    q1.Push(2);
    q1.Push(3);
    EXPECT_EQ(1, q == q1);
}
TEST(TLQueue, right_false_equal_queues)
{
   
    TLQueue<int> q;
    q.Push(1);
    q.Push(2);
    TLQueue<int> q1;
    q1.Push(1);
    q1.Push(1);
    q1.Push(1);
    EXPECT_EQ(1, q != q1);
}
TEST(TLQueue, can_push)
{
    
    TLQueue<int> q;
    int a1 = 1;
    int a2 = 2;
  
   
    q.Push(a1);
    q.Push(a2);
   
    EXPECT_EQ(a1, q.Pop());
    EXPECT_EQ(a2, q.Pop());
   
}
TEST(TLQueue, can_pop)
{
    
    TLQueue<int> q;
    int a1 = 1;
    int a2 = 2;
   
    q.Push(a1);
    q.Push(a2);
  
    int b1, b2;
    ASSERT_NO_THROW(b1 = q.Pop());
    ASSERT_NO_THROW(b2 = q.Pop());
   
    EXPECT_EQ(a1, b1);
    EXPECT_EQ(a2, b2);
   
}
TEST(TLQueue, throws_when_use_pop_on_empty_queue)
{
    
    TLQueue<int> q;
    ASSERT_ANY_THROW(q.Pop());
}
TEST(TLQueue, can_use_front)
{
    TLQueue<int> q;
    q.Push(1);
    q.Push(2);
    int a1;
    ASSERT_NO_THROW(a1 = q.Front());
   
    EXPECT_EQ(a1, 1);
}
TEST(TLQueue, can_use_back)
{
    TLQueue<int> q;
    q.Push(1);
    q.Push(2);
    int  a2;
    
    ASSERT_NO_THROW(a2 = q.Back());
    EXPECT_EQ(2, a2);
}
TEST(TLQueue, throws_when_use_front_on_empty_queue)
{
    
    TLQueue<int> q;
    ASSERT_ANY_THROW(q.Front());
    
}
TEST(TLQueue, throws_when_use_back_on_empty_queue)
{
    
    TLQueue<int> q;
   
    ASSERT_ANY_THROW(q.Back());
}
TEST(TLQueue, Empty_on_empty_queue)
{
   
    TLQueue<int> q;
    bool a1 = q.empty();
    EXPECT_EQ(1, a1);
}
TEST(TLQueue, false_Empty_on_not_empty_queue)
{
    
    TLQueue<int> q;
    q.Push(1);
    q.Push(1);
    bool a1 = q.empty();
    EXPECT_EQ(0, a1);
}
TEST(TLQueue, can_get_size_queue)
{
    
    TLQueue<int> q;
    q.Push(1);
    q.Push(1);
    EXPECT_EQ(2, q.size_queue());
}
