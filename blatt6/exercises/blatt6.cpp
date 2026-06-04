#include "../include/blatt6.h"

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
void selection_sort(vector<int>& vec) {
    // TODO
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
