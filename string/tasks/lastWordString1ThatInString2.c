#include "../test/test.h"

bool lastWordString1ThatInString2(char *beginString1,
                                  char *beginString2,
                                  Word *word) {
    BagOfWords *bag = getBagOfWordsBuffer();
    getBagOfWords(bag, beginString2);
    sortBagOfWords(bag);

    char *rbegin = getEndOfString(beginString1) - 1;
    char *rend = beginString1 - 1;

    while (getWordReverse(rbegin, rend, word)){
        if (isWordInSortBag(*word, bag))
            return true;

        rbegin = word->begin - 1;
    }

    return false;
}

void test_lastWordString1ThatInString2_null() {
    Word word;
    lastWordString1ThatInString2("",
                                 "",
                                 &word);
    char *result = getStringBuffer();
    wordToString(word, result);
    ASSERT_STRING("", result);
}

void test_lastWordString1ThatInString2_pair() {
    Word word;
    lastWordString1ThatInString2("123",
                                 "123",
                                 &word);
    char *result = getStringBuffer();
    wordToString(word, result);
    ASSERT_STRING("123", result);
}

void test_lastWordString1ThatInString2_manyWordInString2() {
    Word word;
    lastWordString1ThatInString2("3",
                                 "1 2 3 4 5 6",
                                 &word);
    char *result = getStringBuffer();
    wordToString(word, result);
    ASSERT_STRING("3", result);
}

void test_lastWordString1ThatInString2_manyUniqueWord() {
    Word word;
    char *result = getStringBuffer();

    lastWordString1ThatInString2("7 8 9 a b c",
                                 "1 2 3 4 5 6",
                                 &word);
    wordToString(word, result);
    ASSERT_STRING("", result);

    lastWordString1ThatInString2("7 8 9 a b c",
                                 "1 a 3 4 5 6",
                                 &word);
    wordToString(word, result);
    ASSERT_STRING("a", result);
}

void test_lastWordString1ThatInString2_manyWord() {
    Word word;
    char *result = getStringBuffer();

    lastWordString1ThatInString2("7 a 9 a b c",
                                 "1 b 3 4 b a",
                                 &word);
    wordToString(word, result);
    ASSERT_STRING("b", result);
}

void test_lastWordString1ThatInString2() {
    test_lastWordString1ThatInString2_null();
    test_lastWordString1ThatInString2_pair();
    test_lastWordString1ThatInString2_manyWordInString2();
    test_lastWordString1ThatInString2_manyUniqueWord();
    test_lastWordString1ThatInString2_manyWord();
}
