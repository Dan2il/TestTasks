#include <iostream>
#include <string>

struct Node {
  char symbol;
  struct Node* next_node = nullptr;
};

class List {
 public:
  List() = default;
  List(const std::string& symbols);

  ~List();

  List Reverse();
  size_t Size();

  void PrintList();

  Node& GetNullNode();

 private:
  Node null_node = {'-', nullptr};
  unsigned int size = 0;

  void FreeList();
};
