//
// Created by Robin on 25.03.24.
//

#include <gtest/gtest.h>
#include "../include/palindrome.h"

using VEC = vector<int>;

class isPalindromeTest : public testing::TestWithParam<VEC> {};

TEST_P(isPalindromeTest, CheckNumbers) {
    auto vec = GetParam();
    bool expected = std::equal(vec.begin(), vec.begin() + vec.size() / 2, vec.rbegin());
    bool output = isPalindrome(vec);
    ASSERT_EQ(output, expected) << "Input was: " << listToStr(vec);
}

INSTANTIATE_TEST_SUITE_P(
        EdgeCases,
        isPalindromeTest,
        testing::Values(VEC{}, VEC{1}, VEC{1, 2}, VEC{1, 1}, VEC{1, 2, 1}, VEC{1, 2, 3}, VEC{1, 2, 2, 1}, VEC{1, 0, 2, 1}, VEC{0, 1, 0, 1, 0}, VEC{0, 0, 0})
);

auto randomLists = testing::Values(VEC{2, 0, 3, 1, 4, 0}, VEC{0, 0, 2, 5}, VEC{4, 3, 3, 1}, VEC{1, 2, 3, 3, 1, 5, 5, 3}, VEC{3, 2, 2}, VEC{2, 5, 0, 5}, VEC{1, 3, 5, 1}, VEC{0, 2, 4}, VEC{5, 0, 1, 2, 0, 3, 5, 0}, VEC{4, 4, 5}, VEC{4, 5, 3, 5, 1, 1, 0}, VEC{4, 2, 2, 0, 2, 1, 5, 4}, VEC{0, 5, 3, 2, 1, 5, 3, 4}, VEC{2, 1, 0, 0, 4}, VEC{2, 0, 5, 1, 2, 1, 5, 3}, VEC{4, 5, 1, 0, 5, 5}, VEC{4, 1, 1, 0, 3, 3, 3, 3}, VEC{2, 3, 5, 4}, VEC{4, 0, 3, 3, 0, 4, 5, 4}, VEC{0, 2, 1, 5, 5, 4}, VEC{1, 2, 3, 5}, VEC{2, 4, 4}, VEC{2, 3, 4, 2}, VEC{2, 0, 0, 4, 1, 4, 0}, VEC{4, 3, 4, 0, 4}, VEC{1, 5, 5, 2, 5}, VEC{4, 3, 4, 0, 4, 3, 2, 0}, VEC{4, 0, 0, 1, 2}, VEC{5, 5, 4, 5}, VEC{4, 4, 0, 4, 0, 1}, VEC{3, 5, 0, 5}, VEC{3, 5, 5, 4, 0, 3, 5}, VEC{3, 0, 0, 0, 0}, VEC{5, 1, 5, 2, 1, 1, 4}, VEC{0, 3, 0, 0, 3, 4, 1, 4}, VEC{5, 1, 4, 4}, VEC{1, 1, 5, 0}, VEC{5, 0, 2}, VEC{1, 4, 3, 4, 2, 5, 5, 5}, VEC{5, 1, 3, 5}, VEC{4, 0, 0}, VEC{4, 4, 2}, VEC{5, 1, 1}, VEC{5, 0, 5, 4, 0}, VEC{0, 3, 0, 2, 5}, VEC{0, 4, 3, 4, 5, 0, 3, 4}, VEC{0, 2, 1}, VEC{5, 0, 4, 3, 4, 5, 5, 4}, VEC{4, 1, 3}, VEC{0, 2, 2, 2, 5}, VEC{0, 2, 1, 1, 4}, VEC{3, 4, 5, 1, 5, 0}, VEC{1, 3, 4}, VEC{1, 1, 2, 4}, VEC{2, 4, 3, 4, 4, 3}, VEC{5, 1, 2, 2, 3, 2, 2}, VEC{3, 0, 4, 2}, VEC{3, 2, 3, 2}, VEC{2, 4, 0, 0, 5, 2, 4, 1}, VEC{3, 2, 2, 0, 3, 1, 3, 3}, VEC{4, 4, 4}, VEC{1, 5, 1, 5, 2, 2, 5, 1}, VEC{2, 4, 2, 0, 5, 0, 0, 4}, VEC{4, 0, 5}, VEC{0, 4, 4, 0, 4, 0, 0}, VEC{1, 0, 0}, VEC{1, 0, 3, 1}, VEC{4, 1, 2, 0, 3, 4, 4, 4}, VEC{2, 5, 5, 2, 5, 2}, VEC{5, 5, 4}, VEC{2, 3, 3}, VEC{5, 1, 2, 0, 2}, VEC{5, 2, 5, 0}, VEC{5, 4, 4, 4, 2}, VEC{5, 5, 5}, VEC{2, 1, 5}, VEC{2, 4, 1, 0}, VEC{1, 3, 2}, VEC{0, 4, 3}, VEC{2, 1, 0, 0, 5, 0, 3, 3}, VEC{5, 5, 3, 1, 2}, VEC{4, 0, 4, 3, 5, 0, 0, 4}, VEC{4, 0, 0, 1, 1}, VEC{1, 3, 4, 2, 3, 1, 4}, VEC{2, 5, 4, 2, 2, 5, 4, 5}, VEC{1, 1, 0, 3, 0, 3, 4}, VEC{0, 2, 5, 4, 4}, VEC{3, 2, 0, 2}, VEC{1, 3, 4}, VEC{5, 1, 0, 1, 3, 2}, VEC{2, 3, 2}, VEC{0, 5, 3, 3, 2, 2}, VEC{3, 2, 4}, VEC{4, 4, 2, 0, 0}, VEC{4, 1, 2, 0}, VEC{3, 4, 3, 4, 4, 0, 2, 0}, VEC{5, 3, 4, 3, 2}, VEC{3, 4, 2, 1}, VEC{0, 2, 5}, VEC{4, 4, 4}, VEC{0, 2, 1, 1, 1, 2}, VEC{2, 0, 2, 1, 1, 1, 1}, VEC{2, 0, 0}, VEC{2, 2, 0, 1, 0, 2}, VEC{1, 0, 2, 1, 0, 2, 2, 2}, VEC{2, 2, 2}, VEC{0, 2, 1, 0}, VEC{0, 0, 1, 2}, VEC{0, 2, 0, 1, 2, 1}, VEC{1, 1, 1, 0}, VEC{1, 2, 1, 0, 1, 1, 0}, VEC{1, 1, 1, 2, 1, 1, 2, 1}, VEC{1, 1, 2, 0, 2}, VEC{0, 1, 0, 0, 2}, VEC{0, 0, 1, 0, 2, 2}, VEC{1, 1, 1, 2, 0, 0, 1, 1}, VEC{0, 0, 2, 1, 0}, VEC{1, 0, 2, 1, 2}, VEC{1, 0, 1, 0}, VEC{0, 2, 0, 0, 1, 1, 0}, VEC{0, 2, 1, 1, 2, 1, 0, 0}, VEC{0, 2, 1, 0, 1, 2, 1, 2}, VEC{0, 0, 0, 1, 0, 0, 0, 0}, VEC{2, 1, 0}, VEC{0, 2, 1}, VEC{2, 0, 1, 1, 1}, VEC{1, 0, 1, 0}, VEC{1, 0, 2, 1, 2, 1, 2}, VEC{0, 0, 1, 0, 0, 2, 0}, VEC{0, 1, 0, 1, 1, 0}, VEC{2, 1, 0}, VEC{0, 1, 2}, VEC{1, 2, 2}, VEC{2, 2, 2, 0, 1}, VEC{0, 0, 0}, VEC{2, 0, 1, 0}, VEC{1, 2, 2}, VEC{2, 2, 1, 2, 0, 0, 0, 2}, VEC{1, 0, 1, 1, 2, 2, 1}, VEC{2, 2, 0, 1, 0}, VEC{0, 2, 1, 2, 1, 0, 2, 0}, VEC{0, 1, 1, 1, 0, 1, 0}, VEC{0, 0, 2, 0, 0, 1, 2}, VEC{2, 0, 2, 1, 1}, VEC{0, 0, 1, 2}, VEC{2, 2, 0, 2, 1}, VEC{0, 0, 1, 0, 1}, VEC{1, 0, 2, 0}, VEC{1, 2, 2, 2, 2}, VEC{2, 1, 2, 1}, VEC{2, 2, 0, 2, 1, 2}, VEC{0, 1, 0, 2, 2}, VEC{0, 2, 0, 0, 2}, VEC{2, 0, 1, 2, 2}, VEC{2, 2, 1, 0, 2, 1, 0}, VEC{1, 2, 2}, VEC{2, 2, 2, 2, 0, 0}, VEC{0, 2, 0, 2, 0}, VEC{0, 1, 0}, VEC{1, 2, 2, 2, 1}, VEC{2, 0, 0, 0, 0, 2}, VEC{1, 2, 1, 2, 1, 1}, VEC{0, 1, 0, 0, 1}, VEC{0, 1, 0, 1, 2, 2, 0}, VEC{0, 0, 1, 2, 2}, VEC{2, 1, 0, 1, 1}, VEC{2, 2, 0, 1}, VEC{0, 2, 0, 1, 0, 1, 1, 1}, VEC{1, 0, 0, 1, 0, 0, 2}, VEC{1, 2, 1, 0}, VEC{1, 1, 0, 0}, VEC{1, 1, 2, 0, 2, 2, 0}, VEC{1, 1, 2, 1, 0, 2, 2}, VEC{1, 0, 1}, VEC{0, 0, 2, 2, 1}, VEC{2, 0, 0, 0, 2, 1}, VEC{0, 1, 1, 0, 2, 2, 0}, VEC{1, 0, 1, 1}, VEC{1, 2, 2, 0, 0, 2}, VEC{0, 0, 1, 2, 1, 1}, VEC{1, 0, 2, 1, 0, 1}, VEC{1, 2, 1, 1, 0, 0}, VEC{2, 2, 1, 1, 2, 2}, VEC{0, 1, 1, 2, 0, 2, 1, 1}, VEC{2, 1, 2, 2, 2, 2}, VEC{0, 1, 2, 2}, VEC{1, 2, 1}, VEC{0, 1, 2, 2, 2}, VEC{2, 2, 0, 0, 0}, VEC{1, 1, 2, 1}, VEC{0, 2, 1, 2, 2, 1, 2, 0}, VEC{0, 1, 0}, VEC{0, 2, 1, 0, 2, 1}, VEC{2, 1, 2, 1}, VEC{1, 1, 1, 0, 1, 1, 1}, VEC{0, 2, 0}, VEC{1, 0, 1, 2}, VEC{1, 1, 1, 2, 2, 2}, VEC{1, 1, 0, 1, 2}, VEC{0, 2, 2, 2});

