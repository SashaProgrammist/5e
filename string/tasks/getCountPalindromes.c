#include "../test/test.h"

bool isPalindrome(WordDescriptor word) {
    word.end--;

    while (word.begin < word.end) {
        if (*word.begin != *word.end)
            return false;

        word.begin++;
        word.end--;
    }

    return true;
}

size_t getCountPalindromes(char *beginString) {
    size_t result = 0;
    WordDescriptor word =
            {beginString, beginString};
    bool endOfCheck = *word.end == '\0';

    while (!endOfCheck) {
        endOfCheck = *word.end == '\0';
        bool metComma = *word.end == ',';

        if (metComma || endOfCheck)
            if (word.end != word.begin &&
                isPalindrome(word))
                result++;

        word.end++;

        if (metComma)
            word.begin = word.end;
    }

    return result;
}


void test_isPalindrome_null() {
    //          0123456
    char s[] = "1211333";

    for (int i = 0; i < 7; ++i)
        assert(true ==
               isPalindrome(
                       (WordDescriptor) {s + i, s + i}
               ));
}

void test_isPalindrome_oneChar() {
    char s[] = "1211333";

    for (int i = 0; i < 6; ++i)
        assert(true ==
               isPalindrome(
                       (WordDescriptor) {s + i, s + i + 1}
               ));
}

void test_isPalindrome_twyChar() {
    char s[] = "1211333";

    assert(true == (
            isPalindrome(
                    (WordDescriptor) {s + 2, s + 4}
            ) &&
            isPalindrome(
                    (WordDescriptor) {s + 4, s + 6}
            ) &&
            isPalindrome(
                    (WordDescriptor) {s + 5, s + 7}
            )
    ));

    assert(false == (
            isPalindrome(
                    (WordDescriptor) {s + 1, s + 3}
            ) ||
            isPalindrome(
                    (WordDescriptor) {s, s + 2}
            ) ||
            isPalindrome(
                    (WordDescriptor) {s + 3, s + 5}
            )
    ));
}

void test_isPalindrome_threeChar() {
    char s[] = "1211333";

    assert(true == (
            isPalindrome(
                    (WordDescriptor) {s, s + 3}
            ) &&
            isPalindrome(
                    (WordDescriptor) {s + 4, s + 7}
            )
    ));

    assert(false == (
            isPalindrome(
                    (WordDescriptor) {s + 1, s + 4}
            ) ||
            isPalindrome(
                    (WordDescriptor) {s + 2, s + 5}
            )
    ));
}

void test_isPalindrome() {
    test_isPalindrome_null();
    test_isPalindrome_oneChar();
    test_isPalindrome_twyChar();
    test_isPalindrome_threeChar();
}

void test_getCountPalindromes_null() {
    char s[] = "";
    assert(0 == getCountPalindromes(s));
}

void test_getCountPalindromes_oneChar() {
    char s[] = "a";
    assert(1 == getCountPalindromes(s));
}

void test_getCountPalindromes_oneComma() {
    char s[] = ",";
    assert(0 == getCountPalindromes(s));
}

void test_getCountPalindromes_Palindrome() {
    char s[] = "aroora";
    assert(1 == getCountPalindromes(s));
}

void test_getCountPalindromes_manyComma() {
    char s[] = ",,,aroo,,,,,,,,,,,,,,,,ara,,";
    assert(1 == getCountPalindromes(s));
}

void test_getCountPalindromes_bigString() {
    char s[] = ",,,aroo,,,ara,,dfd, fogof,ototo";
    assert(3 == getCountPalindromes(s));
}

void test_getCountPalindromes() {
    test_isPalindrome();

    test_getCountPalindromes_null();
    test_getCountPalindromes_oneChar();
    test_getCountPalindromes_oneComma();
    test_getCountPalindromes_Palindrome();
    test_getCountPalindromes_manyComma();
    test_getCountPalindromes_bigString();
}
