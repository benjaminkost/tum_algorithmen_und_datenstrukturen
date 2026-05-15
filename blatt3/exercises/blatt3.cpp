#include "../include/blatt3.h"

vector<int> addNumbers(vector<int>& x, vector<int>& y, int base) {
    if (y.size() < x.size())
    {
        const vector<int> temp = x;
        x = y;
        y = temp;
    }

    int carry = 0;
    int tempSum = 0;
    int yCounter = y.size()-1;
    for (int i = x.size()-1; i >= 0 ; i--)
    {
        tempSum = x[i] + y[yCounter];
        y[yCounter] = (tempSum+carry) % base;
        carry = (tempSum+carry) / base;
        yCounter--;
    }

    if (carry != 0)
    {
        for (; yCounter >= 0 ; yCounter--)
        {
            tempSum = y[yCounter] + carry;
            y[yCounter] = tempSum % base;
            carry = tempSum / base;
        }
        if (yCounter < 0 && carry != 0)
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
 *  -> Gibt die Ziffern des gegebenen vectors aus
 *
 */