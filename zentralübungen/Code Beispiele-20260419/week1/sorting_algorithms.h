//
// Created by robin on 15.04.24.
//

#include <vector>
#include <algorithm>

#ifndef DEMO_SORTING_ALGORITHMS_H
#define DEMO_SORTING_ALGORITHMS_H

void builtInSort(std::vector<int>& vec);

void quickSort(std::vector<int>& vec, int low, int high);

void quickSort(std::vector<int>& vec);

void badSort(std::vector<int>& vec);

void sort1(std::vector<int>& vec);
void sort2(std::vector<int>& vec);
void sort3(std::vector<int>& vec);

#endif //DEMO_SORTING_ALGORITHMS_H
