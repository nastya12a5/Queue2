#include "../Queue/TQueue.h"
#include "gtest.h"

TEST(TQueue, can_create_queue_with_positive_size)
{
    ASSERT_NO_THROW(TQueue<int> q(5));
}

TEST(TQueue, throws_when_create_queue_with_negative_size)
{
	ASSERT_ANY_THROW(TQueue<int> q(-5));
}

TEST(TQueue, can_create_copi_queue)
{
	TQueue<int> q(5);
	
	ASSERT_NO_THROW(TQueue<int> q1(q));
}

TEST(TQueue, copied_queue_is_equal_to_source_one)
{
	TQueue<int> q(5);
	int i = 1;
	while (!(q.full()))
	{
		q.Push(i);
		i++;
	}
	TQueue<int> q1(q);
	while (!(q.empty()) && !(q1.empty()))
	{
		EXPECT_EQ(q.Pop(), q1.Pop());
	}
}

TEST(TQueue, copied_queue_has_its_own_memory)
{
	TQueue<int> q(5);
	int i = 1;
	while (!(q.full()))
	{
		q.Push(i);
		i++;
	}
	TQueue<int> q1(q);
	EXPECT_EQ(0, &q == &q1);
}

TEST(TQueue, can_correct_two_equal_queues)
{
	TQueue<int> q(4);
	int i = 3;
	while (!(q.full()))
	{
		q.Push(i);
	}
	TQueue<int> q1(4);
	int k = 3;
	while (!(q1.full()))
	{
		q1.Push(k);
	}
	EXPECT_EQ(true, q==q1);
}

TEST(TQueue, can_correct_two_not_equal_queues)
{
	TQueue<int> q(5);
	int i = 1;
	while (!(q.full()))
	{
		q.Push(i);
	}
	TQueue<int> q1(5);
	int k = 1;
	while (!(q1.full()))
	{
		q1.Push(k+1);
	}
	EXPECT_EQ(true, q != q1);
}




TEST(TQueue, new_queue_is_empty)
{
	TQueue<int> q(5);
	EXPECT_EQ(true, q.empty());
}

TEST(TQueue, no_empty_queue_is_not_empty)
{
	TQueue<int> q(5);
	q.Push(1);
	q.Push(2);
	EXPECT_EQ(false, q.empty());
}

TEST(TQueue, full_queue_is_full)
{
	TQueue<int> q(5);
	int i = 1;
	while (!(q.full()))
	{
		q.Push(i);
	}
	EXPECT_EQ(true, q.full());
}

TEST(TQueue, not_full_queue_is_not_full)
{
	TQueue<int> q(5);
	q.Push(1);
	q.Push(2);
	EXPECT_EQ(false, q.full());
}

TEST(TQueue, throws_when_output_empty_queue)
{
	TQueue<int> q(5);
	ASSERT_ANY_THROW(q.output());
}

TEST(TQueue, can_push)
{
	TQueue<int> q(5);
	ASSERT_NO_THROW(q.Push(1));
}

TEST(TQueue, can_pop)
{
	TQueue<int> q(5);
	q.Push(1);
	ASSERT_NO_THROW(q.Pop());
}

TEST(TQueue, cant_push_to_full_queue)
{
	TQueue<int> q(5);
	int i = 1;
	while (!(q.full()))
	{
		q.Push(i);
	}
	ASSERT_ANY_THROW(q.Push(1));
}

TEST(TQueue, cant_pop_from_empty_queue)
{
	TQueue<int> q(5);
	ASSERT_ANY_THROW(q.Pop());
}

TEST(TQueue, cant_get_front_from_empty_stack)
{
	TQueue<int> q(5);
	ASSERT_ANY_THROW(q.front());
}

TEST(TQueue, can_get_right_front)
{
	TQueue<int> q(5);
	q.Push(1);
	q.Push(2);
	EXPECT_EQ(1, q.front());
}

TEST(TQueue, cant_get_back_from_empty_stack)
{
	TQueue<int> q(5);
	ASSERT_ANY_THROW(q.back());
}

TEST(TQueue, can_get_right_back)
{
	TQueue<int> q(5);
	q.Push(1);
	q.Push(2);
	EXPECT_EQ(2, q.back());
}

TEST(TQueue, can_get_right_head_index)
{
	TQueue<int> q(5);
	q.Push(1);
	q.Push(2);
	int tmp = q.Pop();
	EXPECT_EQ(1, q.GetHeadIndex());
}

TEST(TQueue, can_get_right_current_size)
{
	TQueue<int> q(5);
	q.Push(0);
	q.Push(1);
	q.Push(2);
	int tmp = q.Pop();
	EXPECT_EQ(2, q.GetCurrentSize());
}

TEST(TQueue, can_get_right_max_size)
{
	TQueue<int> q(5);
	EXPECT_EQ(5, q.GetMaxSize());
}