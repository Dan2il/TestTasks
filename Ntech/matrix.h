#include <future>
#include <vector>

struct Matrix {
  std::vector<int> data;
  unsigned int width = 0;
  unsigned int height = 0;

  bool operator==(const Matrix &matrix);
  bool operator==(const Matrix &matrix) const;

  Matrix Transpose();
};

class WorkerInterface {
 public:
  WorkerInterface() = default;
  WorkerInterface(WorkerInterface &&) = delete;
  WorkerInterface(const WorkerInterface &) = delete;

  WorkerInterface &operator=(WorkerInterface &&) = delete;
  WorkerInterface &operator=(const WorkerInterface &) = delete;

  virtual ~WorkerInterface() = default;

  virtual std::future<Matrix> AsyncProcess(Matrix matrix) = 0;
};

std::shared_ptr<WorkerInterface> get_new_worker();

class MatrixWorker : public WorkerInterface {
 public:
  std::future<Matrix> AsyncProcess(Matrix matrix) override {
    Matrix transposedMatrix = matrix.Transpose();
    std::promise<Matrix> resultPromise;
    resultPromise.set_value(transposedMatrix);
    return resultPromise.get_future();
  }
};