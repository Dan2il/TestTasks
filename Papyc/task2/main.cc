#include <iostream>
#include <string>

bool CheckEntryInArray(const std::string* B, const size_t num_b,
                       const std::string& word) {
  for (size_t counter_b = 0; counter_b < num_b; ++counter_b) {
    if (B[counter_b] == word) {
      return true;
    }
  }
  return false;
}

std::string* GetDifferentArray(const std::string* A, const size_t num_a,
                               const std::string* B, const size_t num_b) {
  std::string* res = nullptr;
  if (A && num_a && B && num_b) {
    size_t size_res = 0;
    for (size_t counter_a = 0; counter_a < num_a; ++counter_a) {
      if (!CheckEntryInArray(B, num_b, A[counter_a])) {
        std::cout << size_res << std::endl;
        res = new std::string[++size_res];
        res[size_res - 1] = A[counter_a];
        std::cout << res[size_res - 1] << std::endl;
      }
    }
  }
  return res;
}

int main() {
  std::string* old_excellent = new std::string[5];
  old_excellent[0] = "Ivanov";
  old_excellent[1] = "Sidoerov";
  old_excellent[2] = "Melnicov";
  old_excellent[3] = "Mechen";
  old_excellent[4] = "Lebedev";
  std::string* now_excellent = new std::string[3];
  now_excellent[0] = "Ivanov";
  now_excellent[1] = "Sidoerov";
  now_excellent[2] = "Melnicov";

  std::string* result = GetDifferentArray(old_excellent, 5, now_excellent, 3);

  std::cout << "size = " << result->size() << std::endl;
  std::cout << result->at(0) << std::endl;
  std::cout << result->at(1) << std::endl;

  delete[] old_excellent;
  delete[] now_excellent;
  delete[] result;
}