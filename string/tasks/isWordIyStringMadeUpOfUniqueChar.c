#include "../test/test.h"

bool isWordIyStringMadeUpOfUniqueChar(char *beginString){
    char *workBuffer = getStringBuffer();
    copy(beginString,
         getEndOfString(beginString) + 1,
         workBuffer);
    BagOfWords *bag = getBagOfWordsBuffer();
    getBagOfWords(bag, workBuffer);

    foreachBag(bag, replaceWithMultipleChar);

    return isUniqueWordInString(workBuffer);
}

void test_isWordIyStringMadeUpOfUniqueChar_null(){
    assert(isWordIyStringMadeUpOfUniqueChar(""));
}

void test_isWordIyStringMadeUpOfUniqueChar_oneWord(){
    assert(isWordIyStringMadeUpOfUniqueChar("12342123"));
}

void test_isWordIyStringMadeUpOfUniqueChar_twoWord(){
    assert(isWordIyStringMadeUpOfUniqueChar("12 32"));
}

void test_isWordIyStringMadeUpOfUniqueChar_manyUniqueWord(){
    assert(isWordIyStringMadeUpOfUniqueChar(" 12 13  1 4  15 16 74 94 "));
}

void test_isWordIyStringMadeUpOfUniqueChar_manyWord(){
    assert(!isWordIyStringMadeUpOfUniqueChar(
            " 12 44444444444444445555555555"
            " 13  132 4  15 16 74 94  1231321"));
}

void test_isWordIyStringMadeUpOfUniqueChar(){
    test_isWordIyStringMadeUpOfUniqueChar_null();
    test_isWordIyStringMadeUpOfUniqueChar_oneWord();
    test_isWordIyStringMadeUpOfUniqueChar_twoWord();
    test_isWordIyStringMadeUpOfUniqueChar_manyUniqueWord();
    test_isWordIyStringMadeUpOfUniqueChar_manyWord();
}
