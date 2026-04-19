#include <iostream>

#include "sorting_algorithms.h"
#include "../utils/utils.h"

using std::vector;

const int SORTING_ALGORITHM_1 = 0;
const int SORTING_ALGORITHM_2 = 1;
const int SORTING_ALGORITHM_3 = 2;


double sortAndMeasureTime(std::vector<int>& vec, int algo) {
    Timer t;
    t.start();

    if(algo == SORTING_ALGORITHM_1) {
        sort1(vec);
    }
    else if(algo == SORTING_ALGORITHM_2) {
        sort2(vec);
    }
    else if(algo == SORTING_ALGORITHM_3) {
        sort3(vec);
    }

    return t.timeInSeconds();
}


int f(int x, float y) {
    return x;
}

int f(float x, int y) {
    return y;
}


/**
 * h    < - - - - s 0x85932042
 * e
 * l
 * l
 * o
 * h    < - - - t0x85932043
 * e
 * l
 * l
 * o
 *
 * @return
 */
int main() {
    int n = 1000000;  // Number of random integers to generate
    int min = 1;    // Minimum value
    int max = 1000; // Maximum value

    /// Generate List of random numbers
    vector<int> randomNumbers = generateRandomIntegers(n, min, max);

    /// Print Sample
    // TODO: Print first 20 elements of list
    for (int i = 0; i < 20; i++) {
        printf("%d ", randomNumbers[i]);
    }
    printf("\n");

    /// Sort
    double sortingTime = sortAndMeasureTime(randomNumbers, SORTING_ALGORITHM_1);
    printf("Sorting Time Algorithm 1:\t%.4f\n", sortingTime);

    sortingTime = sortAndMeasureTime(randomNumbers, SORTING_ALGORITHM_2);
    printf("Sorting Time Algorithm 2:\t%.4f\n", sortingTime);

    sortingTime = sortAndMeasureTime(randomNumbers, SORTING_ALGORITHM_3);
    printf("Sorting Time Algorithm 3:\t%.4f\n", sortingTime);
}
