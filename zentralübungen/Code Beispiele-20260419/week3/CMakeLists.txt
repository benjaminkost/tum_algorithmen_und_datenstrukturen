add_executable(Palindrome main.cpp palindrome.cpp ${CMAKE_SOURCE_DIR}/include/palindrome.h)
target_include_directories(Palindrome PUBLIC ${CMAKE_SOURCE_DIR}/include)

enable_testing()

add_executable(PalindromeTest palindrome_test.cpp palindrome.cpp ${CMAKE_SOURCE_DIR}/include/palindrome.h)
target_include_directories(PalindromeTest PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(PalindromeTest GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(PalindromeTest)