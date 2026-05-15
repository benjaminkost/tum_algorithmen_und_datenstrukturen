#include <iostream>

#include "include/blatt3.h"

void aufgabe1() {
    vector<int> digitsA = {1,0,1,1,1,0,0};
    vector<int> digitsB = {1,0,0,0};
    int base = 2;

    printf("Before adding:\n");
    printDigits(digitsA, base);
    printDigits(digitsB, base);

    vector<int> added = addNumbers(digitsA, digitsB, base);

    printf("After adding: ");
    printDigits(added, base);
}


int main() {
    aufgabe1();
}
