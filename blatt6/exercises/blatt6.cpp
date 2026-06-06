#include "../include/blatt6.h"
#include <limits>

/// Aufgabe 2

// Konstante, legt maximale Werte für n und k fest
const int N = 1000;

long long binom_memo(int n, int k) {
    static auto* lookup = new long long[N][N];

    if (lookup[n][k] > 0)
    {
        return lookup[n][k];
    }

    if ( k == 0 || n == k)
    {
        lookup[n][k] = 1;
        return lookup[n][k];
    }

    lookup[n][k] = binom_memo(n-1,k-1)+binom_memo(n-1,k);

    return lookup[n][k];
}

/// Aufgabe 3
void selection_sort_iter(vector<int>& vec) {
    int min_index = -1;
    int min_value = std::numeric_limits<int>::max();
    int i = 0;

    while (i < vec.size())
    {
        int j = i;
        while (j < vec.size())
        {
            if (min_value > vec[j])
            {
                min_value = vec[j];
                min_index = j;
            }
            j++;
        }
        vec[min_index] = vec[i];
        vec[i] = min_value;
        min_value = std::numeric_limits<int>::max();
        min_index = -1;
        i++;
    }
}

void selection_sort_helper(vector<int>& vec, int end_of_sorted_list, int iterator_index, int current_lowest_value_index)
{
    if (end_of_sorted_list == vec.size()-1)
    {
        return;
    }
    if (iterator_index == vec.size()-1) {
        if (vec[iterator_index] < vec[current_lowest_value_index]) current_lowest_value_index = iterator_index;
        int current_lowest_value = vec[current_lowest_value_index];

        vec[current_lowest_value_index] = vec[end_of_sorted_list+1];
        vec[end_of_sorted_list+1] = current_lowest_value;

        selection_sort_helper(vec, end_of_sorted_list+1, end_of_sorted_list+2, end_of_sorted_list+2);
    }
    else if (vec[iterator_index] <= vec[current_lowest_value_index])
    {
        current_lowest_value_index = iterator_index;
        selection_sort_helper(vec, end_of_sorted_list, iterator_index+1, current_lowest_value_index);
    } else
    {
        selection_sort_helper(vec, end_of_sorted_list, iterator_index+1, current_lowest_value_index);
    }
}

void selection_sort(vector<int>& vec) {
    selection_sort_helper(vec, -1, 0, 0);
}

/// Aufgabe 4a)
int binary_search_rec_helper(vector<int>& vec, int l, int r, int value)
{
    if (r < l) return -1;
    int mid = r+l/2;
    if (vec[mid] == value) return mid;

    if (value < vec[mid])
    {
        return binary_search_rec_helper(vec, l, mid-1, value);
    }

    return binary_search_rec_helper(vec, mid+1, r, value);
}

int binary_search(vector<int>& vec,int value)
{
    return binary_search_rec_helper(vec, 0, vec.size()-1,value);
}

int binary_search_with_shift_rec_helper(vector<int>& vec, int l, int r, int value, int shift)
{
    if (r < l) return -1;

    int mid = (l+r)/2;
    int mid_real = (mid+shift)%vec.size();
    if (vec[mid_real] == value) return mid_real;

    if (value < vec[mid_real])
    {
        return binary_search_with_shift_rec_helper(vec, l, mid-1, value, shift);
    }

    return binary_search_with_shift_rec_helper(vec, mid+1, r, value, shift);
}

int search(vector<int>& vec, int c, int x) {
   return binary_search_with_shift_rec_helper(vec, 0, vec.size()-1, x, c);
}

/// Aufgabe 4b)

int get_shift(vector<int>& vec, int l, int r)
{
    if (r <= l || vec[l] < vec[r]) return l;

    int mid = (l+r)/2;

    if (vec[l] > vec[mid])
    {
        return get_shift(vec, l, mid);
    }
    return get_shift(vec, mid+1, r);
}

int get_shift(vector<int>& vec) {
    if (vec[0] <= vec[vec.size()-1]) return 0;

    return get_shift(vec, 0, vec.size()-1);
}

/**
 *  ========== Hilfsfunktionen ==========
 *
 *  void printList(vector<int>& numbers)
 *  -> Gibt die Liste aus
 *
 */


