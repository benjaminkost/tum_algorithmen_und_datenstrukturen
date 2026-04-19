#include <iostream>

/**
 * Ensures that start <= end. Swaps values if necessary.
 * Returns true if the range was already valid.
 */
bool ensureValidRange(float& a, float& b) {
    if(a <= b) {
        return true;
    }
    float tmp = a;
    a = b;
    b = tmp;
    return false;
}


int main() {
    float a = 9.5;
    float b = 3.2;

    std::cout << "Original range: [" << a << ", " << b << "]\n";

    bool valid = ensureValidRange(a, b);

    std::cout << "Was range valid? " << (valid ? "Yes" : "No") << "\n";
    std::cout << "Corrected range: [" << a << ", " << b << "]\n";

    return 0;
}
