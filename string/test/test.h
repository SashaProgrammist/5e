#ifndef PROJECT_TEST_H
#define PROJECT_TEST_H

#include <assert.h>
#include <stdio.h>

#include "../string_.h"

# define ASSERT_STRING(expected, got) assertString(expected, got, \
             __FILE__, __FUNCTION__, __LINE__ )

void test();

void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName,
                  int line);

int *getLincExitCode();

// tasks

void test_removeNonLetters();

void test_AdjacentEqualLetters();

void test_forWordInString();

void test_digitForSpaces();

void test_replace();

void test_isOrderedString();

void test_outputWordForReversOrdered();

void test_getCountPalindromes();

void test_mergeStrings();

void test_reverseWordOrder();

void testAll_getWordBeforeFirstWordWithA();

void test_lastWordString1ThatInString2();

void test_isUniqueWordInString();

void test_isWordIyStringMadeUpOfUniqueChar();

void test_getStringOfWordsOtherThanLast();

void test_getWordPrecedingFirstOccurrenceOfWInString1();

void test_removingPalindrome();

void test_padSmallerString();

#endif //PROJECT_TEST_H
