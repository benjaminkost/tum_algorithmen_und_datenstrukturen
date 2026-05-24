#include "../include/blatt5.h"

/// Aufgabe 1b)
float pi(int n) {
    if (n == 0) return 4;
    if (n%2 == 0)
    {
        return 4.0f/(2*static_cast<float>(n)+1) + pi(n-1);
    }
    return -4.0f/(2*static_cast<float>(n)+1) + pi(n-1);
}

/// Aufgabe 3

long binom_iter(int n, int k) {
    // TODO
    return 0;
}

long binom_rec(int n, int k) {
    long res=0;

    if (n == 0) n=1;
    if (k == 0) k=1;
    for (int i = n;i>0;i--)
    {
        res += i/(k*(i-k));
        if (i == k)
        {
            res += i/k;
            break;
        }
        if (k != 0) --k;
    }
    return res;
}

/// Aufgabe 4

// Hilfsfunktion g endrekursiv
int g_tailrec_help(int x, int y /* TODO: weitere Parameter */) {
    // TODO
    return 0;
}

// Funktion g endrekursiv
int g_tailrec(int x, int y) {
    // TODO
    return 0;
}

// Funktion g iterativ
int g_iter(int x, int y) {
    // TODO
    return 0;
}
