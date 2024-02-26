#include <chrono>
#include <iostream>
#include <thread>

#include "tests.h"

TEST(tests_matrix_worker, correct_arg) {
  auto worker = get_new_worker();
  Matrix mtx = {.data = {1, 2, 3, 4, 5, 6}, .width = 3, .height = 2};
  Matrix answer = {{1, 4, 2, 5, 3, 6}, 2, 3};

  auto future = worker->AsyncProcess(mtx);
  Matrix result = future.get();

  EXPECT_TRUE(answer == result);
};

TEST(tests_matrix_worker, correct_arg_2) {
  std::shared_ptr<WorkerInterface> worker = get_new_worker();

  Matrix matrix_1{.data = {1, 2, 3, 4, 5, 6}, .width = 3, .height = 2};
  Matrix matrix_2{.data = {7, 8, 9, 10, 11, 12}, .width = 2, .height = 3};

  Matrix answer_1{.data = {1, 4, 2, 5, 3, 6}, .width = 2, .height = 3};
  Matrix answer_2{.data = {7, 9, 11, 8, 10, 12}, .width = 3, .height = 2};

  std::future<Matrix> future_1 = worker->AsyncProcess(matrix_1);
  std::future<Matrix> future_2 = worker->AsyncProcess(matrix_2);

  future_1.wait();
  future_2.wait();

  Matrix result_1 = future_1.get();
  Matrix result_2 = future_2.get();

  EXPECT_TRUE(answer_1 == result_1);
  EXPECT_TRUE(answer_2 == result_2);
};