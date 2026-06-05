#include <iostream>

#include "include/blatt6.h"

struct ListNode
{
    int val;
    ListNode* next;
};

void aufgabe2() {
    int n = 4;
    int k = 2;
    long binom = binom_memo(n, k);
    printf("binom(%d, %d) = %ld\n", n, k, binom);
}

void aufgabe3() {
    vector<int> digits = {3, 6, 10, 25, 8, 1, 33, 2};

    printf("Before sort: ");
    printList(digits);

    selection_sort_iter(digits);

    printf("After sort: ");
    printList(digits);
}

void aufgabe4a() {
    vector<int> list = {23,25,36,1,4,8,12,15,18};

    printf("List: ");
    printList(list);

    int index = search(list, 3, 8);

    printf("Index of 8 is %d\n", index);
}

void aufgabe4b() {
    vector<int> list = {23,25,36,1,4,8,12,15,18};

    printf("List: ");
    printList(list);

    int shift = get_shift(list);

    printf("Shift is %d\n", shift);
}

void remove(ListNode* &ptr) {
    // ptr is a non-null pointer of the linked list;
    // the element ptr points to is removed
    ListNode* help = ptr;
    ptr = ptr->next;
    delete help;
}

void printLinkedList(ListNode* &ptr)
{
    while (ptr != nullptr)
    {
        printf("%d ", ptr->val);
        ptr = ptr->next;
    }
}

int main() {
//    aufgabe2();
     aufgabe3();
//    aufgabe4a();
//    aufgabe4b();

    /*auto head = new ListNode();
    head->val = 1;

    auto ptr = new ListNode;

    head->next = ptr;
    ptr->val = 2;

    auto ptr2 = new ListNode();
    ptr->next = ptr2;
    ptr2->val = 3;

    remove(ptr);

    printLinkedList(head);*/
}
