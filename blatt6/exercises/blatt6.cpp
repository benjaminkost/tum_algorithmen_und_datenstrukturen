#include "../include/blatt6.h"
#include <limits>

/// Aufgabe 2

// Konstante, legt maximale Werte für n und k fest
const int N = 1000;

long long binom_memo(int n, int k) {
    static auto* lookup = new long long[N][N];

    if (lookup[n][k] > 0)
    {
        return lookup[n][k];
    }

    if ( k == 0 || n == k)
    {
        lookup[n][k] = 1;
        return lookup[n][k];
    }

    lookup[n][k] = binom_memo(n-1,k-1)+binom_memo(n-1,k);

    return lookup[n][k];
}

/// Aufgabe 3
void selection_sort_iter(vector<int>& vec) {
    int min_index = -1;
    int min_value = std::numeric_limits<int>::max();
    int i = 0;

    while (i < vec.size())
    {
        int j = i;
        while (j < vec.size())
        {
            if (min_value > vec[j])
            {
                min_value = vec[j];
                min_index = j;
            }
            j++;
        }
        vec[min_index] = vec[i];
        vec[i] = min_value;
        min_value = std::numeric_limits<int>::max();
        min_index = -1;
        i++;
    }
}

void selection_sort(vector<int>& vec) {

}

/// Aufgabe 4a)
int search(vector<int>& vec, int c, int x) {
    // TODO
    return 0;
}

/// Aufgabe 4b)
int get_shift(vector<int>& vec) {
    // TODO
    return 0;
}

/**
 *  ========== Hilfsfunktionen ==========
 *
 *  void printList(vector<int>& numbers)
 *  -> Gibt die Liste aus
 *
 */


