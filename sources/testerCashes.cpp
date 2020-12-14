//
// Copyright 2020 Rinat <rinatmuka4@gmail.com>
//

#include "testerCashes.hpp"
#include "chrono"
#include "algorithm"
#include "random"
#include "sstream"


const int kylo1024 = 1024;
const int kylo1000 = 1000;
const double four = 4.;
const int sixteen = 16;

void tester::straightTest() {
    varOfTest = "direction";
    durationsOfTest.clear();
    [[maybe_unused]] int vault;
    for (const double &size : sizesOfBufs) {
        int *arr1 = new int[static_cast<int>(size / four)];
        for (int i = 0; i < size / four; i += sixteen) {
            vault = arr1[i];
        }
        auto startTime = std::chrono::steady_clock::now();
        for (int item = 0; item < kylo1000; ++item) {
            for (int i = 0; i < size / four; i += sixteen) {
                vault = arr1[i];
            }
        }
        auto endTime = std::chrono::steady_clock::now();
        durationsOfTest.push_back(
                std::chrono::duration_cast<std::chrono::microseconds>
                        (endTime - startTime).count()/kylo1000);
        delete[] arr1;
    }
}

void tester::revertTest() {
    varOfTest = "reverse";
    durationsOfTest.clear();

    [[maybe_unused]] int vault;

    for (const double &size : sizesOfBufs) {
        int *arr1 = new int[static_cast<int>(size / four)];
        for (int i = size / four-1; i > 0; i -= sixteen) {
            vault = arr1[i];
        }
        auto startTime = std::chrono::steady_clock::now();
        for (int i = 0; i < kylo1000; ++i) {
            for (int j = size / four-1; j > 0; j -= sixteen) {
                vault = arr1[j];
            }
        }
        auto endTime = std::chrono::steady_clock::now();

        durationsOfTest.push_back(
                std::chrono::duration_cast<std::chrono::microseconds>
                        (endTime - startTime).count()/kylo1000);
        delete[] arr1;
    }
}

void tester::randomTest() {
    varOfTest = "random";
    durationsOfTest.clear();
    [[maybe_unused]]int vault;

    for (const double &size : sizesOfBufs) {
        int *arr1 = new int[static_cast<int>(size / four)];
        std::vector<int> indexesOfBlocks;
        for (int j = 0; j < size / four; j += sixteen) {
            indexesOfBlocks.push_back(j);
            vault = arr1[j];
        }
        auto rng = std::default_random_engine{};
        std::shuffle(indexesOfBlocks.begin(), indexesOfBlocks.end(), rng);

        auto startTime = std::chrono::steady_clock::now();
        for (int i = 0; i < kylo1000; ++i) {
            for (auto index : indexesOfBlocks) {
                vault = arr1[index];
            }
        }
        auto endTime = std::chrono::steady_clock::now();
        durationsOfTest.push_back(
                std::chrono::duration_cast<std::chrono::microseconds>
                        (endTime - startTime).count()/kylo1000);
        delete[] arr1;
    }
}

std::stringstream tester::getExp(int indexOfBuf) {
    std::stringstream ss;
    ss << "\t- experiment:\n"
       << "\t\tnumber: " << indexOfBuf + 1 << "\n"
       << "\t\tinput_data:\n"
       << "\t\t\tbuffer_size: " << sizesOfBufs[indexOfBuf] / kylo1024 << "Kb"
       << "\n"
       << "\t\tresults:\n"
       << "\t\t\tduration: " << durationsOfTest[indexOfBuf] << "mcs" << '\n';
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

std::string tester::getVarOfTest() {
    return varOfTest;
}

size_t tester::getSizeOfBufArr() {return sizesOfBufs.size();}

std::ostream & operator << (std::ostream & out, tester & invest){
    out << "investigation:\n" << "\ttravel_variant: "
    << invest.getVarOfTest() << "\n";
    for (size_t i = 0; i < invest.getSizeOfBufArr(); ++i)
        out << invest.getExp(i).str();
    out << "\n";
    return out;
}

void tester::setBufs() {
    sizesOfBufs.push_back(sizesOfCashes[0] / 2.0 * kylo1024 * kylo1024);
    for (int i = 1; i <= 1.5 * sizesOfCashes[2]; i *= 2) {
        sizesOfBufs.push_back(i * kylo1024 * kylo1024);
    }
    sizesOfBufs.push_back(sizesOfCashes[2] * 1.5 * kylo1024 * kylo1024);
}

