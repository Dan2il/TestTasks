#include "tests.h"

TEST(test_operator_eq_matrix, correcr_arg_1) {
  Matrix matrix_1 = {{1, 2, 3, 4, 5, 6}, 3, 2};
  Matrix matrix_2 = {{1, 3, 5, 2, 4, 6}, 2, 3};

  EXPECT_FALSE(matrix_1 == matrix_2);
}

TEST(test_operator_eq_matrix, correcr_arg_2) {
  Matrix matrix_1 = {{1, 2, 3, 4, 5, 6}, 3, 2};
  Matrix matrix_2 = {{1, 2, 3, 4, 5, 6}, 3, 2};

  EXPECT_TRUE(matrix_1 == matrix_2);
}

TEST(tests_methods_eq, correcr_arg_3) {
  Matrix matrix_1 = {{256, 0, -1000, 256, 0, -1000, 256, 0, -1000}, 3, 3};
  Matrix matrix_2 = {{256, 0, -1000, 256, 0, -1000, 256, 0, -1000}, 3, 3};

  EXPECT_TRUE(matrix_1 == matrix_2);
}

TEST(tests_methods_eq_matrix, uncorrect_arg) {
  Matrix matrix_1 = {{1, 2, 3, 4, 5, 6}, 3, 6};
  Matrix matrix_2 = {};

  EXPECT_FALSE(matrix_1 == matrix_2);
}
