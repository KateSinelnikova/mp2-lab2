#include "MyVector.h"

#include <gtest.h>
#include "TMatrix.h"

TEST(TMatrix, can_create_matrix) {
    ASSERT_NO_THROW(TMatrix<int>(5));
}

TEST(TMatrix, can_set_get_element){
    TMatrix<int> m1(3);
    m1(1,1) = 5;
    EXPECT_EQ(m1(1,1),5);
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one) {
    TMatrix<int> m1(4), m2(m1);
    EXPECT_EQ(m1, m2);
}

TEST(TMatrix, error_with_negative_index){
    TMatrix<int> m1(4);
    ASSERT_ANY_THROW(m1(-1,-1));
}

TEST(TMatrix, error_with_exceed_index){
    TMatrix<int> m1(4);
    ASSERT_ANY_THROW(m1(5,5));
}

TEST(TMatrix, can_copy_matrix) {
    TMatrix<int> m1(2);
    m1(0,0) = 1;
    m1(0,1) = 2;
    m1(1,0) = 3;
    m1(1,1) = 4;
    TMatrix<int>m2(m1);
    EXPECT_EQ(m1, m2);
}

TEST(TMatrix, assign_changes_size){
    TMatrix<int> m1(2), m2(3);
    m1 = m2;
    EXPECT_EQ(m1.Length(), 3);
}