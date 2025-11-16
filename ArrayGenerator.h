//
// Created by admin on 16.11.2025.
//

#ifndef SORTTESTING_ARRAYGENERATOR_H
#define SORTTESTING_ARRAYGENERATOR_H
#include <vector>
#include <random>

class ArrayGenerator {
public:

    ArrayGenerator() : rng(1239239) {
        std::uniform_int_distribution<int> dist(minVal, maxVal);

        baseRandom.resize(maxSize);
        for (int& t : baseRandom) {
            t = dist(rng);
        }

        baseSorted = baseRandom;
        std::sort(baseSorted.begin(), baseSorted.end());

        baseReverse = baseSorted;
        std::reverse(baseReverse.begin(), baseRandom.end());
    }

    std::vector<int> getRandom(size_t n) const {
        checkSize(n);
        return std::vector<int>(baseRandom.begin(), baseRandom.begin() + n);
    }

    std::vector<int> getReverse(size_t n) const {
        checkSize(n);
        return std::vector<int>(baseReverse.begin(), baseReverse.begin() + n);
    }

    std::vector<int> getAlmostSorted(size_t n) const {
        checkSize(n);



        std::vector<int> as(baseSorted.begin(), baseSorted.begin() + n);

        std::mt19937 rnd(rand());
        size_t swaps = n / 100;
        std::uniform_int_distribution<size_t> rndIndex(0, n - 1);
        for (size_t t = 0; t < swaps; ++t) {
            size_t i = rndIndex(rnd);
            size_t j = rndIndex(rnd);
            std::swap(as[i], as[j]);
        }

        return as;
    }

private:
    size_t maxSize = 100000;
    size_t minSize = 0;
    int minVal = 0;
    int maxVal = 6000;
    std::mt19937 rng;

    std::vector<int> baseRandom;
    std::vector<int> baseSorted;
    std::vector<int> baseReverse;

    void checkSize(size_t& n) const {
        n = std::min(n, maxSize);
        n = std::max(n, minSize);
    }
};
#endif//SORTTESTING_ARRAYGENERATOR_H
