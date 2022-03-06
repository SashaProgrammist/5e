#include "../test/test.h"

bool isUniqueWordInString(char *beginString) {
    BagOfWords *bag = getBagOfWordsBuffer();
    getBagOfWords(bag, beginString);
    sortBagOfWords(bag);

    for (Word *current = bag->words,
            *end = getEndWord(bag);
         current < end;
         current++)
        if (0 == areWordsEqual(current[0],
                               current[1]))
            return false;

    return true;
}

void test_isUniqueWordInString_null(){
    assert(isUniqueWordInString(""));
}

void test_isUniqueWordInString_oneWord(){
    assert(isUniqueWordInString("aba"));
}

void test_isUniqueWordInString_twoWord(){
    assert(isUniqueWordInString("ro or"));
}

void test_isUniqueWordInString_manyUniqueWord(){
    assert(isUniqueWordInString(
            " 9 2 7  6  \n"
            "\t 8 3 4  5 1 "));
}

void test_isUniqueWordInString_manyWord(){
    assert(!isUniqueWordInString(
            " 9 2 1 7  6  \n"
            "\t 8 3 4  5 1 "));
}

void test_isUniqueWordInString(){
    test_isUniqueWordInString_null();
    test_isUniqueWordInString_oneWord();
    test_isUniqueWordInString_twoWord();
    test_isUniqueWordInString_manyUniqueWord();
    test_isUniqueWordInString_manyWord();
}
