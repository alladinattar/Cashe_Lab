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

 public:
  void straightTest();
  void randomTest();
  void revertTest();
  void setBufs();
  friend std::ostream & operator << (std::ostream & out, tester & a);
  std::string getVarOfTest();
  size_t getSizeOfBufArr();

  std::stringstream getExp(int indexOfBuf);
  std::string getInvestigation();
};
#endif  // INCLUDE_TESTERCASHES_HPP_
