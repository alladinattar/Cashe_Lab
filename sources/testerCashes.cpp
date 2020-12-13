//
// Copyright 2020 Rinat <rinatmuka4@gmail.com>
//

#include "testerCashes.hpp"
#include "chrono"
#include "algorithm"
#include "random"
#include "sstream"

void tester::straightTest() {
  varOfTest = "direction";
  durationsOfTest.clear();

  for (const double& size : sizesOfBufs) {
    int* arr1 = new int[static_cast<int>(size / 4.0)];
    for (int i = 0; i < size / 4.0; i += 16) {
      vault = arr1[i];
    }
    auto startTime = std::chrono::steady_clock::now();
    for (int item = 0; item < 1000; ++item) {
      for (int i = 0; i < size / 4.0; i += 16) {
        vault = arr1[i];
      }
    }
    auto endTime = std::chrono::steady_clock::now();
    durationsOfTest.push_back(
        std::chrono::duration_cast<std::chrono::milliseconds>
            (endTime - startTime).count());
    delete[] arr1;
  }
}

void tester::revertTest() {
  varOfTest = "reverse";
  durationsOfTest.clear();


  for (const double& size : sizesOfBufs) {
    int* arr1 = new int[static_cast<int>(size / 4.0)];
    for (int i = size / 4.0; i > 0; i -= 16) {
      vault = arr1[i];
    }
    auto startTime = std::chrono::steady_clock::now();
    for (int i = 0; i < 1000; ++i) {
      for (int j = size / 4.0; j > 0; j -= 16) {
        vault = arr1[j];
      }
    }
    auto endTime = std::chrono::steady_clock::now();

    durationsOfTest.push_back(
        std::chrono::duration_cast<std::chrono::milliseconds>
            (endTime - startTime).count());
    delete[] arr1;
  }
}

void tester::randomTest() {
  varOfTest = "random";
  durationsOfTest.clear();
  for (const double& size : sizesOfBufs) {
    int* arr1 = new int[static_cast<int>(size / 4.0)];
    std::vector<int> indexesOfBlocks;
    for (int j = 0; j < size / 4.0; j += 16) {
      indexesOfBlocks.push_back(j);
      vault = arr1[j];
    }
    auto rng = std::default_random_engine{};
    std::shuffle(indexesOfBlocks.begin(), indexesOfBlocks.end(), rng);

    auto startTime = std::chrono::steady_clock::now();
    for (int i = 0; i < 1000; ++i) {
      for (auto index : indexesOfBlocks) {
        vault = arr1[index];
      }
    }
    auto endTime = std::chrono::steady_clock::now();
    durationsOfTest.push_back(
        std::chrono::duration_cast<std::chrono::milliseconds>
            (endTime - startTime).count());
    delete[] arr1;
  }
}

std::stringstream tester::getExp(int indexOfBuf) {
  std::stringstream ss;
  ss << "\t- experiment:\n"
     << "\t\tnumber: " << indexOfBuf + 1 << "\n"
     << "\t\tinput_data:\n"
     << "\t\t\tbuffer_size: " << sizesOfBufs[indexOfBuf] / 1024 << "Kb"
     << "\n"
     << "\t\tresults:\n"
     << "\t\t\tduration: " << durationsOfTest[indexOfBuf] << "ms" << '\n';
  return ss;
}

std::string tester::getInvestigation() {
  std::stringstream ss;
  ss << "investigation:\n"
     << "\ttravel_variant:" << varOfTest << "\n";
  for (size_t duration = 0; duration < durationsOfTest.size(); ++duration) {
    ss << getExp(duration).str();
  }
  ss << "\n";
  return ss.str();
}

void tester::setBufs() {
  sizesOfBufs.push_back(sizesOfCashes[0] / 2.0 * 1024 * 1024);
  for (int i = 1; i <= 1.5 * sizesOfCashes[2]; i *= 2) {
    sizesOfBufs.push_back(i * 1024 * 1024);
  }
  sizesOfBufs.push_back(sizesOfCashes[2] * 1.5 * 1024 * 1024);
}
