// src\concepts\iteration\solution.cpp

#include <algorithm>
#include <numeric>
#include <stdexcept>
#include <vector>

namespace iteration {

int sum(const std::vector<int>& xs) {
  return std::accumulate(xs.begin(), xs.end(), 0);
}

int count_greater_than(const std::vector<int>& xs, int threshold) {
  return static_cast<int>(
      std::count_if(xs.begin(), xs.end(),
                    [&](int v) { return v > threshold; }));
}

int max_or_throw(const std::vector<int>& xs) {
  if (xs.empty()) throw std::invalid_argument("empty input");
  return *std::max_element(xs.begin(), xs.end());
}

void reverse_in_place(std::vector<int>& xs) {
  std::reverse(xs.begin(), xs.end());
}

} // namespace iteration
