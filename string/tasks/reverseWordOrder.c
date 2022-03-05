#include "../test/test.h"

char *reverseWordOrder(char *beginString) {
    char *recordPtr = beginString;
    char *buffer = getStringBuffer();
    char *rend = buffer - 1;
    char *endRead = copy(beginString,
                         getEndOfString(beginString) + 1,
                         buffer) - 2;
    Word word;

    while (getWordReverse(endRead,
                          rend,
                          &word)) {
        COPY(recordPtr, word);
        *recordPtr = ' ';
        recordPtr++;

        endRead = word.begin - 1;
    }

    if (beginString != recordPtr)
        recordPtr--;

    *recordPtr = '\0';
    return recordPtr;
}

void test_reverseWordOrder_null() {
    char s[] = "";
    reverseWordOrder(s);
    ASSERT_STRING("", s);
}

void test_reverseWordOrder_oneWord() {
    char s[] = "12";
    reverseWordOrder(s);
    ASSERT_STRING("12", s);
}

void test_reverseWordOrder_twoWord() {
    char s[] = "12 34";
    reverseWordOrder(s);
    ASSERT_STRING("34 12", s);
}

void test_reverseWordOrder_threeWord() {
    char s[] = "12 34 56";
    reverseWordOrder(s);
    ASSERT_STRING("56 34 12", s);
}

void test_reverseWordOrder_manyWord() {
    char s[] = "12   \n34\t   56   78 , 90";
    reverseWordOrder(s);
    ASSERT_STRING("90 , 78 56 34 12", s);
}

void test_reverseWordOrder_result() {
    char s[] = "12   \n34\t   56   78 , 90";
    assert(s + 16 == reverseWordOrder(s));
}

void test_reverseWordOrder() {
    test_reverseWordOrder_null();
    test_reverseWordOrder_oneWord();
    test_reverseWordOrder_twoWord();
    test_reverseWordOrder_threeWord();
    test_reverseWordOrder_manyWord();
    test_reverseWordOrder_result();
}
