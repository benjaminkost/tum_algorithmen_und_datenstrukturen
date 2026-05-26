#include "../include/blatt5.h"

/// Aufgabe 1
/// Aufhabe 1a)
float aufgabe1a(int n)
{
    if (n == 1) return (4.0f-2)/2;

    float currentTerm = (4.0f*n-2)/(n+1);
    return aufgabe1a(--n) * currentTerm;
}

/// Aufgabe 1b)
float pi(int n) {
    if (n == 0) return 4;
    if (n%2 == 0)
    {
        return 4.0f/(2*static_cast<float>(n)+1) + pi(n-1);
    }
    return -4.0f/(2*static_cast<float>(n)+1) + pi(n-1);
}


/// Aufgabe 2

/// Hilfsfunktion
float betrag(float a, float b)
{
    return sqrt(a*a+b*b);
}
float heron(float a, float aktuellerWert)
{
    float neuerWert = 0.5f*(aktuellerWert+(a/aktuellerWert));
    if (betrag(aktuellerWert,neuerWert) < 0.0000001f) return neuerWert;
    return heron(a,neuerWert);
}

/// Aufgabe 3

long binom_iter(int n, int k) {
    long res=1;
    while (n > 0)
    {
        if (k<=1 && n-1<=1)
        {
            res*=n;
        } else if (k<=1)
        {
            res*=n/(n-1);
        } else if (n-1<=1)
        {
            res*=n/k;
        } else
        {
            res*=n/(k*(n-k));
        }
        n--;
        k--;
    }
    return res;
}

long binom_rec(int n, int k) {
    return 0;
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
