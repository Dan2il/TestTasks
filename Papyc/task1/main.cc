#include <cassert>
#include <iostream>
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
  assert(CheckCorrectPositionBrackets("(1+2)*4") == true);
  assert(CheckCorrectPositionBrackets("(1+2)*4+3") == true);
  assert(CheckCorrectPositionBrackets("((1+2)*4)+3") == true);
  assert(CheckCorrectPositionBrackets(
             "15/(7-(1+1))*3-(2+(1+1))*15/(7-(200+1))*3-(2+(1+1))*(15/"
             "(7-(1+1))*3-(2+(1+1))+15/(7-(1+1))*3-(2+(1+1)))") == true);
  assert(CheckCorrectPositionBrackets("") == true);
  assert(CheckCorrectPositionBrackets("-456-(-2*-56)+(+(-23)/45)") == true);
  assert(CheckCorrectPositionBrackets("sin(cos(111))+tan(sqrt(222))-acos(asin("
                                      "333))*atan(444)/ln(log(555))") == true);
  assert(CheckCorrectPositionBrackets("-(-(-4,4-1,1))") == true);

  assert(CheckCorrectPositionBrackets("(234cds+23r))") == false);
  assert(CheckCorrectPositionBrackets("3+4*2/(1-5)^2)") == false);
  assert(CheckCorrectPositionBrackets("(") == false);

  std::cout << "success" << std::endl;
}