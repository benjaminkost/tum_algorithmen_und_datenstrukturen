//
// Created by robin on 12.05.25.
//

#ifndef DEMO_WEEK3_H
#define DEMO_WEEK3_H

#include <string>
#include <sstream>
#include <vector>

using std::vector;

bool isPalindrome(vector<int>& x);

bool fixPalindrome(vector<int>& x);

static void printList(vector<int>& x) {
    std::stringstream ss;
    std::string sep;
    for (int i: x) {
        ss << sep << i;
        sep = ", ";
    }
    printf("%s\n", ss.str().c_str());
}

static std::string listToStr(vector<int>& x) {
    std::stringstream ss;
    std::string sep;
    for (int elem: x) {
        ss << sep << elem;
        sep = ", ";
    }
    return ss.str();
}


#endif //DEMO_WEEK3_H
