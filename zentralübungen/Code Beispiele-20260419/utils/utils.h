//
// Created by robin on 15.04.24.
//


#include <vector>
#include <random>
#include <chrono>

#ifndef DEMO_UTILS_H
#define DEMO_UTILS_H


int randInt(int min, int max);

std::vector<int> generateRandomIntegers(int n, int min, int max);

class Timer {
    std::chrono::time_point<std::chrono::steady_clock, std::chrono::duration<double>> startTime;
public:
    void start();
    double timeInSeconds();
};

#endif //DEMO_UTILS_H
