#include "../include/palindrome.h"

bool isPalindromeIndices(vector<int>& x) {

    for (int i = 0; i < x.size()/2; i++){
        if (x[i] != x[x.size()-1-i]){
            return false;
        }
    }

    return true;
}


bool isPalindromePointers(vector<int>& x) {
    // TODO
    return false;
}


bool isPalindrome(vector<int>& x) {
    return isPalindromeIndices(x);
}

bool fixPalindromeIndices(vector<int>& x) {
    // TODO
    return false;
}

bool fixPalindromePointers(vector<int>& x) {
    // TODO
    return false;
}

bool fixPalindrome(vector<int>& x) {
    return fixPalindromeIndices(x);
}


/**
 *  ========== Hilfsfunktionen ==========
 *
 *  void printList(vector<int>& numbers)
 *  -> Gibt die Liste aus
 *
 */