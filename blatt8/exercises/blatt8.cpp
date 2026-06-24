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
void add_rec(ListNode* &current, ListNode* other) {
    // Basisfall: Eins der beiden Polynome ist zu Ende
    if(other == nullptr)
        return;

    if(current == nullptr) {
        // Unser Polynom ist zu Ende
        current = new ListNode(other->i, other->ci);
        add_rec(current->next, other->next);
        // Wichtig: andere Liste muss KOPIERT werden:
        // "current = other;" wäre fatal, da es beide Listen zusammenführen würde!
        return;
    }

    // Rekursionsfall: Es gibt 3 Möglichkeiten, basierend darauf welcher Exponent der größte ist:
    if(current->i > other->i) {
        // Unser Exponent is höher -> wir gehen einen Schritt weiter
        add_rec(current->next, other);
    } else if (current->i < other->i) {
        // Der andere Exponent is höher -> wir kopieren das Element in unsere Liste
        ListNode* node = new ListNode(other->i, other->ci);
        node->next = current;
        current = node;
        add_rec(node->next, other->next);
    } else {
        // Jetzt gilt: current->i == other->i
        // -> Wir addieren die Koeffizienten
        current->ci += other->ci;
        if(current->ci == 0) {
            // Die Summe der Koeffizienten ist 0 -> Wir löschen den Knoten
            ListNode* tmp = current; // Pointer auf current, um diesen Knoten löschen zu können
            current = current->next;
            delete tmp;
            add_rec(current, other->next);
        } else {
            add_rec(current->next, other->next);
        }
    }
}

void Polynomial::add(Polynomial& other){
    add_rec(head, other.head);
}