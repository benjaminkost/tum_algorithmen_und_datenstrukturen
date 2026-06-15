#include "../include/blatt7.h"


/// Aufgabe 2
void deleteNode(Node* &node)
{
    Node *helper = node;
    node = node->next;

    delete helper;
}

void printLinkedList(Node *head)
{
    Node *pointer = head;
    printf("\n Current List: \n");
    while (pointer->next->data != head->data)
    {
        printf("%i \n", pointer->data);
        pointer = pointer->next;
    }
}

std::pair<vector<int>, int> josephus(int n, int k) {
    vector<int> order;
    CyclicLinkedList cl(n);
    Node* &pointer = cl.start;
    while (pointer->next != pointer)
    {
        for (int i = 1; i < k-1; i++)
        {
            pointer = pointer->next;
        }
        order.push_back(pointer->next->data);
        deleteNode(pointer->next);
        pointer = pointer->next;
    }
    return {order, pointer->data};
}

/// Aufgabe 3a)

float Polynomial::evaluate(float x) {
    float res = 0;
    for (ListNode *pointer = this->head; pointer != nullptr; pointer = pointer->next)
    {
        res += std::pow(x, pointer->i)*pointer->ci;
    }
    return res;
}

/// Aufgabe 3b)

bool Polynomial::equalTo(Polynomial& other){
    ListNode* current_node = this->head;
    for (ListNode *pointer = other.head; pointer != nullptr; pointer = pointer->next)
    {
        if (pointer->i != current_node->i || pointer->ci != current_node->ci)
        {
            return false;
        }
        current_node = current_node->next;
    }
    return true;
}

/**
 *  ========== Hilfsfunktionen ==========
 *
 *  void printList(vector<int>& numbers)
 *  -> Gibt die Liste aus
 *
 *
 *  - - - - - - - - - - - - - Für Aufgabe 2) Josephus - - - - - - - - - - - - - - - - - - - - -
 *  struct Node {                       Repräsentiert ein Element in einer CyclicLinkedList
 *      int data;
 *      Node* next;
 *  }
 *
 *  class CyclicLinkedList {
 *  public:
 *      Node* start;
 *      CyclicLinkedList(int count);    Initialisiert mit count Knoten, beginnend mit data = 1
 *      ~CyclicLinkedList()             Löscht alle verbleibenden Elemente
 *      void print();                   Gibt die Liste aus
 *  }
 *
 *  - - - - - - - - - - - - - Für Aufgabe 3) Polynome - - - - - - - - - - - - - - - - - - - - -
 *  struct ListNode {                   Repräsentiert ein Element in einem Polynom: ci * x^i
 *      int i;                          Exponent
 *      float ci;                       Koeffizient
 *      ListNode* next;
 *  }
 *
 *  class Polynomial {
 *  public:
 *      ListNode* head;
 *      void print();
 */
