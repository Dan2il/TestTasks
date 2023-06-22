#include "list.h"

List::List(const std::string& symbols) {
  Node* push_node = &null_node;
  try {
    for (const char symbol : symbols) {
      Node* new_node = new Node{symbol, nullptr};
      push_node->next_node = new_node;
      push_node = push_node->next_node;
      ++size;
    }
  } catch (const std::exception& e) {
    FreeList();
    throw;
  }
}

List::~List() { FreeList(); }

void List::FreeList() {
  for (Node* next_node = null_node.next_node; next_node != nullptr;) {
    Node* clean = next_node;
    next_node = next_node->next_node;
    delete clean;
    --size;
  }
}

size_t List::Size() { return size; }

Node& List::GetNullNode() { return null_node; }

List List::Reverse() {
  List res;
  if (size) {
    char reverse_list[size];
    int index_reverse_list = size - 1;
    for (Node* next_node = null_node.next_node; next_node != nullptr;) {
      reverse_list[index_reverse_list] = next_node->symbol;
      next_node = next_node->next_node;
      --index_reverse_list;
    }
    return List(std::string(reverse_list));
  }
  return res;
}