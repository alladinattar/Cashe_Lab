// Copyright 2020 Your Name <your_email>

#include <gtest/gtest.h>

#include "iostream"
#include "testerCashes.hpp"
TEST(Example, EmptyTest) {
  tester test;
  test.setBufs();
  test.straightTest();
  std::cout << test.getInvestigation();
  test.revertTest();
  std::cout << test.getInvestigation();
  test.randomTest();
  std::cout << test.getInvestigation();
}
