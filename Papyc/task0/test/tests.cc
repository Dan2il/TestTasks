#include <gtest/gtest.h>

#include <algorithm>

#include "../src/list.h"

TEST(tests_list, correct_argument) {
  List test("abcde");
  List reverse_test = test.Reverse();
  std::string res;
  for (Node* print = reverse_test.GetNullNode().next_node; print != nullptr;) {
    res.push_back(print->symbol);
    print = print->next_node;
  }
  EXPECT_EQ(res, "edcba");
}

TEST(tests_list, correct_argument_long) {
  std::string data =
      "oh948hfduipj3,lldfiuherij    ouijnegoilj "
      "oiuhrthije5giuh\tjwhefuiherviukh";
  List test(data);
  List reverse_test = test.Reverse();
  std::string res;
  for (Node* print = reverse_test.GetNullNode().next_node; print != nullptr;) {
    res.push_back(print->symbol);
    print = print->next_node;
  }
  std::reverse(data.begin(), data.end());
  EXPECT_EQ(res, data);
}

TEST(tests_list, correct_argument_escape) {
  std::string data = "\r\n\t\v\"\'\\\?\a";
  List test(data);
  List reverse_test = test.Reverse();
  std::string res;
  for (Node* print = reverse_test.GetNullNode().next_node; print != nullptr;) {
    res.push_back(print->symbol);
    print = print->next_node;
  }
  std::reverse(data.begin(), data.end());
  EXPECT_EQ(res, data);
}

TEST(tests_list, empty) {
  List test("");
  List reverse_test = test.Reverse();
  std::string res;
  for (Node* print = reverse_test.GetNullNode().next_node; print != nullptr;) {
    res.push_back(print->symbol);
    print = print->next_node;
  }
  EXPECT_EQ(res, "");
}

TEST(tests_list, size) {
  List test_1("abcde");
  std::string data = "\r\n\t\v\"\'\\\?\a";
  List test_2(data);
  List test_3("");
  EXPECT_EQ(test_1.Size(), 5);
  EXPECT_EQ(test_2.Size(), 9);
  EXPECT_EQ(test_3.Size(), 0);
}
