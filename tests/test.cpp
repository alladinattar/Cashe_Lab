// Copyright 2020 Your Name <your_email>

#include <gtest/gtest.h>
#include "testerCashes.hpp"
#include "iostream"
TEST(Example, EmptyTest) {
  tester test;
  test.setBufs();
  test.revertTest();
  std::cout<<test.getInvestigation();
  test.straightTest();
  std::cout<<test.getInvestigation();
  test.randomTest();
  std::cout<<test.getInvestigation();
}
