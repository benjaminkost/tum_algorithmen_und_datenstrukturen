#include "../include/blatt4.h"

vector<int> plusOne(vector<int>& digits) {
    vector<int> sol(digits); // Kopie von digits anlegen
    auto sol_it = sol.rbegin();

    int carry = 0;

    int tempSum = *sol_it + 1;
    *sol_it = tempSum % 10;
    carry = tempSum / 10;
    ++sol_it;
    while (sol_it != sol.rend())
    {
        tempSum = *sol_it + carry;
        *sol_it = tempSum % 10;
        carry = tempSum / 10;
        if (carry == 0) return sol;
        ++sol_it;
    }

    if (carry != 0)
    {

        sol.insert(sol.begin(), carry);
    }
    return sol;
}


vector<int> addNumbers(vector<int>& x, vector<int>& y, int base) {
    if (y.size() < x.size())
    {
        swap(x, y);
    }

    int carry = 0;

    auto x_it = x.rbegin();
    auto y_it = y.rbegin();
    while (x_it != x.rend())
    {
        int tempSum = *x_it + *y_it;
        *y_it = (tempSum+carry) % base;
        carry = (tempSum+carry) / base;

        ++x_it;
        ++y_it;
    }

    if (carry != 0)
    {
        while (y_it != y.rend())
        {
            int tempSum = *y_it + carry;
            *y_it = tempSum % base;
            carry = tempSum / base;

            ++y_it;
        }
        if (y_it == y.rend() && carry != 0)
        {
            y.insert(y.begin(), carry);
        }
    }
    return y;
}

/**
 *  ========== Hilfsfunktionen ==========
 *
 *  void printDigits(vector<int>& digits, int base)
 *  -> Gibt die Ziffern des gegebenen vectors als Dezimalzahl aus
 *  -> Wirft eine Exception, falls ein digit invalid ist (negativ oder >= base)
 *
 *  void printList(vector<int>& numbers)
 *  -> Gibt die Liste aus
 *
 */