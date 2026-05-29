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

long factorial(int n) {
    if (n == 0) return 1;
    int res = 1;
    for (int i = 1; i<=n; i++)
    {
        res*=i;
    }
    return res;
}

long binom_iter(int n, int k) {
    long res = factorial(n)/(factorial(k)*factorial(n-k));

    return res;
}

long binom_iter_alternativ(int n, int k) {
    float res=1;
    long diff = n-k;
    while (n > 0)
    {
        if (k<=1 && diff<=1)
        {
            res*=1.0f*n;
        } else if (k<=1)
        {
            res*=1.0f*n/diff;
        } else if (diff<=1)
        {
            res*=1.0f*n/k;
        } else
        {
            res*=1.0f*n/(k*diff);
        }
        n--;
        k--;
        diff--;
    }
    return (long) res;
}

long binom_rec(int n, int k) {
    if ( k == 0 || n == k) return 1;
    return binom_rec(n-1,k-1)+binom_rec(n-1,k);
}

long binom_rec_alternativ(int n, int k)
{
    if (k == 0 || n == k) return 1;
    return binom_rec_alternativ(n+1,k+1)-binom_rec_alternativ(n,k+1);
}

/// Aufgabe 4

// Hilfsfunktion g endrekursiv
int g_tailrec_help(int x, int y, int akk) {
    if (x<10) return pow(x,y) + akk;
    int temp = pow(x%10,y);
    return g_tailrec_help(x/10,y+1,akk + temp);
}

// Funktion g endrekursiv
int g_tailrec(int x, int y) {
    return g_tailrec_help(x,y,0);
}

// Funktion g iterativ
int g_iter(int x, int y) {
    int akk = 0;
    for (int i = 0; x>=10; i++)
    {
        akk+=pow(x%10,y);
        y+=1;
        x=x/10;
    }
    akk += pow(x,y);
    return akk;
}