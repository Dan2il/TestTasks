#include <cassert>
#include <iostream>
#include <string>
#include <vector>

bool CheckEntryInArray(std::vector<int>& indexs_search_in_B,
                       const std::vector<std::string>& B, const size_t num_b,
                       const std::string& student_search) {
  for (int index : indexs_search_in_B) {
    if (B.at(index) == student_search) {
      indexs_search_in_B.erase((indexs_search_in_B.begin() + index));
      return true;
    }
  }

  for (const std::string& student : B) {
    if (student == student_search) {
      return true;
    }
  }
  return false;
}

std::vector<std::string> GetDifferentArray(const std::vector<std::string>& A,
                                           const size_t num_a,
                                           const std::vector<std::string>& B,
                                           const size_t num_b) {
  std::vector<std::string> res;
  if (!A.empty() && num_a && !B.empty() && num_b) {
    if (num_a == num_b) {
      return res;
    }
    std::vector<int> indexs_search_in_B;
    indexs_search_in_B.resize(num_b);
    for (size_t counter_B = 0; counter_B < num_b; ++counter_B) {
      indexs_search_in_B.push_back(counter_B);
    }

    for (size_t counter_A = 0; counter_A < num_a; ++counter_A) {
      if (!CheckEntryInArray(indexs_search_in_B, B, num_b, A.at(counter_A))) {
        res.push_back(A.at(counter_A));
      }
    }
  }
  return res;
}

std::vector<std::string> Test(std::vector<std::string> old_excellent,
                              size_t size_old,
                              std::vector<std::string> now_excellent,
                              size_t size_now) {
  return GetDifferentArray(old_excellent, size_old, now_excellent, size_now);
}

int main() {
  std::vector<std::string> old_excellent(
      {"Ivanov", "Sidoerov", "Melnicov", "Mechen", "Lebedev"});
  std::vector<std::string> now_excellent({"Ivanov", "Sidoerov", "Melnicov"});
  std::vector<std::string> result =
      Test({"Ivanov", "Sidoerov", "Melnicov", "Mechen", "Lebedev"}, 5,
           {"Ivanov", "Sidoerov", "Melnicov"}, 3);

  assert(result.at(0) == "Mechen");
  assert(result.at(1) == "Lebedev");

  result = Test(
      {"Don Jones",          "Robert Hernandez", "Eugene Santiago",
       "Gregory Benson",     "Mark Kelly",       "Kevin Carpenter",
       "Joseph Mason",       "Joseph Jackson",   "Anthony Carter",
       "Peter Sullivan",     "Brian Lee",        "Ronald Reynolds",
       "Alfredo Ross",       "Louis Alvarez",    "Robert Foster",
       "Thomas Simmons",     "Joseph Alexander", "Vincent Holland",
       "Thomas Hunter",      "Richard Drake",    "Randy Brown",
       "James Jennings",     "Jack Bell",        "Gregory Edwards",
       "Lester Gibbs",       "Joseph Hughes",    "Frank West",
       "Kevin Miller",       "Jessie Coleman",   "Zachary Miller",
       "Richard Peterson",   "Carl Stone",       "Christopher Martin",
       "Richard Edwards",    "Jesus Lawrence",   "Charles Bass",
       "Cory Gilbert",       "Lee Jones",        "Raymond Allen",
       "Brian Fields",       "Jose Kennedy",     "Jason Holmes",
       "Phillip Brooks",     "Gary Bowman",      "Bobby Barber",
       "James Jackson",      "Kevin Johnson",    "Joe Gonzales",
       "Miguel Barton",      "Patrick Brady",    "Albert Hill",
       "Anthony Webb",       "Adam Young",       "Alex Thomas",
       "Richard Haynes",     "Alvin Gray",       "Wallace Johnson",
       "James Turner",       "Jeremy Rodriguez", "Victor Ford",
       "Martin Powers",      "John Gutierrez",   "William Perkins",
       "Bryan Little",       "Scott Roberts",    "Daryl King",
       "John Kim",           "Nathaniel Cox",    "Gary Jones",
       "Jerome Todd",        "William Reed",     "Kurt Washington",
       "Mark Atkins",        "James Graham",     "Raymond Edwards",
       "Thomas Taylor",      "Charles Scott",    "Brian Hill",
       "Christopher Miller", "Mark Blair",       "Carlos Brown",
       "Gordon Brooks",      "Larry Watson",     "Christopher Gonzalez",
       "Calvin Harris",      "Herbert Wright",   "Alfredo Dawson",
       "Andrew Butler",      "Steven Sanchez",   "Ronald Jackson",
       "Gilbert Myers",      "George Garner",    "James Smith",
       "Charles Hayes",      "Lance Walker",     "Warren White",
       "William Ward",       "Paul Taylor",      "Rodney Stevens",
       "Chris King"},
      100, {"Don Jones",          "Robert Hernandez", "Eugene Santiago",
            "Gregory Benson",     "Mark Kelly",       "Kevin Carpenter",
            "Joseph Mason",       "Joseph Jackson",   "Anthony Carter",
            "Peter Sullivan",     "Brian Lee",        "Ronald Reynolds",
            "Alfredo Ross",       "Louis Alvarez",    "Robert Foster",
            "Thomas Simmons",     "Joseph Alexander", "Vincent Holland",
            "Thomas Hunter",      "Richard Drake",    "Randy Brown",
            "James Jennings",     "Jack Bell",        "Gregory Edwards",
            "Lester Gibbs",       "Joseph Hughes",    "Frank West",
            "Kevin Miller",       "Jessie Coleman",   "Zachary Miller",
            "Richard Peterson",   "Carl Stone",       "Christopher Martin",
            "Richard Edwards",    "Jesus Lawrence",   "Charles Bass",
            "Cory Gilbert",       "Lee Jones",        "Raymond Allen",
            "Brian Fields",       "Jose Kennedy",     "Jason Holmes",
            "Phillip Brooks",     "Gary Bowman",      "Bobby Barber",
            "James Jackson",      "Kevin Johnson",    "Joe Gonzales",
            "Miguel Barton",      "Patrick Brady",    "Albert Hill",
            "Anthony Webb",       "Adam Young",       "Alex Thomas",
            "Richard Haynes",     "Alvin Gray",       "Wallace Johnson",
            "James Turner",       "Jeremy Rodriguez", "Victor Ford",
            "Martin Powers",      "John Gutierrez",   "William Perkins",
            "Bryan Little",       "Scott Roberts",    "Daryl King",
            "John Kim",           "Nathaniel Cox",    "Gary Jones",
            "Jerome Todd",        "William Reed",     "Kurt Washington",
            "Mark Atkins",        "James Graham",     "Raymond Edwards",
            "Thomas Taylor",      "Charles Scott",    "Brian Hill",
            "Christopher Miller", "Mark Blair",       "Carlos Brown",
            "Gordon Brooks",      "Larry Watson",     "Christopher Gonzalez",
            "Calvin Harris",      "Herbert Wright",   "Alfredo Dawson",
            "Andrew Butler",      "Steven Sanchez",   "Ronald Jackson",
            "Gilbert Myers",      "George Garner",    "James Smith",
            "Charles Hayes",      "Lance Walker",     "Warren White",
            "William Ward",       "Paul Taylor",      "Rodney Stevens"},
      99);

  assert(result.at(0) == "Chris King");

  result = Test({}, 5, {}, 3);

  assert(result.empty());
}