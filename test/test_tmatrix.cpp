#include "utmatrix.h"

#include <gtest/gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m(5);

  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	int s = 8;
	TMatrix<int> m1(s);
	for (int i = 0; i < s; i++)
		for (int j = i; j < s; j++)
			m1[i][j] = i + j;
	TMatrix<int> m2 = m1;
	EXPECT_EQ(m1, m2);

}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	int s = 8;
	TMatrix<int> m1(s);
	for (int i = 0; i < s; i++)
		for (int j = i; j < s; j++)
			m1[i][j] = i + j;
	TMatrix<int> m2 = m1;
	++m1[0][0];
	EXPECT_NE(m1, m2);
}

TEST(TMatrix, can_get_size)
{
	int s = 8;
	TMatrix<int>m(s);
	EXPECT_EQ(s, m.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	int s = 8;
	TMatrix<int>m(s);
	m[0][0] = 5;
	EXPECT_EQ(5, m[0][0]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	int s = 8;
	TMatrix<int> m(s);
	ASSERT_ANY_THROW(m[-1][-1] = 4);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	int s = 8;
	TMatrix<int>m(s);
	ASSERT_ANY_THROW(m[8][8] = 5);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	int s = 8;
	TMatrix<int> m(s);
	ASSERT_NO_THROW(m = m);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	int s = 7;
	TMatrix<int>m1(s), m2(s);
	for (int i = 0; i < s; i++)
		for (int j = i; j < s; j++)
			m1[i][j] = i * j;
	m2 = m1;
	EXPECT_EQ(m1, m2);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	int s1 = 7, s2 = 4;
	TMatrix<int>m1(s1), m2(s2);
	for (int i = 0; i < s1; i++)
		for (int j = i; j < s1; j++)
			m1[i][j] = i * j;
	m2 = m1;
	EXPECT_EQ(s1, m2.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	int s1 = 7, s2 = 4;
	TMatrix<int>m1(s1), m2(s2);
	for (int i = 0; i < s1; i++)
		for (int j = i; j < s1; j++)
			m1[i][j] = i * j;
	m2 = m1;
	EXPECT_EQ(m1, m2);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	int s = 6;
	TMatrix<int>m1(s), m2(s);
	for (int i = 0; i < s; i++)
		for (int j = i; j < s; j++)
		{
			m1[i][j] = i * j;
			m2[i][j] = i * j;
		}
	EXPECT_TRUE(m1 == m2);
	
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	int s = 6;
	TMatrix<int>m(s);
	for (int i = 0; i < s; i++)
		for (int j = i; j < s; j++)
			m[i][j] = i * j;
	EXPECT_TRUE(m == m);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	int s1 = 7, s2 = 4;
	TMatrix<int>m1(s1), m2(s2);
	for (int i = 0; i < s1; i++)
		for (int j = i; j < s1; j++)
			m1[i][j] = i * j;
	for (int i = 0; i < s2; i++)
		for (int j = i; j < s2; j++)
			m2[i][j] = i * j;
	EXPECT_FALSE(m1 == m2);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	int s = 7;
	TMatrix<int>m1(s), m2(s), ans(s), expans(s);
	for (int i = 0; i < s; i++)
		for (int j = i; j < s; j++)
		{
			m1[i][j] = i * j;
			m2[i][j] = 2 * i * j;
			expans[i][j] = 3 * i * j;
		}
	ans = m1 + m2;
	EXPECT_EQ(ans, expans);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	int s1 = 7, s2 = 8;
	TMatrix<int> m1(s1), m2(s2);
	ASSERT_ANY_THROW(m1 + m2);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	int s = 7;
	TMatrix<int>m1(s), m2(s), ans(s), expans(s);
	for (int i = 0; i < s; i++)
		for (int j = i; j < s; j++)
		{
			m1[i][j] = 2 * i * j;
			m2[i][j] = i * j;
			expans[i][j] = i * j;
		}
	ans = m1 - m2;
	EXPECT_EQ(ans, expans);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	int s1 = 7, s2 = 8;
	TMatrix<int> m1(s1), m2(s2);
	ASSERT_ANY_THROW(m1 - m2);
}

