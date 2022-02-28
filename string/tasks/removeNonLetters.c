#include "../test/test.h"

void removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s,
                               endSource,
                               s,
                               isgraph);
    *destination = '\0';
}

void test_removeNonLetters_oneWord() {
    char s[] = " Hi123 ";
    removeNonLetters(s);
    ASSERT_STRING ("Hi123", s);
}

void test_removeNonLetters_manyWord() {
    char s[] = " Hi123 111 3 51     0      ";
    removeNonLetters(s);
    ASSERT_STRING ("Hi1231113510", s);
}

void test_removeNonLetters() {
    test_removeNonLetters_manyWord();
    test_removeNonLetters_oneWord();
}
