//
// Created by robin on 15.04.24.
//

#include "utils.h"

int randInt(int min, int max) {
    std::random_device rd;  // Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(min, max); // Define the range
    return distrib(gen);
}

std::vector<int> generateRandomIntegers(int n, int min, int max) {
    std::random_device rd;  // Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(min, max); // Define the range

    std::vector<int> randomIntegers;
    randomIntegers.reserve(n); // Reserve space for n integers

    for (int i = 0; i < n; ++i) {
        randomIntegers.push_back(distrib(gen)); // Generate random integer and add to vector
    }

    return randomIntegers;
}

void Timer::start() {
    startTime = std::chrono::steady_clock::now();
}


double Timer::timeInSeconds() {
    auto end = std::chrono::steady_clock::now(); // End time
    std::chrono::duration<double> elapsed_seconds = end - startTime; // Calculate elapsed time
    return elapsed_seconds.count(); // Return sorting time in seconds
}