#ifndef INC_5_STRING__H
#define INC_5_STRING__H

#include <stdlib.h>
#include <ctype.h>

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

char *copyIf(char *beginSource, const char *endSource,
             char *beginDestination, int (*f)(int));

char *copyIfExtended(char *beginSource, const char *endSource,
                     char *beginDestination, int (*f)(char *));

char *copyIfReverse(char *rbeginSource, const char *rendSource,
                    char *beginDestination, int (*f)(char *));

// get

char *getEndOfString(char *s);

#endif //INC_5_STRING__H
