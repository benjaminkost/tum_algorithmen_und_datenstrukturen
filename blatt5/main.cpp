#include <iostream>

#include "include/blatt5.h"

void aufgabe1b() {
    int n = 10;
    float approx = pi(n);
    printf("Pi is approximately: %f\n", approx);
}

void aufgabe3a() {
    int n = 3;
    int k = 1;
    long binom = binom_iter(n, k);
    printf("binom(%d, %d) = %ld\n", n, k, binom);
}

void aufgabe3b() {
    int n = 1;
    int k = 0;
    long binom = binom_rec(n, k);
    printf("binom(%d, %d) = %ld\n", n, k, binom);
}

void aufgabe4a_helper() {
    int x = 4;
    int y = 3;
    int akk = 1;
    int val = g_tailrec_help(x, y, akk);
    printf("g_iter(%d, %d) = %d\n", x, y, val);
}

void aufgabe4a() {
    int x = 4;
    int y = 2;
    int val = g_tailrec(x, y);
    printf("g_tailrec(%d, %d) = %d\n", x, y, val);
}

void aufgabe4b() {
    int x = 33;
    int y = 4;
    int val = g_iter(x, y);
    printf("g_iter(%d, %d) = %d\n", x, y, val);
}


int main() {
//    float res = aufgabe1a(3);
//    aufgabe1b();
//    aufgabe3a();
//    aufgabe3b();
//     aufgabe4a_helper();
//    aufgabe4a();
    aufgabe4b();
}
