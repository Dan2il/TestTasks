#include "list.h"

// самый простой вариант - использовать метод reverse
// и std::forward_list
// но исхожу из предположения, что их нельзя использовать

int main() {
  List test("abcde");

  for (Node* print = test.GetNullNode().next_node; print != nullptr;) {
    std::cout << print->symbol << " ";
    print = print->next_node;
  }
  std::cout << std::endl;

  List reverse_test = test.Reverse();

  for (Node* print = reverse_test.GetNullNode().next_node; print != nullptr;) {
    std::cout << print->symbol << " ";
    print = print->next_node;
  }
  std::cout << std::endl;
}
