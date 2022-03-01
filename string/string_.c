#include "string_.h"

char stringBuffer[MAX_STRING_SIZE + 1];

//char *_stringBuffer = __stringBuffer;
char *getStringBuffer() {
    return stringBuffer;
}

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

char *copyReverse(char *rbeginSource, const char *rendSource, char *beginDestination) {
    for (; rbeginSource != rendSource; rbeginSource--)
        *(beginDestination++) = *rbeginSource;

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
                    char *beginDestination, int (*f)(int)) {
    for (; rbeginSource != rendSource; rbeginSource--)
        if (f(*rbeginSource))
            *(beginDestination++) = *rbeginSource;

    return beginDestination;
}

char *copyIfReverseExtended(char *rbeginSource, const char *rendSource,
                            char *beginDestination, int (*f)(char *)) {
    for (; rbeginSource != rendSource; rbeginSource--)
        if (f(rbeginSource))
            *(beginDestination++) = *rbeginSource;

    return beginDestination;
}

char *getEndOfString(char *s) {
    return s + strlen(s);
}

int getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    word->end = findSpace(word->begin);

    if (*word->begin == '\0')
        return 0;

    return 1;
}

int getWordReverse(char *rbegin, char *rend, WordDescriptor *word) {
    char *endWord = findNonSpaceReverse(rbegin, rend);
    word->end = endWord + 1;
    if (*endWord == '\0')
        return 0;

    word->begin = findSpaceReverse(endWord, rend) + 1;

    return 1;
}

void reverseOrder(char *beginSource, char *endSource) {
    char *endBuffer = copyReverse(endSource - 1,
                                  beginSource - 1,
                                  getStringBuffer());
    copy(getStringBuffer(),
         endBuffer,
         beginSource);
}

int getWordLen(WordDescriptor word) {
    return (int) (word.end - word.begin);
}

int areWordsEqual(WordDescriptor w1,
                  WordDescriptor w2) {
//    if (getWordLen(w1) != getWordLen(w2))
//        return 0;
//
//    for (; getWordLen(w1) != 0 &&
//           *w1.begin == *w2.begin;
//           w1.begin++, w2.begin++);
//
//    return getWordLen(w1) == 0;

    for (; getWordLen(w1) != 0 &&
           getWordLen(w2) != 0 &&
           *w1.begin == *w2.begin;
           w1.begin++, w2.begin++);

    switch ((getWordLen(w1) == 0) + 2 * (getWordLen(w2) == 0)) {
        case 0:
            return *w1.begin - *w2.begin;
        case 1:
            return -*w2.begin;
        case 2:
            return *w1.begin;
        default: // 3
            return 0;
    }
}
