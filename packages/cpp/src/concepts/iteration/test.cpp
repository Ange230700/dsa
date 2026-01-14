// src\concepts\iteration\test.cpp

#include "../../lib/dsa.hpp"

#include <vector>

// Forward declarations (simple MVP approach)
namespace iteration {
int sum(const std::vector<int>& xs);
int count_greater_than(const std::vector<int>& xs, int threshold);
int max_or_throw(const std::vector<int>& xs);
void reverse_in_place(std::vector<int>& xs);
} // namespace iteration

TEST_CASE(sum_handles_empty_and_basic) {
  ASSERT_EQ(iteration::sum({}), 0);
  ASSERT_EQ(iteration::sum({1}), 1);
  ASSERT_EQ(iteration::sum({1, 2, 3}), 6);
  ASSERT_EQ(iteration::sum({-2, 5, -3}), 0);
}

TEST_CASE(count_greater_than_basic) {
  ASSERT_EQ(iteration::count_greater_than({}, 10), 0);
  ASSERT_EQ(iteration::count_greater_than({1, 2, 3}, 2), 1);
  ASSERT_EQ(iteration::count_greater_than({5, 5, 5}, 4), 3);
  ASSERT_EQ(iteration::count_greater_than({-1, 0, 1}, 0), 1);
}

TEST_CASE(max_or_throw_behaviour) {
  ASSERT_THROW(iteration::max_or_throw({}));
  ASSERT_EQ(iteration::max_or_throw({7}), 7);
  ASSERT_EQ(iteration::max_or_throw({1, 9, 3}), 9);
  ASSERT_EQ(iteration::max_or_throw({-10, -2, -30}), -2);
}

TEST_CASE(reverse_in_place_basic) {
  std::vector<int> a{};
  iteration::reverse_in_place(a);
  ASSERT_TRUE(a.empty());

  std::vector<int> b{1};
  iteration::reverse_in_place(b);
  ASSERT_EQ(b.size(), 1);
  ASSERT_EQ(b[0], 1);

  std::vector<int> c{1, 2, 3, 4};
  iteration::reverse_in_place(c);
  ASSERT_EQ(c[0], 4);
  ASSERT_EQ(c[1], 3);
  ASSERT_EQ(c[2], 2);
  ASSERT_EQ(c[3], 1);
}

int main() {
  return dsa::run_all_tests();
}
