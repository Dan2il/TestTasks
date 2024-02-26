#include "tests.h"

TEST(tests_methods_transpose, correct_arg) {
  Matrix matrix_1 = {{1, 2, 3, 4, 5, 6}, 3, 2};
  Matrix answer = {{1, 4, 2, 5, 3, 6}, 2, 3};
  Matrix result = matrix_1.Transpose();

  EXPECT_TRUE(result == answer);
}

TEST(tests_methods_transpose, correct_arg_2) {
  unsigned int rows = unsigned(rand() % 1000 + 1);
  unsigned int columns = unsigned(rand() % 1000 + 1);

  Matrix matrix_1 = {std::vector<int>(rows * columns), rows, columns};
  Matrix answer = {std::vector<int>(rows * columns), columns, rows};

  for (unsigned int i = 0; i < rows; i++) {
    for (unsigned int j = 0; j < columns; j++) {
      double value1 = (rand() - 298.3) / (rand() + 1);
      matrix_1.data[j * matrix_1.width + i] = value1;
      answer.data[i * answer.width + j] = value1;
    }
  }
  Matrix result = matrix_1.Transpose();
  EXPECT_TRUE(result == answer);
}

TEST(tests_methods_transpose, correct_arg_3) {
  Matrix matrix_1 = {{23}, 1, 1};
  Matrix answer = {{23}, 1, 1};

  Matrix result = matrix_1.Transpose();
  EXPECT_TRUE(result == answer);
}

TEST(tests_methods_transpose, uncorrect_arg_1) {
  Matrix matrix_1;
  Matrix answer;

  EXPECT_ANY_THROW(Matrix result = matrix_1.Transpose());
}