
#include <array>
#include <vector>
#include <cstdio>
#include <limits>

using std::array, std::vector;

const int INT_MIN = std::numeric_limits<int>::min();

int findmax(int* p, int n) {
    int current_max = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (current_max < p[i]) {
            current_max = p[i];
        }
    }
    return current_max;
}

int findmax_std_array(array<int, 8> &a) {
    int current_max = INT_MIN;
    for (int i = 0; i < a.size(); i++) {
        if (current_max < a.at(i)) {
            current_max = a.at(i);
        }
    }
    return current_max;
}

int findmax_std_vector(vector<int> &a) {
    int current_max = INT_MIN;
    for (int i = 0; i < a.size(); i++) {
        if (current_max < a.at(i)) {
            current_max = a.at(i);
        }
    }
    return current_max;
}

int main() {
    int carr[] = {7, 8, 27, 39, 3, 10, 42, 1};
    int max_carr = findmax(carr, 8);
    printf("The max is %d\n", max_carr);

    array<int, 8> arr{7, 8, 27, 39, 3, 10, 42, 1};
    int max_arr = findmax_std_array(arr);
    printf("The max is %d\n", max_arr);


    vector<int> vec{7, 8, 27, 39, 3, 10, 42, 1};
    int max = findmax_std_vector(vec);
    printf("The max is %d\n", max);

    return 0;
}