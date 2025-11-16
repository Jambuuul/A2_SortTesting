//
// Created by admin on 16.11.2025.
//

#ifndef SORTTESTING_SORTTESTER_H
#define SORTTESTING_SORTTESTER_H
#include "ArrayGenerator.h"
#include <functional>
#include <vector>
#include <chrono>

using namespace std;

class SortTester {
public:
    SortTester(ArrayGenerator& generator) : gen(generator) {}

    long long measureRandom(int n, function<void(vector<int>&)> sorter) {
        vector<int> a = gen.getRandom(n);
        return measure(a, sorter);
    }

    long long measureReverse(int n, function<void(vector<int>&)> sorter) {
        vector<int> a = gen.getReverse(n);
        return measure(a, sorter);
    }

    long long measureAlmostSorted(int n, function<void(vector<int>&)> sorter) {
        vector<int> a = gen.getAlmostSorted(n);
        return measure(a, sorter);
    }

    long long measure(vector<int>& a, function<void(vector<int>&)> sorter) {
        auto start = chrono::high_resolution_clock::now();
        sorter(a);
        auto elapsed = std::chrono::high_resolution_clock::now() - start;
        return std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count();;
    }

private:
    const ArrayGenerator& gen;
};

#endif//SORTTESTING_SORTTESTER_H
