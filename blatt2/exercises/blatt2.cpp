#include "../include/blatt2.h"

/**
 * Aufgabe 2
 */
int max_subarray(vector<int>& a) {
    if (a.size() == 0) return 0;
    int sum_res = a[0];
    int sum_temp = a[0];

    for(int i = 0; i < a.size(); i++){
        if (i != 0) {
            sum_temp += a[i];
        }
        if (a[i] > sum_temp) {
            sum_temp = a[i];
        }
        if (sum_temp > sum_res){
            sum_res = sum_temp;
        }
    }
    return sum_res;
}

/**
 * Aufgabe 3b)
 */
int nextSeat(/*TODO: select data structure*/) {
    // TODO: Extract next seat, given the room data structure
    return 0;
}

/**
 * Aufgabe 3c)
 */
vector<int> examRoomOrder(int n) {
    vector<int> order;
    // TODO
    return order;
}

/**
 *  ========== Hilfsfunktionen ==========
 *
 *  void printList(vector<int>& numbers)
 *  -> Gibt die Liste aus
 *
 */
