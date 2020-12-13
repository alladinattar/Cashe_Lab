// Copyright 2020 Rinat <rinatmuka4@gmail.com>
#ifndef INCLUDE_TESTERCASHES_HPP_
#define INCLUDE_TESTERCASHES_HPP_
#include "string"
#include "vector"
class tester {
 private:
  std::string varOfTest;

  std::vector<double> sizesOfCashes = {0.25, 1, 6 };
  std::vector<double> sizesOfBufs;
  std::vector<double> durationsOfTest;
  int vault;

 public:
  void straightTest();
  void randomTest();
  void revertTest();
  void setBufs();

  std::stringstream getExp(int indexOfBuf);
  std::string getInvestigation();
};
#endif  // INCLUDE_TESTERCASHES_HPP_
