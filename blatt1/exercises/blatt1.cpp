#include "../include/blatt1.h"

/**
 * Aufgabe 1c, i)
 */
bool returnTrue() {
    return true;
}

/**
 * Aufgabe 1c, ii)
 */
int returnPositiveOdd() {
    return 3;
}

/**
 * Aufgabe 1c, iii)
 */
int returnPrime() {
    return 11;
}



/**
 * Aufgabe 2a)
 */
void reverse(vector<int>& numbers) {
    for(int i = 0; i < (numbers.size()+1)/2;i++) {
        char a = numbers[i];
        numbers[i] = numbers[numbers.size()-i-1];
        numbers[numbers.size()-i-1] = a;
    }
}

/**
 * Aufgabe 2b)
 */
vector<int> plusOne(vector<int>& digits) {
    if (digits[digits.size()-1] < 9) {
        digits[digits.size()-1] = digits[digits.size()-1] + 1;
        return digits;
    }

    int i = digits.size()-1;
    for(i; i >= 0 && digits[i] == 9;i--){
        digits[i] = 0;
    }

    if (digits[0] == 0){
        digits.insert(digits.begin(), 1);
    } else {
        digits[i] = digits[i]+1;
    }

    return digits;
}

/**
 * Aufgabe 2c)
 */
vector<int> findPeaks(vector<int>& mountain) {
    if (mountain.size() < 3) return {};

    std::vector<int> res = {};

    for (int i = 1; i < mountain.size()-1;i++) {
        if (mountain[i-1] < mountain[i] && mountain[i] > mountain[i+1]) {
            res.push_back(i);
            i++;
        }
    }

    return res;
}


/**
 *  ========== Hilfsfunktionen ==========
 *
 *  void printDigits(vector<int>& digits)
 *  -> Gibt die Ziffern des gegebenen vectors als Dezimalzahl aus
 *
 *  void printList(vector<int>& numbers)
 *  -> Gibt die Liste aus
 *
 */

