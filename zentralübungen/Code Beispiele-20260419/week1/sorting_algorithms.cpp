//
// Created by robin on 15.04.24.
//

#include "sorting_algorithms.h"


void builtInSort(std::vector<int>& vec){
    std::sort(vec.begin(), vec.end()); // Sort the vector
}

void quickSort(std::vector<int>& vec, int low, int high) {
    if (low < high) {
        // Partition the pointer
        int pivot = vec[high]; // Choose the last element as pivot
        int i = low - 1; // Index of smaller element

        for (int j = low; j <= high - 1; ++j) {
            // If current element is smaller than or equal to pivot
            if (vec[j] <= pivot) {
                ++i; // Increment index of smaller element
                std::swap(vec[i], vec[j]);
            }
        }
        std::swap(vec[i + 1], vec[high]);
        int pivotIndex = i + 1;

        // Recursively sort elements before and after pivot
        quickSort(vec, low, pivotIndex - 1);
        quickSort(vec, pivotIndex + 1, high);
    }
}

void quickSort(std::vector<int>& vec) {
    quickSort(vec, 0, vec.size() - 1);
}

void badSort(std::vector<int>& vec) {
    size_t n = vec.size();
    bool swapped;
    for (int i = 0; i < n - 1; ++i) {
        swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (vec[j] > vec[j + 1]) {
                // Swap vec[j] and vec[j+1]
                int temp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;
                swapped = true;
            }
        }
        // If no two elements were swapped in the inner loop, then the pointer is already sorted
        if (!swapped) {
            break;
        }
    }
}

void sort1(std::vector<int>& vec) {
    quickSort(vec);
}
void sort2(std::vector<int>& vec) {
    builtInSort(vec);
}
void sort3(std::vector<int>& vec) {
    badSort(vec);
}