#ifndef INC_5_STRING__H
#define INC_5_STRING__H

#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

#define MAX_STRING_SIZE 100
#define MAX_N_WORDS_IN_STRING 100
#define MAX_WORD_SIZE 20

typedef struct WordDescriptor {
    char *begin; // позиция начала слова
    char *end; //   позиция первого символа, после последнего символа слова
} WordDescriptor;
char *getStringBuffer();

typedef struct BagOfWords {
    WordDescriptor words[MAX_N_WORDS_IN_STRING];
    size_t size;
} BagOfWords;
BagOfWords *getBagOfWordsBuffer();

int areWordsEqual(WordDescriptor w1,
                  WordDescriptor w2);

void outputWord(WordDescriptor word);

size_t strlen(const char *begin);

// find

char *find(const char *begin, const char *end, int ch);

char *findNonSpace(char *begin);

char *findSpace(char *begin);

char *findNonSpaceReverse(char *rbegin, const char *rend);

char *findSpaceReverse(char *rbegin, const char *rend);

//cmp

int strcmp_(const char *lhs, const char *rhs);

// copy

char *copy(const char *beginSource, const char *endSource,
           char *beginDestination);

char *copyReverse(char *rbeginSource, const char *rendSource,
                  char *beginDestination);

char *copyIf(char *beginSource, const char *endSource,
             char *beginDestination, int (*f)(int));

char *copyIfExtended(char *beginSource, const char *endSource,
                     char *beginDestination, int (*f)(char *));

char *copyIfReverse(char *rbeginSource, const char *rendSource,
                    char *beginDestination, int (*f)(int));

char *copyIfReverseExtended(char *rbeginSource, const char *rendSource,
                            char *beginDestination, int (*f)(char *));

// get

char *getEndOfString(char *s);

int getWord(char *beginSearch, WordDescriptor *word);

int getWordReverse(char *rbegin, char *rend, WordDescriptor *word);

int getWordLen(WordDescriptor word);

void getBagOfWords(BagOfWords *bag, char *beginString);

WordDescriptor *getEndWord(BagOfWords *bag);

// transform

void reverseOrder(char *beginSource, char *endSource);

#endif //INC_5_STRING__H
