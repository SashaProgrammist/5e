#include "../test/test.h"

bool getWordPrecedingFirstOccurrenceOfWInString1(
        char *beginString1,
        char *beginString2,
        Word *word) {
    BagOfWords *bag = getBagOfWordsBuffer();
    getBagOfWords(bag, beginString2);
    sortBagOfWords(bag);

    char *rend = beginString1 - 1;

    while (getWord(beginString1, word)) {
        if (isWordInSortBag(*word, bag)) {
            getWordReverse(word->begin - 1, rend, word);
            return word->begin != word->end;
        }

        beginString1 = word->end;
    }

    return false;
}

void test_getWordPrecedingFirstOccurrenceOfWInString1_null() {
    Word word;
    assert(!getWordPrecedingFirstOccurrenceOfWInString1(
                   "", "", &word));

    char *result = getStringBuffer();
    wordToString(word, result);
    ASSERT_STRING("", result);
}

void test_getWordPrecedingFirstOccurrenceOfWInString1_find() {
    Word word;
    assert(getWordPrecedingFirstOccurrenceOfWInString1(
                   "456 123", "123", &word));

    char *result = getStringBuffer();
    wordToString(word, result);
    ASSERT_STRING("456", result);
}

void test_getWordPrecedingFirstOccurrenceOfWInString1_manyWordInString2() {
    Word word;
    assert(getWordPrecedingFirstOccurrenceOfWInString1(
                   "456 123",
                   "1 2 3 4 123 8 7 6 3", &word));

    char *result = getStringBuffer();
    wordToString(word, result);
    ASSERT_STRING("456", result);
}

void test_getWordPrecedingFirstOccurrenceOfWInString1_manyUniqueWord() {
    Word word;
    assert(!getWordPrecedingFirstOccurrenceOfWInString1(
                   "7 8 9 a b c",
                   "1 2 3 4 5 6",
                   &word));

    char *result = getStringBuffer();
    wordToString(word, result);
    ASSERT_STRING("", result);

    assert(getWordPrecedingFirstOccurrenceOfWInString1(
            "7 8 9 a b c",
            "1 a 3 4 5 6",
            &word));
    wordToString(word, result);
    ASSERT_STRING("9", result);
}

void test_getWordPrecedingFirstOccurrenceOfWInString1_manyWord() {
    Word word;
    assert(getWordPrecedingFirstOccurrenceOfWInString1(
                   "7 a 9 a b c",
                   "1 b 3 4 b a",
                   &word));

    char *result = getStringBuffer();
    wordToString(word, result);
    ASSERT_STRING("7", result);
}

void test_getWordPrecedingFirstOccurrenceOfWInString1() {
    test_getWordPrecedingFirstOccurrenceOfWInString1_null();
    test_getWordPrecedingFirstOccurrenceOfWInString1_find();
    test_getWordPrecedingFirstOccurrenceOfWInString1_manyWordInString2();
    test_getWordPrecedingFirstOccurrenceOfWInString1_manyUniqueWord();
    test_getWordPrecedingFirstOccurrenceOfWInString1_manyWord();
}
