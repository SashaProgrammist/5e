#include "../test/test.h"

int isOrderedString(char *beginString) {
    Word previousWord, currentWord;

    getWord(beginString, &previousWord);
    beginString = previousWord.end;

    while (getWord(beginString,
                   &currentWord)) {
        if (areWordsEqual(previousWord, currentWord) <= 0) {
            previousWord = currentWord;
            beginString = currentWord.end;
        } else
            return 0;
    }

    return 1;
}

void test_isOrderedString_null() {
    *getStringBuffer() = '\0';
    assert(isOrderedString(getStringBuffer()));
}

void test_isOrderedString_one() {
    char s[] = "111";
    assert(isOrderedString(s));
}

void test_isOrderedString_two() {
    char s[] = "111 112";
    assert(isOrderedString(s));
}

void test_isOrderedString_three() {
    char s[] = "111 112 113";
    assert(isOrderedString(s));
}

void test_isOrderedString_noOrder() {
    char s[] = "111 113 112";
    assert(!isOrderedString(s));
}

void test_isOrderedString() {
    test_isOrderedString_null();
    test_isOrderedString_one();
    test_isOrderedString_two();
    test_isOrderedString_three();
    test_isOrderedString_noOrder();
}
