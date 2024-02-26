#include "matrix.h"

bool Matrix::operator==(const Matrix& matrix) {
  return matrix.data == this->data and matrix.width == this->width and
         matrix.height == this->height;
}

bool Matrix::operator==(const Matrix& matrix) const {
  return matrix.data == this->data and matrix.width == this->width and
         matrix.height == this->height;
}

Matrix Matrix::Transpose() {
  if (!this->width or !this->height) {
    throw std::invalid_argument("Uncorrect width or height");
  }

  Matrix result = {std::vector<int>(this->height * this->width), this->height,
                   this->width};

  if (this->width == 1 and this->height == 1) {
    result.data[0] = this->data[0];
    return result;
  }

  for (size_t i = 0; i < this->height; ++i) {
    for (size_t j = 0; j < this->width; ++j) {
      result.data[j * result.width + i] = this->data[i * this->width + j];
    }
  }
  return result;
}

std::shared_ptr<WorkerInterface> get_new_worker() {
  return std::make_shared<MatrixWorker>();
}