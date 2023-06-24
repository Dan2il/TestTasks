#include <cassert>
#include <string>

bool CheckCorrectPositionBrackets(const std::string& expression) {
  int counter_open_brackets = 0;
  int counter_close_brackets = 0;
  for (const char symbol : expression) {
    if (symbol == ')' && !counter_open_brackets) {
      return false;
    } else if (symbol == '(') {
      ++counter_open_brackets;
    } else if (symbol == ')') {
      --counter_open_brackets;
    }
  }
  return (!counter_open_brackets && !counter_close_brackets);
}

int main() {
  assert(CheckCorrectPositionBrackets("2+2") == true);
  assert(CheckCorrectPositionBrackets(
             "assert(CheckCorrectPositionBrackets(\"2 + 2\") == true)") ==
         true);
  assert(CheckCorrectPositionBrackets("(234cds+23r))") == false);
}