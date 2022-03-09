#include "../test/test.h"
#include <stdint.h>

typedef struct Set {
    int64_t value[4];
} Set;

bool getFromSet(Set *set, char index) {
    int64_t *work = set->value + index / 64;
    index %= 64;

    return ((*work) >> index) & 1;
}

void setInSet(Set *set, char index, bool value) {
    int64_t *work = set->value + index / 64;
    index %= 64;

    *work = ((*work) & ~((int64_t) 1 << index)) |
            ((int64_t) value << index);
}

bool isWordInString(Word word, char *beginString) {
    if (word.begin == word.end) return true;
    if (*beginString == '\0') return false;

    Set charSet = {};
    int countUnique = 0;
    for (char *current = word.begin;
         current < word.end;
         current++)
        if (!getFromSet(&charSet, *current)) {
            countUnique++;
            setInSet(&charSet, *current, true);
        }

    if (*charSet.value & 1) return false;// '\0' no in string

    char *readPtr = beginString;
    while (*readPtr != '\0') {
        if (getFromSet(&charSet, *readPtr)) {
            countUnique--;
            if (countUnique == 0)
                return true;
            setInSet(&charSet, *readPtr, false);
        }

        readPtr++;
    }

    return countUnique == 0;
}

void test_isWordInString_null() {
    char wordString[] = "";
    Word word = {wordString, wordString};
    assert(isWordInString(word, ""));
}

void test_isWordInString_no() {
    char wordString[] = "241";
    Word word = {wordString, wordString + 3};
    assert(!isWordInString(word, "123"));
}

void test_isWordInString_yes() {
    char wordString[] = "2341";
    Word word = {wordString, wordString + 4};
    assert(isWordInString(word, "1234"));
}

void test_isWordInString() {
    test_isWordInString_null();
    test_isWordInString_no();
    test_isWordInString_yes();
}
