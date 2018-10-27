#include "utmatrix.h"

#include <gtest/gtest.h>

TEST(TVector, can_add_three_vectors_with_equal_size_MY_TEST)
{
	int s = 7;
	TVector<int> v1(s), v2(s), v3(s), ans(s), expans(s);
	for (int i = 0; i < s; i++)
	{
		v1[i] = v2[i] = v3[i] = i;
		expans[i] = 3 * i;
	}
	ans = v1 + v2 + v3;
	EXPECT_EQ(ans, expans);
}

TEST(TVector, can_subtract_three_vectors_with_equal_size_MY_TEST)
{
	int s = 7;
	TVector<int> v1(s), v2(s), v3(s), ans(s), expans(s);
	for (int i = 0; i < s; i++)
	{
		v1[i] = 3 * i;
		v2[i] = v3[i] = i;
		expans[i] = i;
	}
	ans = v1 - v2 - v3;
	EXPECT_EQ(ans, expans);
}

TEST(TVector, operator_not_equal_return_false_with_equal_vectors_MY_TEST)
{
	int s = 6;
	TVector<int> v1(s), v2(s);
	for (int i = 0; i < s; i++)
		v1[i] = v2[i] = i + 1;
	EXPECT_FALSE(v1 != v2);
}

TEST(TVector, cant_add_vectors_with_equal_start_index_and_non_equal_size_MY_TEST)
{
	int s1 = 7, s2 = 5;
	int st1 = 3, st2 = 3;
	TVector<int> v1(s1, st1), v2(s2, st2);
	EXPECT_ANY_THROW(v1 + v2);
}

TEST(TVector, cant_subtract_vectors_with_equal_start_index_and_non_equal_size_MY_TEST)
{
	int s1 = 7, s2 = 5;
	int st1 = 3, st2 = 3;
	TVector<int> v1(s1, st1), v2(s2, st2);
	EXPECT_ANY_THROW(v1 - v2);
}

TEST(TMatrix, can_add_three_matrix_with_equal_size_MY_TEST)
{
	int s = 7;
	TMatrix<int>m1(s), m2(s), m3(s), ans(s), expans(s);
	for (int i = 0; i < s; i++)
		for (int j = i; j < s; j++)
		{
			m1[i][j] = i * j;
			m2[i][j] = 2 * i * j;
			m3[i][j] = 3 * i * j;
			expans[i][j] = 6 * i * j;
		}
	ans = m1 + m2 + m3;
	EXPECT_EQ(ans, expans);
}

TEST(TMatrix, can_subtract_three_matrix_with_equal_size_MY_TEST)
{
	int s = 7;
	TMatrix<int>m1(s), m2(s), m3(s), ans(s), expans(s);
	for (int i = 0; i < s; i++)
		for (int j = i; j < s; j++)
		{
			m1[i][j] = 6 * i * j;
			m2[i][j] = 2 * i * j;
			m3[i][j] = 3 * i * j;
			expans[i][j] =  i * j;
		}
	ans = m1 - m2 - m3;
	EXPECT_EQ(ans, expans);
}

TEST(TMatrix, operator_not_equal_return_false_with_equal_matrix_MY_TEST)
{
	int s = 6;
	TMatrix<int>m(s);
	for (int i = 0; i < s; i++)
		for (int j = i; j < s; j++)
			m[i][j] = i * j;
	EXPECT_FALSE(m != m);
}

TEST(TMatrix, can_assign_three_matrix_MY_TEST)
{
	int s = 7;
	TMatrix<int>m1(s), m2(s), m3(s), expans(s);
	for (int i = 0; i < s; i++)
		for (int j = i; j < s; j++)
		{
			m1[i][j] = i * j;
			expans[i][j] = i * j;

		}
	m3 = m2 = m1;
	EXPECT_EQ(expans, m1);
	EXPECT_EQ(expans, m2);
	EXPECT_EQ(expans, m3);
}

TEST(TMatrix, throws_when_set_element_in_lower_triangle_MY_TEST)
{
	int s = 2;
	TMatrix<int>m(s);
	ASSERT_ANY_THROW(m[1][0] = 5);
}