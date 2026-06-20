#include "../include/blatt8.h"

/// Aufgabe 3
int max_subarray(vector<int>& a) {
    // TODO
    return 0;
}

/// Aufgabe 4a)
void Polynomial::flip() {
    ListNode* pointer = this->head;

    while (pointer != nullptr)
    {
        pointer->ci = pointer->ci*-1;
        pointer = pointer->next;
    }
}

/// Aufgabe 4b)
void Polynomial::moveUp(float c) {
    // Fall 1: Leeres Polynom → neuen Knoten mit x^0 erstellen
    if (this->head == nullptr) {
        if (c != 0) {
            this->head = new ListNode(0, c);
        }
        return;
    }

    // Fall 2: Head ist x^0 → Koeffizient anpassen
    // Sonderfall: head->i == 0 und es ist der einzige Knoten
    // Allgemein: wir müssen durch die Liste laufen

    ListNode* prev = nullptr;
    ListNode* pointer = this->head;

    while (pointer != nullptr)
    {
        if (pointer->i == 0)
        {
            float newCoeff = pointer->ci + c;
            if (newCoeff == 0) {
                // Knoten mit Koeffizient 0 entfernen
                if (prev == nullptr) {
                    // Es ist der head-Knoten
                    this->head = pointer->next;
                } else {
                    prev->next = pointer->next;
                }
                delete pointer;
            } else {
                pointer->ci = newCoeff;
            }
            return;
        }  else if (pointer->next == nullptr)
        {
            // Ende der Liste erreicht, kein x^0-Term vorhanden → neuen anhängen
            if (c != 0) {
                auto* newElement = new ListNode(0, c);
                pointer->next = newElement;
            }
            return;
        }
        prev = pointer;
        pointer = pointer->next;
    }
}

/// Aufgabe 4c)
void insert(int index, int i, float ci, ListNode* &ptr)
{
    if (index == 0)
    {
        ListNode* newElement = new ListNode(i,ci);
        newElement->next = ptr;

        ptr = newElement;
    } else
    {
        if (ptr == nullptr) return;

        insert(index - 1, i, ci, ptr->next);
    }
}

void deleteSingleElement(ListNode* &position)
{
    ListNode* helper = position;
    position = position->next;
    delete helper;
}

ListNode* handleBeginningOfList(ListNode* &actual, ListNode* &other)
{
    ListNode* firstAddedElement = actual;
    int firstExponent = actual->i;
    for (int i = 0; other != nullptr && other->i > firstExponent; i++)
    {
        insert(i, other->i, other->ci, actual);
        if (i == 0) firstAddedElement = actual;
        other = other->next;
    }

    return firstAddedElement;
}

void handleEqualExponent(ListNode* &position, int coeff)
{
    if (coeff == 0) deleteSingleElement(position);

    position->ci = position->ci;

}

void handleBiggerExponent(ListNode* &actual, ListNode* &other)
{
    auto* helper = other;
    while (other->i > actual->next->i)
    {
        other = other->next;
    }
    other = actual->next;
    actual->next = helper;
}

void Polynomial::add(Polynomial& other){
    auto* pointerCurrent = this->head;
    auto* pointerOther = other.head;

    this->head = handleBeginningOfList(pointerCurrent, pointerOther);

    while (pointerCurrent != nullptr && pointerOther != nullptr)
    {
        if (pointerOther->i == pointerCurrent->next->i)
        {
            int coeff = pointerOther->ci+pointerCurrent->next->ci;
            if (coeff == 0)
            {
                deleteSingleElement(pointerCurrent->next);
            } else
            {
                pointerCurrent->next->ci = coeff;
            }
        } else if (pointerOther->i > pointerCurrent->next->i)
        {
            handleBiggerExponent(pointerCurrent, pointerOther);
        } else if (pointerCurrent->next == nullptr)
        {
            pointerCurrent->next = pointerOther;
        } else if (pointerOther->next == nullptr)
        {
            break;
        }

        pointerCurrent = pointerCurrent->next;
        pointerOther = pointerOther->next;
    }
}