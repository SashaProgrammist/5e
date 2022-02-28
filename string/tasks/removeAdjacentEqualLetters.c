#include "../test/test.h"

int isAdjacentEqualLetters(const char *ch) {
    return ch[0] != ch[1];
}

void removeAdjacentEqualLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIfExtended(s,
                                       endSource,
                                       s,
                                       (int (*)(char *)) isAdjacentEqualLetters);
    *destination = '\0';
}

void test_AdjacentEqualLetters_nullString() {
    char s[] = "";
    removeAdjacentEqualLetters(s);
    ASSERT_STRING ("", s);
}

void test_AdjacentEqualLetters_oneChar() {
    char s[] = "a";
    removeAdjacentEqualLetters(s);
    ASSERT_STRING ("a", s);
}

void test_AdjacentEqualLetters_manyUniqueChar() {
    char s[] = "abcdefg";
    removeAdjacentEqualLetters(s);
    ASSERT_STRING ("abcdefg", s);
}

void test_AdjacentEqualLetters_manyChar() {
    char s[] = "abccddaefcg";
    removeAdjacentEqualLetters(s);
    ASSERT_STRING ("abcdaefcg", s);
}

void test_AdjacentEqualLetters_manyNotUniqueChar() {
    char s[] = "aaaaaaaaaaaaaaaaaaaaaaa";
    removeAdjacentEqualLetters(s);
    ASSERT_STRING ("a", s);
}

void test_AdjacentEqualLetters() {
    test_AdjacentEqualLetters_nullString();
    test_AdjacentEqualLetters_oneChar();
    test_AdjacentEqualLetters_manyUniqueChar();
    test_AdjacentEqualLetters_manyChar();
    test_AdjacentEqualLetters_manyNotUniqueChar();
}
