#include "../test/test.h"

char *mergeStrings(char *beginString1,
                   char *beginString2,
                   char *beginDestination) {
    Word word1, word2;
    bool isW1Found, isW2Found;
    bool isFromFirst = true;
    char *beginSearch1 = beginString1;
    char *beginSearch2 = beginString2;
    char *recordPtr = beginDestination;

    while ((isW1Found = getWord(beginSearch1, &word1)),
            (isW2Found = getWord(beginSearch2, &word2)),
            isW1Found || isW2Found) {
        switch (isW1Found + 2 * isW2Found + 3 * isFromFirst) {
            case 5: // isW2Found && isFromFirst
            case 3: // isW2Found && isW1Found
            case 2: // isW2Found
                COPY(recordPtr, word2);
                beginSearch2 = word2.end;
                break;
            case 6: // isW2Found && isW1Found && isFromFirst
            case 4: // isW1Found && isFromFirst
            case 1: // isW1Found
                COPY(recordPtr, word1);
                beginSearch1 = word1.end;
                break;
        }

        isFromFirst = !isFromFirst;
        *recordPtr = ' ';
        recordPtr++;
    }

    if (beginDestination != recordPtr)
        recordPtr--;

    *recordPtr = '\0';
    return recordPtr;
}

void test_mergeStrings_null() {
    mergeStrings("",
                 "",
                 getStringBuffer());
    ASSERT_STRING("", getStringBuffer());
}

void test_mergeStrings_oneWord() {
    mergeStrings("12",
                 "",
                 getStringBuffer());
    ASSERT_STRING("12", getStringBuffer());

    mergeStrings("",
                 "12",
                 getStringBuffer());
    ASSERT_STRING("12", getStringBuffer());
}

void test_mergeStrings_twoWord() {
    mergeStrings("12",
                 "34",
                 getStringBuffer());
    ASSERT_STRING("12 34", getStringBuffer());

    mergeStrings("34",
                 "12",
                 getStringBuffer());
    ASSERT_STRING("34 12", getStringBuffer());
}

void test_mergeStrings_manyWord() {
    mergeStrings("1   3 5  7   9",
                 "2   4   6 8 ",
                 getStringBuffer());
    ASSERT_STRING("1 2 3 4 5 6 7 8 9", getStringBuffer());
}

void test_mergeStrings_result() {
    char *result = mergeStrings("1   3 5  7   9",
                                "2   4   6 8 ",
                                getStringBuffer());
    assert(result == getStringBuffer() + 17);
}

void test_mergeStrings() {
    test_mergeStrings_null();
    test_mergeStrings_oneWord();
    test_mergeStrings_twoWord();
    test_mergeStrings_manyWord();
    test_mergeStrings_result();
}
