#include "../test/test.h"

bool isNotPalindrome(Word word){
    return !isPalindrome(word);
}

void removingPalindrome(char *beginString) {
    removingIf(beginString, isNotPalindrome);
}

void test_removingPalindrome_null() {
    char s[] = "";
    removingPalindrome(s);
    ASSERT_STRING("", s);
}

void test_removingPalindrome_noRemoving() {
    char s[] = "12 34 56 78 90";
    removingPalindrome(s);
    ASSERT_STRING("12 34 56 78 90", s);
}

void test_removingPalindrome_yesRemoving() {
    char s[] = "12 34 565 78 90";
    removingPalindrome(s);
    ASSERT_STRING("12 34  78 90", s);
}

void test_removingPalindrome() {
    test_removingPalindrome_null();
    test_removingPalindrome_noRemoving();
    test_removingPalindrome_yesRemoving();
}
