// src\lib\dsa.hpp

#pragma once

#include <cstdlib>
#include <exception>
#include <functional>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

namespace dsa {

struct TestCase {
  std::string name;
  std::function<void()> fn;
};

inline std::vector<TestCase>& registry() {
  static std::vector<TestCase> r;
  return r;
}

inline void add_test(std::string name, std::function<void()> fn) {
  registry().push_back(TestCase{std::move(name), std::move(fn)});
}

struct TestFailure : std::exception {
  std::string msg;
  explicit TestFailure(std::string m) : msg(std::move(m)) {}
  const char* what() const noexcept override { return msg.c_str(); }
};

inline void fail(const std::string& message, const char* file, int line) {
  std::ostringstream oss;
  oss << file << ":" << line << "  " << message;
  throw TestFailure(oss.str());
}

#define ASSERT_TRUE(expr)                                                     \
  do {                                                                        \
    if (!(expr)) {                                                            \
      dsa::fail(std::string("ASSERT_TRUE failed: ") + #expr, __FILE__,        \
                __LINE__);                                                    \
    }                                                                         \
  } while (0)

#define ASSERT_EQ(a, b)                                                       \
  do {                                                                        \
    auto _a = (a);                                                            \
    auto _b = (b);                                                            \
    if (!((_a) == (_b))) {                                                    \
      std::ostringstream _oss;                                                \
      _oss << "ASSERT_EQ failed: " << #a << " != " << #b << " (got " << _a    \
           << " vs " << _b << ")";                                            \
      dsa::fail(_oss.str(), __FILE__, __LINE__);                              \
    }                                                                         \
  } while (0)

#define ASSERT_THROW(stmt)                                                    \
  do {                                                                        \
    bool _thrown = false;                                                     \
    try {                                                                     \
      (stmt);                                                                 \
    } catch (...) {                                                           \
      _thrown = true;                                                         \
    }                                                                         \
    if (!_thrown) {                                                           \
      dsa::fail(std::string("ASSERT_THROW failed: ") + #stmt, __FILE__,       \
                __LINE__);                                                    \
    }                                                                         \
  } while (0)

#define TEST_CASE(name)                                                       \
  static void name();                                                         \
  static const bool name##_registered = []() {                                 \
    dsa::add_test(#name, &name);                                               \
    return true;                                                              \
  }();                                                                        \
  static void name()

inline int run_all_tests() {
  int passed = 0;
  int failed = 0;

  std::cout << "Running " << registry().size() << " test(s)\n";

  for (const auto& t : registry()) {
    try {
      t.fn();
      ++passed;
      std::cout << "  ✅ " << t.name << "\n";
    } catch (const TestFailure& e) {
      ++failed;
      std::cout << "  ❌ " << t.name << "\n"
                << "     " << e.what() << "\n";
    } catch (const std::exception& e) {
      ++failed;
      std::cout << "  ❌ " << t.name << "\n"
                << "     " << "Unexpected std::exception: " << e.what() << "\n";
    } catch (...) {
      ++failed;
      std::cout << "  ❌ " << t.name << "\n"
                << "     " << "Unknown exception\n";
    }
  }

  std::cout << "\nSummary: " << passed << " passed, " << failed << " failed\n";
  return failed == 0 ? 0 : 1;
}

} // namespace dsa
