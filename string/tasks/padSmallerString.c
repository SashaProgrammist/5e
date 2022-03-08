#include "../test/test.h"

void padSmallerString(char *beginString1,
                      char *beginString2) {
    int countWord1 = getCountWord(beginString1);
    int countWord2 = getCountWord(beginString2);

    if (countWord1 == countWord2) return;

    char *stringCopy;
    char *beginInserts;
    int minCountWord;
    if (countWord1 < countWord2) {
        stringCopy = beginString2;
        beginInserts = getEndOfString(beginString1);
        minCountWord = countWord1;
    } else {
        stringCopy = beginString1;
        beginInserts = getEndOfString(beginString2);
        minCountWord = countWord2;
    }

    char *beginCopy, *endCopy;
    Word wordBeforeCopy = {stringCopy, stringCopy};
    while (minCountWord > 0) {
        getWord(wordBeforeCopy.end,
                &wordBeforeCopy);
        minCountWord--;
    }
    beginCopy = wordBeforeCopy.end;
    endCopy = getEndOfString(stringCopy) + 1;

    copy(beginCopy,
         endCopy,
         beginInserts);
}

void test_padSmallerString_null() {
    char s1[MAX_STRING_SIZE] = "";
    char s2[MAX_STRING_SIZE] = "";

    padSmallerString(s1, s2);

    ASSERT_STRING("", s1);
    ASSERT_STRING("", s2);
}

void test_padSmallerString_equals() {
    char s1[MAX_STRING_SIZE] = " 123";
    char s2[MAX_STRING_SIZE] = "132 ";

    padSmallerString(s1, s2);

    ASSERT_STRING(" 123", s1);
    ASSERT_STRING("132 ", s2);
}

void test_padSmallerString_yesInsertsIn1() {
    char s1[MAX_STRING_SIZE] = "123";
    char s2[MAX_STRING_SIZE] = " 4 \n5";

    padSmallerString(s1, s2);

    ASSERT_STRING("123 \n5", s1);
    ASSERT_STRING(" 4 \n5", s2);
}

void test_padSmallerString_yesInsertsIn2() {
    char s1[MAX_STRING_SIZE] = " 4 \n5";
    char s2[MAX_STRING_SIZE] = "123";

    padSmallerString(s1, s2);

    ASSERT_STRING(" 4 \n5", s1);
    ASSERT_STRING("123 \n5", s2);
}

void test_padSmallerString_yesInsertsManyWord() {
    char s1[MAX_STRING_SIZE] = "1 2 3 4 5";
    char s2[MAX_STRING_SIZE] = "1 2 3 4 5 6 7 8 9 10";

    padSmallerString(s1, s2);

    ASSERT_STRING("1 2 3 4 5 6 7 8 9 10", s1);
    ASSERT_STRING("1 2 3 4 5 6 7 8 9 10", s2);
}

void test_padSmallerString_yesInserts() {
    test_padSmallerString_yesInsertsIn1();
    test_padSmallerString_yesInsertsIn2();
    test_padSmallerString_yesInsertsManyWord();
}

void test_padSmallerString() {
    test_padSmallerString_null();
    test_padSmallerString_equals();
    test_padSmallerString_yesInserts();
}
