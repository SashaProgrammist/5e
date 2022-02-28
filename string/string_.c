#include "string_.h"

size_t strlen(const char *begin) {
    const char *end = begin;

    while (*end != '\0')
        end++;

    return end - begin;
}

char *find(const char *begin, const char *end, const int ch) {
    while (begin != end && *begin != ch)
        begin++;

    return (char *) begin;
}

char *findNonSpace(char *begin) {
    while (*begin != '\0' && isspace(*begin))
        begin++;

    return begin;
}

char *findSpace(char *begin) {
    while (*begin != '\0' && !isspace(*begin))
        begin++;

    return begin;
}

char *findNonSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin != rend && isspace(*rbegin))
        rbegin--;

    return rbegin;
}

char *findSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin != rend && !isspace(*rbegin))
        rbegin--;

    return rbegin;
}

int strcmp_(const char *lhs, const char *rhs) {
    for (; *lhs != '\0' && *lhs == *rhs; lhs++, rhs++);

    return *lhs - *rhs;
}

char *copy(const char *beginSource, const char *endSource,
           char *beginDestination) {
    for (; beginSource != endSource; beginDestination++, beginSource++)
        *beginDestination = *beginSource;

    return beginDestination;
}

char *copyIfExtended(char *beginSource, const char *endSource,
                     char *beginDestination, int (*f)(char *)) {
    for (; beginSource != endSource; beginSource++)
        if (f(beginSource))
            *(beginDestination++) = *beginSource;

    return beginDestination;
}

char *copyIf(char *beginSource, const char *endSource,
             char *beginDestination, int (*f)(int)) {
    for (; beginSource != endSource; beginSource++)
        if (f(*beginSource))
            *(beginDestination++) = *beginSource;

    return beginDestination;
}

char *copyIfReverse(char *rbeginSource, const char *rendSource,
                    char *beginDestination, int (*f)(char *)) {
    for (; rbeginSource != rendSource; rbeginSource--)
        if (f(rbeginSource))
            *(beginDestination++) = *rbeginSource;

    return beginDestination;
}

char *getEndOfString(char *s) {
    return s + strlen(s);
}
