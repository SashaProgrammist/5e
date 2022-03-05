#include "../test/test.h"

typedef enum WordBeforeFirstWordWithAReturnCode {
    FIRST_WORD_WITH_A,
    NOT_FOUND_A_WORD_WITH_A,
    WORD_FOUND,
    EMPTY_STRING
} WordBeforeFirstWordWithAReturnCode;

WordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordWithA(
        char *beginString, Word *word) {
    char *readPtr = beginString;

    while (getWord(readPtr,
                   word) &&
           !isLetterInWord('a',
                           *word))
        readPtr = word->end;

    if (readPtr == beginString) {
        if (word->begin == word->end)
            return EMPTY_STRING;
        return FIRST_WORD_WITH_A;
    }

    if (*findNonSpace(readPtr) == '\0')
        return NOT_FOUND_A_WORD_WITH_A;

    getWordReverse(word->begin - 1,
                   beginString - 1,
                   word);

    return WORD_FOUND;
}

void outputWordBeforeFirstWordWithA(char *beginString) {
    Word word;
    getWordBeforeFirstWordWithA(beginString,
                                &word);
    outputWord(word);
}

void testAll_getWordBeforeFirstWordWithA() {
    Word word;

    char s1[] = "";
    assert (
            getWordBeforeFirstWordWithA(s1, &word)
            == EMPTY_STRING
    );

    char s2[] = " ABC";
    assert (
            getWordBeforeFirstWordWithA(s2, &word)
            == FIRST_WORD_WITH_A
    );

    char s3[] = "BC A";
    assert (
            getWordBeforeFirstWordWithA(s3, &word)
            == WORD_FOUND
    );
    char *got = getStringBuffer();
    copy(word.begin, word.end, got);
    got[word.end - word.begin] = '\0';
    ASSERT_STRING ("BC", got);

    char s4[] = "BC a";
    assert (
            getWordBeforeFirstWordWithA(s4, &word)
            == WORD_FOUND
    );
    copy(word.begin, word.end, got);
    got[word.end - word.begin] = '\0';
    ASSERT_STRING ("BC", got);

    char s5[] = "B Q WE YR OW IUWR ";
    assert (getWordBeforeFirstWordWithA(s5, &word)
            == NOT_FOUND_A_WORD_WITH_A);
}
