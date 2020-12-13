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
  std::string getVarOfTest();
  void setBufs();

  std::stringstream getExp(int indexOfBuf);
  std::string getInvestigation();
};