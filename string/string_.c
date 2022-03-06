#include "string_.h"

char stringBuffer[MAX_STRING_SIZE + 1];

BagOfWords bagOfWordsBuffer = {
        (Word [MAX_N_WORDS_IN_STRING]) {},
        0
};

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

int getWord(char *beginSearch, Word *word) {
    word->begin = findNonSpace(beginSearch);
    word->end = findSpace(word->begin);

    if (*word->begin == '\0')
        return 0;

    return 1;
}

int getWordReverse(char *rbegin, char *rend, Word *word) {
    char *endWord = findNonSpaceReverse(rbegin, rend);
    word->end = endWord + 1;
    word->begin = findSpaceReverse(endWord, rend) + 1;

    if (endWord == rend)
        return 0;

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

int getWordLen(Word word) {
    return (int) (word.end - word.begin);
}

int areWordsEqual(Word w1,
                  Word w2) {
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

void getBagOfWords(BagOfWords *bag, char *beginString) {
    char *beginSearch = beginString;
    Word word;
    Word *wordInBag = bag->words;
    bag->size = 0;

    while (getWord(beginSearch, &word)) {
        *(wordInBag++) = word;
        beginSearch = word.end;
        bag->size++;
    }
}

Word *getEndWord(BagOfWords *bag) {
    return bag->words + bag->size - 1;
}

BagOfWords *getBagOfWordsBuffer() {
    return &bagOfWordsBuffer;
}

void outputWord(Word word) {
    for (; word.begin < word.end; word.begin++)
        printf("%c", *word.begin);
}

bool isLetterInWord(char letter, Word word) {
    letter = getLowercase(letter);

    for (char *readPtr = word.begin;
         readPtr < word.end;
         readPtr++)
        if (letter ==
            getLowercase(*readPtr))
            return true;

    return false;
}

char getLowercase(char letter) {
    if (isupper(letter))
        letter += 'a' - 'A';
    return letter;
}

bool isWordInBag(Word word, BagOfWords *bag) {
    Word *end = getEndWord(bag) + 1;

    for (Word *current = bag->words;
         current < end;
         current++)
        if (0 == areWordsEqual(*current,
                               word))
            return true;


    return false;
}

char *wordToString(Word word,
                   char *destination) {
    char *result = copy(word.begin,
                        word.end,
                        destination);
    *result = '\0';
    return result;
}


void sortBagOfWords(BagOfWords *bag) {
    qsort(bag->words,
          bag->size,
          sizeof(Word),
          compareWords);
}

int compareWords(const void *a, const void *b) {
    Word arg1 = *(const Word *) a;
    Word arg2 = *(const Word *) b;

    int resultCmp = areWordsEqual(arg1, arg2);
    if (resultCmp < 0) return -1;
    if (resultCmp > 0) return 1;
    return 0;
}

char *bagToString(BagOfWords *bag, char *destination) {
    char *recordPtr = destination;

    for (Word *current = bag->words,
                 *end = getEndWord(bag) + 1;
         current < end;
         current++) {
        COPY(recordPtr, (*current));
        *recordPtr = ' ';
        recordPtr++;
    }

    if (recordPtr != destination)
        recordPtr--;

    *recordPtr = '\0';

    return recordPtr;
}

bool isWordInSortBag(Word word, BagOfWords *bag) {
    Word *end = getEndWord(bag);
    Word *begin = bag->words;

    while (begin <= end) {
        Word *middle = begin + (end - begin) / 2;

        int cmpRes = compareWords(&word, middle);

        switch (cmpRes) {
            case 1:
                begin = middle + 1;
                break;
            case 0:
                return true;
            case -1:
                end = middle - 1;
                break;
            default:
                exit(1);
        }
    }

    return false;
}
