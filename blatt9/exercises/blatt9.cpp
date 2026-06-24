#include "../include/blatt9.h"


/// Aufgabe 2
void Queue::enqueue(int x) {
    stack1.push(x);
}

int Queue::dequeue() {
    int firstInQueue;
    if (stack2.empty())
    {
        while (!stack1.empty())
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
        firstInQueue = stack2.top();
        stack2.pop();
    } else
    {
        firstInQueue = stack2.top();
        stack2.pop();
    }

    return firstInQueue;
}

bool Queue::isEmpty() {
    return stack1.empty() && stack2.empty();
}

/// Aufgabe 3
void fillStack(stack<int>& st, stack<int> top)
{
    while (!top.empty())
    {
        st.push(top.top());
        top.pop();
    }
}

void sortInsert_rec(stack<int>& st, stack<int> top, int val)
{
    if (st.empty())
    {
        st.push(val);
        fillStack(st, top);
        return;
    }

    if (st.top() >= val)
    {
        st.push(val);
        fillStack(st, top);
        return;
    }

    top.push(st.top());
    st.pop();
    return sortInsert_rec(st,top, val);
}

void sortedInsert(stack<int>& st, int val) {
    stack<int> top;

    sortInsert_rec(st, top, val);
}

void stackSort(stack<int>& st) {
    stack<int> res;
    while (!st.empty())
    {
        sortedInsert(res, st.top());
        st.pop();
    }
    st = res;
}



/**
 *  ========== Hilfsfunktionen ==========
 *
 *  void printStack(stack<int>& st)
 *  -> Gibt die Elemente des Stack aus
 *
 *  void printQueue(Queue& q)
 *  -> Gibt die Elemente der Queue aus
 *
 */