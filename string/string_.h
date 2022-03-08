#ifndef INC_5_STRING__H
#define INC_5_STRING__H

#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_STRING_SIZE 100
#define MAX_N_WORDS_IN_STRING 100
#define MAX_WORD_SIZE 20
#define COPY(des, word) des = copy((word).begin, (word).end, des)

typedef struct Word {
    char *begin; // позиция начала слова
    char *end; //   позиция первого символа, после последнего символа слова
} Word;

char *getStringBuffer();

typedef struct BagOfWords {
    Word *words;
    size_t size;
} BagOfWords;

BagOfWords *getBagOfWordsBuffer();

void outputWord(Word word);

size_t strlen(const char *begin);


char *wordToString(Word word, char *destination);

char *bagToString(BagOfWords *bag, char *destination);

void sortBagOfWords(BagOfWords *bag);

// bool

bool isLetterInWord(char letter, Word word);

bool isWordInBag(Word word, BagOfWords *bag);

bool isWordInSortBag(Word word, BagOfWords *bag);

bool isUniqueWordInString(char *beginString);

bool isWordIyStringMadeUpOfUniqueChar();

bool isAdjacentEqualLetters(char *ch);

bool isPalindrome(Word word);

// find

char *find(const char *begin, const char *end, int ch);

char *findNonSpace(char *begin);

char *findSpace(char *begin);

char *findNonSpaceReverse(char *rbegin, const char *rend);

char *findSpaceReverse(char *rbegin, const char *rend);

//cmp

int strcmp_(const char *lhs, const char *rhs);

int areWordsEqual(Word w1, Word w2);

int compareWords(const void *a, const void *b);

int compareChar(const void *a, const void *b);

// copy

char *copy(const char *beginSource, const char *endSource,
           char *beginDestination);

char *copyReverse(char *rbeginSource, const char *rendSource,
                  char *beginDestination);

char *copyIf(char *beginSource, const char *endSource,
             char *beginDestination, int (*f)(int));

char *copyIfExtended(char *beginSource, const char *endSource,
                     char *beginDestination, bool (*f)(char *));

char *copyIfReverse(char *rbeginSource, const char *rendSource,
                    char *beginDestination, int (*f)(int));

char *copyIfReverseExtended(char *rbeginSource, const char *rendSource,
                            char *beginDestination, int (*f)(char *));

// get

char *getEndOfString(char *beginString);

int getWord(char *beginSearch, Word *word);

int getWordReverse(char *rbegin, char *rend, Word *word);

int getWordLen(Word word);

void getBagOfWords(BagOfWords *bag, char *beginString);

Word *getEndWord(BagOfWords *bag);

char getLowercase(char letter);

int getCountWord(char *beginSearch);

// transform

void reverseOrder(char *beginSource, char *endSource);

void foreachBag(BagOfWords *bag,
                void (*f)(Word *));

void sortWord(Word *word);

void replaceWithMultipleChar(Word *word);

char *replaceWord(char *source, Word word1, Word word2);

void deleteIf(BagOfWords *bag, bool (*f)(Word));

void removingIf(char *beginString, bool (*f)(Word));

#endif //INC_5_STRING__H
