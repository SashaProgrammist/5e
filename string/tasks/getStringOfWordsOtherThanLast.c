#include "../test/test.h"

char *getStringOfWordsOtherThanLast(char *beginString, char *result) {
    size_t size = strlen(beginString);
    char *endString = beginString + size;
    copy(beginString,
         endString + 1,
         result);
    Word word1;
    getWordReverse(endString - 1,
                   beginString - 1,
                   &word1);
    Word word2 = {NULL, NULL};

    return replaceWord(result, word1, word2);
}

void test_getStringOfWordsOtherThanLast_null() {
    char get[] = "";
    getStringOfWordsOtherThanLast(get, get);
    ASSERT_STRING("", get);
}

void test_getStringOfWordsOtherThanLast_oneWord() {
    char get[] = "123 ";
    getStringOfWordsOtherThanLast(get, get);
    ASSERT_STRING(" ", get);
}

void test_getStringOfWordsOtherThanLast_twoWord() {
    char get[] = " 123  321";
    getStringOfWordsOtherThanLast(get, get);
    ASSERT_STRING(" 123  ", get);
}

void test_getStringOfWordsOtherThanLast_manyUniqueWord() {
    char get[] = "1 2 3 4 5 6 7 8 9";
    getStringOfWordsOtherThanLast(get, get);
    ASSERT_STRING("1 2 3 4 5 6 7 8 ", get);
}

void test_getStringOfWordsOtherThanLast_manyWord() {
    char get[] = "5 8 9 4 5 8 9 8 9";
    char *end = get + 17;

    end -= 3;
    assert(end ==
           getStringOfWordsOtherThanLast(get, get));
    ASSERT_STRING("5 8  4 5 8  8 ", get);

    end -= 3;
    assert(end ==
           getStringOfWordsOtherThanLast(get, get));
    ASSERT_STRING("5   4 5    ", get);

    end -= 2;
    assert(end ==
           getStringOfWordsOtherThanLast(get, get));
    ASSERT_STRING("   4     ", get);

    end -= 1;
    assert(end ==
           getStringOfWordsOtherThanLast(get, get));
    ASSERT_STRING("        ", get);

    assert(end ==
           getStringOfWordsOtherThanLast(get, get));
    ASSERT_STRING("        ", get);
}

void test_getStringOfWordsOtherThanLast() {
    test_getStringOfWordsOtherThanLast_null();
    test_getStringOfWordsOtherThanLast_oneWord();
    test_getStringOfWordsOtherThanLast_twoWord();
    test_getStringOfWordsOtherThanLast_manyUniqueWord();
    test_getStringOfWordsOtherThanLast_manyWord();
}
