#include "MyVector.h"

#include <gtest.h>
#include "SMatrix.h"

TEST(SMatrix, can_create_matrix) {
    ASSERT_NO_THROW(SMatrix<int>(4, 1, 2));
}

TEST(SMatrix, cant_create_exceed_bandwidth) {
    ASSERT_ANY_THROW(SMatrix<int>(4, 1, 4));
}

TEST(SMatrix, can_set_get_element){
    SMatrix<int> m1(3, 0,0);
    m1(1,1) = 5;
    EXPECT_EQ(m1(1,1),5);
}

TEST(SMatrix, copied_matrix_is_equal_to_source_one) {
    SMatrix<int> m1(4), m2(m1);
    EXPECT_EQ(m1, m2);
}

TEST(SMatrix, error_with_negative_index){
    SMatrix<int> m1(4);
    ASSERT_ANY_THROW(m1(-1,-1));
}

TEST(SMatrix, error_with_exceed_index){
    SMatrix<int> m1(4,1,2);
    ASSERT_ANY_THROW(m1(5,5));
}

TEST(SMatrix, error_with_out_of_bandwidth){
    SMatrix<int> m1(4,1,2);
    ASSERT_ANY_THROW(m1(2,0));
}

TEST(SMatrix, can_copy_matrix) {
    SMatrix<int> m1(3, 1);
    m1(0,0) = 1;
    m1(1,0) = 3;
    m1(1,1) = 4;
    m1(2,1) = 5;
    m1(2,2) = 6;
    SMatrix<int>m2(m1);
    EXPECT_EQ(m1, m2);
}