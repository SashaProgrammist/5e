#include "../test/test.h"

void forWordInString(char *beginString, void (*f)(WordDescriptor)) {
    char *beginSearch = beginString;
    WordDescriptor word;

    while (getWord(beginSearch, &word)) {
        f(word);
        beginSearch = word.end;
    }
}

void digitToStart(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end,
                                 getStringBuffer());
    char *recPosition = copyIfReverse(endStringBuffer - 1,
                                      getStringBuffer() - 1,
                                      word.begin, isdigit);
    copyIf(getStringBuffer(), endStringBuffer, recPosition, isalpha);
}

void forWordDigitToStartInString(char *beginString) {
    forWordInString(beginString, digitToStart);
}

void test_digitToStartTransform_oneWord() {
    char s[] = "Hi123";
    forWordDigitToStartInString(s);
    ASSERT_STRING ("321Hi", s);
}

void test_digitToStartTransform_manyWord() {
    char s[] = "GU56743JwfjM \n uA87889WZdf U64Gl97wiVWvo";
    forWordDigitToStartInString(s);
    ASSERT_STRING ("34765GUJwfjM \n 98878uAWZdf 7946UGlwiVWvo", s);
}

void wordReverse(WordDescriptor word) {
    reverseOrder(word.begin, word.end);
}

void reverseAllWordInString(char *beginString) {
    forWordInString(beginString, wordReverse);
}

void test_reverseAllWordInString_oneWord() {
    char s[] = "Hi123";
    reverseAllWordInString(s);
    ASSERT_STRING ("321iH", s);
}

void test_reverseAllWordInString_manyWord() {
    char s[] = "GU56743JwfjM \n uA87889WZdf U64Gl97wiVWvo";
    reverseAllWordInString(s);
    ASSERT_STRING ("MjfwJ34765UG \n fdZW98878Au ovWViw79lG46U", s);
}

void reversForWordInString(char *beginString, void (*f)(WordDescriptor)) {
    char *beginSearch = getEndOfString(beginString) - 1;
    char *endSearch = beginString - 1;
    WordDescriptor word;

    while (getWordReverse(beginSearch, endSearch, &word)) {
        f(word);
        beginSearch = word.begin - 1;
    }
}

void increase(WordDescriptor word){
    static char currentIncrease = 0;
    *word.begin += currentIncrease;
    currentIncrease++;
}

void test_reversForWordInString(){
    char s[] = "  0  0  0 0 0   0 \t0 0 \n 0 0 0 0   ";
    reversForWordInString(s, increase);
    ASSERT_STRING ("  ;  :  9 8 7   6 \t5 4 \n 3 2 1 0   ", s);
}

void test_forWordInString() {
    test_digitToStartTransform_oneWord();
    test_digitToStartTransform_manyWord();

    test_reverseAllWordInString_oneWord();
    test_reverseAllWordInString_manyWord();

    test_reversForWordInString();
}
