#include "utmatrix.h"

#include <gtest/gtest.h>

TEST(TVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
  ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
  TVector<int> v(10);

  ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
	int s = 8;
	TVector<int> v1(s);
	for (int i = 0; i < 8; i++)
		v1[i] = i + 1;
	TVector<int> v2 = v1;
	EXPECT_EQ(v1, v2);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
	int s = 8;
	TVector<int> v1(s);
	for (int i = 0; i < 8; i++)
	{
		v1[i] = i + 1;
	}
	TVector<int> v2 = v1;
	v1[0] = v1[0] + 1;
	EXPECT_NE(v1, v2);
}

TEST(TVector, can_get_size)
{
  TVector<int> v(4);

  EXPECT_EQ(4, v.GetSize());
}

TEST(TVector, can_get_start_index)
{
  TVector<int> v(4, 2);

  EXPECT_EQ(2, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
  TVector<int> v(4);
  v[0] = 4;

  EXPECT_EQ(4, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
	TVector<int> v(4);
	ASSERT_ANY_THROW(v[-1] = 4);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	TVector<int>v(4);
	ASSERT_ANY_THROW(v[4] = 4);
}

TEST(TVector, can_assign_vector_to_itself)
{
	TVector<int>v(4);
	v[3] = 1;
	v[2] = 1;
	ASSERT_NO_THROW(v = v);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
	int s = 5;
	TVector<int> v1(s), v2(s);
	v1[2] = 5, v1[3] = 4, v1[0] = 5;
	v2 = v1;
	EXPECT_EQ(v1, v2);
}

TEST(TVector, assign_operator_change_vector_size)
{
	int s1 = 5, s2 = 8;
	TVector<int> v1(s1), v2(s2);
	for (int i = 0; i < s1; i++)
		v1[i] = i;
	v2 = v1;
	EXPECT_EQ(s1, v2.GetSize());
}

TEST(TVector, can_assign_vectors_of_different_size)
{
	int s1 = 6, s2 = 3;
	TVector<int> v1(s1), v2(s2);
	for (int i = 0; i < s1; i++)
		v1[i] = i + 1;
	v2 = v1;
	EXPECT_EQ(v1, v2);
}

TEST(TVector, compare_equal_vectors_return_true)
{
	int s = 6;
	TVector<int> v1(s), v2(s);
	for (int i = 0; i < s; i++)
		v1[i] = v2[i] = i + 1;
	EXPECT_TRUE(v1 == v2);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
	int s = 6;
	TVector<int> v1(s);
	for (int i = 0; i < s; i++)
		v1[i] = 6 - i;
	EXPECT_TRUE(v1 == v1);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	int s1 = 3, s2 = 6;
	TVector<int> v1(s1), v2(s2);
	for (int i = 0; i < s1; i++)
	{
		v1[i] = i;
	}
	for (int i = 0; i < s2; i++)
	{
		v2[i] = i;
	}
	EXPECT_FALSE(v1 == v2);
}

TEST(TVector, can_add_scalar_to_vector)
{
	int s = 7;
	TVector<int> v(s), ans(s), expans(s);
	int val = 5;
	for (int i = 0; i < s; i++)
	{
		v[i] = i + 3;
		expans[i] = i + 3 + val;
	}
	ans = v + val;
	EXPECT_EQ(ans, expans);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
	int s = 7;
	TVector<int> v(s), ans(s), expans(s);
	int val = 5;
	for (int i = 0; i < s; i++)
	{
		v[i] = i + 3;
		expans[i] = i + 3 - val;
	}
	ans = v - val;
	EXPECT_EQ(ans, expans);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
	int s = 7;
	TVector<int> v(s), ans(s), expans(s);
	int val = 5;
	for (int i = 0; i < s; i++)
	{
		v[i] = i + 3;
		expans[i] = (i + 3) * val;
	}
	ans = v * val;
	EXPECT_EQ(ans, expans);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	int s = 7;
	TVector<int> v1(s), v2(s), ans(s), expans(s);
	for (int i = 0; i < s; i++)
	{
		v1[i] = v2[i] = i;
		expans[i] = 2*i;
	}
	ans = v1 + v2;
	EXPECT_EQ(ans, expans);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	int s1 = 7, s2 = 5;
	TVector<int> v1(s1), v2(s2);
	EXPECT_ANY_THROW(v1+v2);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	int s = 7;
	TVector<int> v1(s), v2(s), ans(s), expans(s);
	for (int i = 0; i < s; i++)
	{
		v1[i] = 2 * i;
		v2[i] = i;
		expans[i] = i;
	}
	ans = v1 - v2;
	EXPECT_EQ(ans, expans);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	int s1 = 7, s2 = 5;
	TVector<int> v1(s1), v2(s2);
	EXPECT_ANY_THROW(v1 - v2);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	int s = 7;
	TVector<int> v1(s), v2(s);
	int ans = 0, expans = 0;
	for (int i = 0; i < s; i++)
	{
		v1[i] = v2[i] = i;
		expans += i * i;
	}
	ans = v1 * v2;
	EXPECT_EQ(ans, expans);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	int s1 = 7, s2 = 5;
	TVector<int> v1(s1), v2(s2);
	EXPECT_ANY_THROW(v1 * v2);
}

