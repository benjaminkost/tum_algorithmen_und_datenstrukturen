#include "../include/palindrome.h"


void testIsPalindrome() {
    vector<int> x{1, 2, 3, 3, 1};
    printList(x);

    bool pal = isPalindrome(x);

    printf("This list is%s a palindrome!\n", pal ? "" : " NOT");
}

void testFixPalindrome() {
    vector<int> x{1, 2, 3, 3, 1};
    printList(x);

    bool pal = fixPalindrome(x);

    printf("This list was%s a palindrome before! It should be a palindrome now:\n", pal ? "" : " NOT");

    printList(x);
}


int main() {
    testIsPalindrome();
//    testFixPalindrome();
}