INSTANTIATE_TEST_SUITE_P(
        RandomNumbers,
        isPalindromeTest,
        randomLists
);


class fixPalindromeTest : public testing::TestWithParam<VEC> {};

TEST_P(fixPalindromeTest, CheckNumbers) {
    auto vec = GetParam();
    vector<int> copy = vec;
    bool expected = std::equal(vec.begin(), vec.begin() + vec.size() / 2, vec.rbegin());
    bool output = fixPalindrome(vec);
    ASSERT_EQ(output, expected) << "Input was: " << listToStr(vec);
    bool fixedPalindrome = std::equal(vec.begin(), vec.begin() + vec.size() / 2, vec.rbegin());
    ASSERT_TRUE(fixedPalindrome) << "The return value was correct, but the list is not a palindrome after. Input was: " << listToStr(copy) << ". Your output is: " << listToStr(vec);
    bool usedLeftHalf = std::equal(vec.begin(), vec.begin() + vec.size() / 2, copy.begin());
    ASSERT_TRUE(usedLeftHalf) << "The return value was correct, and the list is a palindrome. But the first half of the input list should be used for the palindrome. Input was: " << listToStr(copy) << ". Your output is: " << listToStr(vec);

}

INSTANTIATE_TEST_SUITE_P(
        EdgeCases,
        fixPalindromeTest,
        testing::Values(VEC{}, VEC{1}, VEC{1, 2}, VEC{1, 1}, VEC{1, 2, 1}, VEC{1, 2, 3}, VEC{1, 2, 2, 1}, VEC{1, 0, 2, 1}, VEC{0, 1, 0, 1, 0}, VEC{0, 0, 0})
);

INSTANTIATE_TEST_SUITE_P(
        RandomNumbers,
        fixPalindromeTest,
        randomLists
);