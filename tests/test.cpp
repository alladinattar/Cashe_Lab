// Copyright 2020 Your Name <your_email>

#include <gtest/gtest.h>

#include "iostream"
#include "testerCashes.hpp"
TEST(Example, EmptyTest) {
  tester test;
  test.setBufs();
  test.straightTest();
  std::cout << test;
  test.revertTest();
  std::cout << test;
  test.randomTest();
  std::cout << test;
}
