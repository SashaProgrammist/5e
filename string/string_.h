#ifndef INC_5_STRING__H
#define INC_5_STRING__H

#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_STRING_SIZE 100
#define MAX_N_WORDS_IN_STRING 100
#define MAX_WORD_SIZE 20
#define COPY(des, word) des = copy(word.begin, word.end, des)

typedef struct Word {
    char *begin; // позиция начала слова
    char *end; //   позиция первого символа, после последнего символа слова
} Word;
char *getStringBuffer();

typedef struct BagOfWords {
    Word words[MAX_N_WORDS_IN_STRING];
    size_t size;
} BagOfWords;
BagOfWords *getBagOfWordsBuffer();

int areWordsEqual(Word w1,
                  Word w2);

void outputWord(Word word);

size_t strlen(const char *begin);

bool isLetterInWord(char letter, Word word);

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

int getWord(char *beginSearch, Word *word);

int getWordReverse(char *rbegin, char *rend, Word *word);

int getWordLen(Word word);

void getBagOfWords(BagOfWords *bag, char *beginString);

Word *getEndWord(BagOfWords *bag);

char getLowercase(char letter);

// transform

void reverseOrder(char *beginSource, char *endSource);

#endif //INC_5_STRING__H
