#include <vector>
#include <functional>
#include <iostream>
#include <cassert>

#include "candle.h"

// 2.1 body_contains
bool test_body_contains_1()
{
  Candle c(100.0, 110.0, 90.0, 105.0); // green
  return c.body_contains(102.0) &&
         !c.body_contains(99.0) &&
         c.body_contains(100.0) &&
         c.body_contains(105.0);
}

bool test_body_contains_2()
{
  Candle c(105.0, 110.0, 90.0, 100.0); // red
  return c.body_contains(102.0) &&
         !c.body_contains(106.0) &&
         c.body_contains(105.0) &&
         c.body_contains(100.0);
}

bool test_body_contains_3()
{
  Candle c(100.0, 100.0, 100.0, 100.0); // doji
  return c.body_contains(100.0) && !c.body_contains(100.1);
}

// 2.2 contains
bool test_contains_1()
{
  Candle c(100.0, 110.0, 90.0, 105.0);
  return c.contains(95.0) && c.contains(105.0) &&
         c.contains(100.0) && !c.contains(89.9);
}

bool test_contains_2()
{
  Candle c(105.0, 110.0, 90.0, 100.0);
  return c.contains(90.0) && c.contains(110.0) && !c.contains(111.0);
}

bool test_contains_3()
{
  Candle c(100.0, 100.0, 100.0, 100.0);
  return c.contains(100.0) && !c.contains(99.9);
}

// 2.3 full_size
bool test_full_size_1()
{
  Candle c(100.0, 110.0, 90.0, 105.0);
  return std::abs(c.full_size() - 20.0) < 1e-9;
}

bool test_full_size_2()
{
  Candle c(105.0, 110.0, 90.0, 100.0);
  return std::abs(c.full_size() - 20.0) < 1e-9;
}

bool test_full_size_3()
{
  Candle c(100.0, 100.0, 100.0, 100.0);
  return c.full_size() == 0.0;
}

// 2.4 body_size
bool test_body_size_1()
{
  Candle c(100.0, 110.0, 90.0, 105.0); // green
  return std::abs(c.body_size() - 5.0) < 1e-9;
}

bool test_body_size_2()
{
  Candle c(105.0, 110.0, 90.0, 100.0); // red
  return std::abs(c.body_size() - 5.0) < 1e-9;
}

bool test_body_size_3()
{
  Candle c(100.0, 100.0, 100.0, 100.0);
  return c.body_size() == 0.0;
}

// 2.5 is_red
bool test_is_red_1()
{
  Candle c(105.0, 110.0, 90.0, 100.0);
  return c.is_red() && !c.is_green();
}

bool test_is_red_2()
{
  Candle c(100.0, 110.0, 90.0, 105.0);
  return !c.is_red();
}

bool test_is_red_3()
{
  Candle c(100.0, 100.0, 100.0, 100.0);
  return !c.is_red();
}

// 2.6 is_green
bool test_is_green_1()
{
  Candle c(100.0, 110.0, 90.0, 105.0);
  return c.is_green() && !c.is_red();
}

bool test_is_green_2()
{
  Candle c(105.0, 110.0, 90.0, 100.0);
  return !c.is_green();
}

bool test_is_green_3()
{
  Candle c(100.0, 100.0, 100.0, 100.0);
  return !c.is_green();
}

static std::vector<std::function<bool()>> tests;

void initTests()
{
  // 2.1
  tests.push_back(test_body_contains_1);
  tests.push_back(test_body_contains_2);
  tests.push_back(test_body_contains_3);
  // 2.2
  tests.push_back(test_contains_1);
  tests.push_back(test_contains_2);
  tests.push_back(test_contains_3);
  // 2.3
  tests.push_back(test_full_size_1);
  tests.push_back(test_full_size_2);
  tests.push_back(test_full_size_3);
  // 2.4
  tests.push_back(test_body_size_1);
  tests.push_back(test_body_size_2);
  tests.push_back(test_body_size_3);
  // 2.5
  tests.push_back(test_is_red_1);
  tests.push_back(test_is_red_2);
  tests.push_back(test_is_red_3);
  // 2.6
  tests.push_back(test_is_green_1);
  tests.push_back(test_is_green_2);
  tests.push_back(test_is_green_3);
}

int launchTests()
{
  int total = 0, passed = 0;
  for (const auto &test : tests)
  {
    std::cout << "test #" << (total + 1);
    if (test())
    {
      passed++;
      std::cout << " passed\n";
    }
    else
    {
      std::cout << " failed\n";
    }
    total++;
  }
  std::cout << "\n"
            << passed << "/" << total << " tests passed!\n";
  return total - passed;
}

int main()
{
  initTests();
  return launchTests();
}